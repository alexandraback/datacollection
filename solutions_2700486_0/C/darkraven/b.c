#include<stdio.h>
#include <math.h>
#define abs(x) ((x)>0?(x):(-(x)))
double g[200][200];
void calc(int n){
	g[0][0]=1;
	g[1][0]=1;
	g[1][1]=1;
	int i;
	for(i=1;i<n;i++){
		int j;
		g[i][0]=1;
		for(j=1;j<i;j++)
			g[i][j]=g[i-1][j]+g[i-1][j-1];
		g[i][i]=1;
	}
}
double pcalc(int k, int y){
	double ans=0;
	int i;
	for(i=y;i<=k;i++){
		ans+=g[k][i];
	}
	return ans*exp(log(0.5)*k);
}
int main(){
	int cases;
	scanf("%d", &cases);
	int cc;
	calc(60);
	for(cc=1; cc<=cases; cc++){
		int x,y,n;
		scanf("%d%d%d", &n, &x, &y);
		/* first we find how many diamond should be piled first */
		int t = (y+abs(x))/2;
		int m = (2*t-1)*t;
		int m2 = m+4*t+1;
		if(n>=m2){
			printf("Case #%d: 1.0\n",cc);
		}else{
			if(n<=m){
				printf("Case #%d: 0.0\n", cc);
			}else{
				if(x == 0){
					printf("Case #%d: 0.0\n",cc);
				}else{
					int k=n-m;
					int top=2*t;
					if(k>=top+y+1){
						printf("Case #%d: 1.0\n",cc);
					}else{
						printf("Case #%d: %.06lf\n", cc, pcalc(k, y+1));
					}
				}
			}
		}
	}
	return 0;
}

