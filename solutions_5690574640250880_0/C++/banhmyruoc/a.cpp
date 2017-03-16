#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef pair<int,int> ii;
ii mem[2600][51][51];
char s[60][60];
int i,j,TC;

bool can( int sum, int a,int b){
	//printf("calculating can, sum = %d, a = %d, b =%d\n",sum,a,b);
	if (sum < 0) return 0;
	if (mem[sum][a][b] != ii(-1,-1)) return ( mem[sum][a][b] != ii(-2,-2) );
	if (sum==0) { mem[sum][a][b] = ii(0,0); return 1; }
	if (b==2) { mem[sum][a][b] = ii(-2,-2); return 0; }
	
	for (int i = a-1;i>=1;i--)
		for (int j = b-2;j>=1;j--){
			if (can(sum-i*j, i,b-j)){
				mem[sum][a][b] = ii(i,j);
				//printf("oh yeah can get can(%d,%d,%d), re = %d %d\n",sum,a,b,i,j);
				return true;
			}
			
		}
	//printf("Cannot get can(%d %d %d)\n", sum,a,b);
	mem[sum][a][b] = ii(-2,-2);
	return false;
}

void doit(int R,int C,int S){
	for (int Y = 2;Y<=R;Y++)
		for (int X = 2;X<=C;X++){
			if (X*Y < S) continue;
			if (X >(S+1)/2 || Y > (S+1)/2 ) continue;
			//printf("considering X = %d, Y =%d\n",X,Y);
			
			if (can( X*Y - S, X-1,Y)){
				//print it out;
				int i,j;
				for (i=0;i<Y;i++)
					for (j=0;j<X;j++)
						s[i][j] = '.';
				
				int at = X-1;
				int bt = Y;
				int sum = X*Y-S;
				while (mem[sum][at][bt] != ii(0,0)){
					ii dou = mem[sum][at][bt];
					at = dou.first;
					bt = dou.second;
					for (int k = X-1;k>=X-at;k--)
						for (int t = Y-1;t>=Y-bt;t--)
							s[t][k] = '*';
					sum -= at*bt;
					bt = Y - bt;
					Y = bt;
				}
				s[0][0] = 'c';
				
				for (i=0;i<R;i++)
					printf("%s\n",s[i]);
					
				return;
				
				
			}
		
		
		}
	printf("Impossible\n");
	
	
}
int main(){
	//freopen("in.txt","r",stdin); freopen("out.txt","w",stdout);
	
	
	int k;
	for (i=0;i<=2500;i++)
		for (j=0;j<=50;j++)
			for (k=0;k<=50;k++)
				mem[i][j][k] = ii(-1,-1);
				
	int TC,cno;
	scanf("%d",&TC);
	for (cno = 1;cno<=TC;cno++){
	printf("Case #%d:\n",cno);
	int R,C,M;
	scanf("%d %d %d",&R,&C,&M);
	
	int Safe = R*C-M;
	
	for (i=0;i<R;i++){
		for (j=0;j<C;j++) s[i][j] = '*';
		s[i][C] = '\0';
	}
	
	if (R>=2 && C>=2 && Safe >=4)
		doit(R,C,R*C-M);
	else{
		if (Safe == 1){
			s[0][0] = 'c';
			for (i=0;i<R;i++)
				printf("%s\n",s[i]);
		}
		else if ( R==1 ){
			for (i=0;i<Safe;i++) s[0][i] = '.';
			s[0][0] ='c';
			for (i=0;i<R;i++)
				printf("%s\n",s[i]);
			
		}else if (C==1){
			for (i=0;i<Safe;i++) s[i][0] = '.';
			s[0][0] = 'c';
			for (i=0;i<R;i++)
				printf("%s\n",s[i]);
		}
		else printf("Impossible\n");
		
	}
	
	}
}
