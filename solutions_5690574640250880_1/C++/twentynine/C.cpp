#include <iostream>
#include <cstdio>
using namespace std;
void f(char c[100][100],int x,int y){
	for(int i=1;i<=x;i++){
		for(int j=1;j<=y;j++){
			printf("%c",c[i][j]);
		}
		printf("\n");
	}
}
	

int main(){
//freopen("C-large.in", "r", stdin);
//freopen("C-large.out", "w", stdout);
	int tc,ii;
	scanf("%d",&tc);
	for(ii=1;ii<=tc;ii++){
		printf("Case #%d:\n",ii);
		int x,y,m,i,j;
		char c[100][100];
		scanf("%d %d %d",&x,&y,&m);
		for(i=1;i<=x;i++)for(j=1;j<=y;j++)c[i][j]='*';
		if(m==0){
			for(i=1;i<=x;i++){
			 	for(j=1;j<=y;j++){
		    		if(i==1&&j==1)printf("c");
		    		else printf(".");
				}
				printf("\n");
			}
		}
		else if(m==x*y-1)c[1][1]='c',f(c,x,y);
		
		else if(x==1){
			for(i=m+1;i<=y;i++)c[1][i]='.';
			c[1][y]='c';
			f(c,x,y);
		}
		
		else if(y==1){
			for(i=m+1;i<=x;i++)c[i][1]='.';
			c[x][1]='c';
			f(c,x,y);
		}
		
		else if(x==2){
			if(m==x*y-1)c[1][1]='c',f(c,x,y);
			else if(m%2==1||x*y-m==2)printf("Impossible\n");
			else {
				for(i=1;i<=y-m/2;i++)c[1][i]='.',c[2][i]='.';
				c[1][1]='c';
				f(c,x,y);
			}
		}
		
		else if(y==2){
			if(m==x*y-1)c[1][1]='c',f(c,x,y);
			else if(m%2==1||x*y-m==2)printf("Impossible\n");
			else {
				for(i=1;i<=x-m/2;i++)c[i][1]='.',c[i][2]='.';
				c[1][1]='c';
				f(c,x,y);
			}
		}	
		
		else if (x==3){ m=x*y-m; //no mine 
			if(m%3==0){
				if(m==3)printf("Impossible\n");
				else {for(i=1;i<=m/3;i++)c[1][i]=c[2][i]=c[3][i]='.';
				      c[1][1]='c';
				      f(c,x,y);
					}
			}
			else if(m%3==1){
				if(m==7)printf("Impossible\n");
				else {
					for(i=1;i<=(m-1)/3+1;i++)c[1][i]=c[2][i]=c[3][i]='.';
					c[3][(m-1)/3]=c[3][(m-1)/3+1]='*';
					c[1][1]='c';
			     	f(c,x,y);
				}
			}
			else if (m%3==2){
				if(m==2||m==5)printf("Impossible\n");
				else {
					for(i=1;i<=m/3+1;i++)c[1][i]=c[2][i]=c[3][i]='.';
					c[3][(m-2)/3+1]='*';
					c[1][1]='c';
			     	f(c,x,y);
				}
			}
		}
				
		else if (y==3){ m=x*y-m; //no mine 
			if(m%3==0){
				if(m==3)printf("Impossible\n");
				else {  for(i=1;i<=m/3;i++)c[i][1]=c[i][2]=c[i][3]='.';
			        	c[1][1]='c';
			        	f(c,x,y);
					}
			}
			else if(m%3==1){
				if(m==7)printf("Impossible\n");
				else {
					for(i=1;i<=(m-1)/3+1;i++)c[i][1]=c[i][2]=c[i][3]='.';
					c[(m-1)/3][3]=c[(m-1)/3+1][3]='*';
					c[1][1]='c';
			     	f(c,x,y);
				}
			}
			else if (m%3==2){
				if(m==2||m==5)printf("Impossible\n");
				else {
					for(i=1;i<=m/3+1;i++)c[i][1]=c[i][2]=c[i][3]='.';
					c[(m-2)/3+1][3]='*';
					c[1][1]='c';
			     	f(c,x,y);
				}
			}
		}	
			
	else { m=x*y-m;
		if(m==2||m==3||m==5||m==7)printf("Impossible\n");
		else{
			if(m==4)c[1][1]=c[1][2]=c[2][1]=c[2][2]='.';
			else if(m==6)c[1][1]=c[1][2]=c[2][1]=c[2][2]=c[1][3]=c[2][3]='.';
			else if(m>=8&&m<=2*y+2){
				c[1][1]=c[1][2]=c[2][1]=c[2][2]=c[1][3]=c[2][3]=c[3][1]=c[3][2]='.';
				m=m-8;
				if(m%2==1)m--,c[3][3]='.';
				for(i=4;i<=3+m/2;i++)c[1][i]=c[2][i]='.';
			}
			else {
				int M=m;
				for(i=1;i<=x;i++)for(j=1;j<=y;j++){if(m>0)c[i][j]='.';m--;}
				if(M%y==1){
					c[M/y][y]='*';
					c[M/y+1][2]='.';
				}
			}
					
			c[1][1]='c';
			f(c,x,y);
		}
				
	}
}
	return 0;
}		
				
				
			
		
