#include <stdio.h>
#include <string.h>
int r,c,m;
char print[52][52];
int main(){
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int test,testt,i,left,j;
	scanf("%d",&testt);
	for(test=1;test<=testt;test++){
		scanf("%d %d %d",&r,&c,&m);
		printf("Case #%d:\n",test);
		if(r==1){
			for(i=0;i<m;i++)
				printf("*");
			for(;i<c-1;i++)
				printf(".");
			printf("c\n");
			continue;
		}
		if(c==1){
			for(i=0;i<m;i++)
				printf("*\n");
			for(;i<r-1;i++)
				printf(".\n");
			printf("c\n");
			continue;
		}
		left=r*c-m;
		if(left==1){
			memset(print,0,sizeof(print));
			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					print[i][j]='*';
			}
			print[r-1][c-1]='c';
			for(i=0;i<r;i++)
				printf("%s\n",print[i]);
			continue;
		}
		if(r==2 && left%2==1){
			printf("Impossible\n");
			continue;
		}
		if(c==2 && left%2==1){
			printf("Impossible\n");
			continue;
		}
		if(left<4 || left==5 || left==7){
			printf("Impossible\n");
			continue;
		}
		else{
			memset(print,0,sizeof(print));
			for(i=0;i<r;i++){
				for(j=0;j<c;j++)
					print[i][j]='*';
			}
			print[r-1][c-1]='c';
			print[r-1][c-2]='.';
			print[r-2][c-2]='.';
			print[r-2][c-1]='.';
			left-=4;
			if(left>0 && r>2){
				print[r-3][c-1]='.';
				print[r-3][c-2]='.';
				left-=2;
			}
			if(left>0 && c>2){
				print[r-1][c-3]='.';
				print[r-2][c-3]='.';
				left-=2;
			}
			for(i=r-4;i>=0;i--){
				if(left>=2){
					left-=2;
					print[i][c-1]='.';
					print[i][c-2]='.';
				}
			}
			for(i=c-4;i>=0;i--){
				if(left>=2){
					left-=2;
					print[r-1][i]='.';
					print[r-2][i]='.';
				}
			}
			for(i=r-3;i>=0;i--){
				for(j=c-3;j>=0;j--){
					if(left!=0 && print[i][j]=='*'){
						left--;
						print[i][j]='.';
					}
				}
			}
			for(i=0;i<r;i++)
				printf("%s\n",print[i]);
		}
	}
	return 0;
}
