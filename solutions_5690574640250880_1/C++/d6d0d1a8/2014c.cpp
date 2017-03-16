#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>

int main(){
	int t;
	scanf("%d",&t);
	for(int tt=0;tt<t;){
		tt++;

		int r,c,m;
		scanf("%d%d%d",&r,&c,&m);
		bool canit;
		char map[50][50];

		for(int i=0;i<r;i++)for(int j=0;j<c;j++)map[i][j]='.';
		int count=0;
		if(r==1||c==1){
			if(c*r>m){
				canit=true;
				for(int i=0;i<r;i++)for(int j=0;j<c;j++){
					if(count>=m)break;
					map[i][j]='*';
					count++;
				}
				map[r-1][c-1]='c';
			}else{
				canit=false;
			}
		}
		else if(r==2||c==2){
			if((m%2==1&&r*c>m+1)||r*c==m+2)canit=false;
			else if(r*c==m+1){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++){
					map[i][j]='*';
				}
				map[r-1][c-1]='c';
				canit=true;
			}
			else{
				if(r==2)for(int i=0;i<2;i++)for(int j=0;j<m/2;j++)map[i][j]='*';
				else for(int i=0;i<m/2;i++)for(int j=0;j<c;j++)map[i][j]='*';
				map[r-1][c-1]='c';
				canit=true;
			}
		}
		else{
			if((c-2)*(r-2)>=m){
				canit=true;
				for(int i=0;i<r-2;i++)for(int j=0;j<c-2;j++){
					if(count>=m)break;					
					map[i][j]='*';
					count++;
				}
				map[r-1][c-1]='c';
			}else if(c*r==m+1){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++){
					map[i][j]='*';
				}
				map[r-1][c-1]='c';
				canit=true;
			}else if(c*r>=m+9){
				for(int i=0;i<r-2;i++)for(int j=0;j<c-2;j++)map[i][j]='*';
				count=(r-2)*(c-2);
				int k=m-count;
				if(k%2){
					map[r-3][c-3]='.';
					count--;
				}
				for(int i=0;i<r-3;i++)for(int j=c-2;j<c;j++){
					if(count>=m)break;
					map[i][j]='*';
					count++;
				}
				for(int j=0;j<c-3;j++)for(int i=r-2;i<r;i++){
					if(count>=m)break;
					map[i][j]='*';
					count++;
				}
				map[r-1][c-1]='c';
				canit=true;
			}else if(r*c==m+9){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++)map[i][j]='*';
				map[0][1]=map[0][2]=map[1][0]=map[1][1]=map[1][2]=map[2][1]=map[2][2]=map[2][0]='.';
				map[0][0]='c';
				canit=true;
				
			}else if(r*c==m+8){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++)map[i][j]='*';
				map[0][1]=map[0][2]=map[1][0]=map[1][1]=map[1][2]=map[2][1]=map[2][0]='.';
				map[0][0]='c';
				canit=true;
			}else if(r*c==m+6){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++)map[i][j]='*';
				map[0][1]=map[0][2]=map[1][0]=map[1][1]=map[1][2]='.';
				map[0][0]='c';
				canit=true;
			}else if(r*c==m+4){
				for(int i=0;i<r;i++)for(int j=0;j<c;j++)map[i][j]='*';
				map[0][1]=map[1][0]=map[1][1]='.';
				map[0][0]='c';
				canit=true;
			}
			else{
				canit=false;
			}
		}

		printf("Case #%d:\n",tt);
		if(canit){
			for(int i=0;i<r;i++){
				for(int j=0;j<c;j++){
					printf("%c",map[i][j]);
				}
				printf("\n");
			}
		}
		else printf("Impossible\n");
	}
	return 0;
}