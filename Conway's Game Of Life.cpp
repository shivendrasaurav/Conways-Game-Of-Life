#include<stdio.h>
#include<stdlib.h>
#include<windows.h>
int n;
int next(int brd[100][100]);

int main(){
	int c,i,j,k,l,flag=1,row,col;
	int brd[100][100]={0},nbrd[n][n];
	printf("Enter grid size in n : ");
	scanf("%d",&n);
	
	while(flag!=0){
		printf("\n\nEnter Row : ");
		scanf("%d",&row);
		printf("\nEnter Column : ");
		scanf("%d",&col);
		brd[row][col]=1;
		printf("\nEnter 1 to give next co-ordinate, 0 to Start : ");
		scanf("%d",&flag);
	}
	system("cls");
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
				if(brd[i][j]==1)
					printf("%c",178);
				else
					printf("%c",176);
		}
		printf("\n");
	}
	
	next(brd);
	
	return 0;
}

int next(int brd[100][100]){
	int i,j,c,k,l,nbrd[100][100]={0};
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				c=0;
				for (int k = -1; k <= 1; k++) 
                    for (int l = -1; l <= 1; l++) 
                        c += brd[i + k][j + l];
				
				c -= brd[i][j];
				
				if(brd[i][j]==1 && c<2)
					nbrd[i][j]=0;
				else if(brd[i][j]==1 && c>3)
					nbrd[i][j]=0;
				else if(brd[i][j]==0 && c==3)
					nbrd[i][j]=1;
				else
					nbrd[i][j]=brd[i][j];
			}
		}
		Sleep(100);
		system("cls");
		for(i=0;i<n;i++){
			for(j=0;j<n;j++){
				if(nbrd[i][j]==1)
					printf("%c",178);
				else
					printf("%c",176);
			}
			printf("\n");
		}
		next(nbrd);
}

