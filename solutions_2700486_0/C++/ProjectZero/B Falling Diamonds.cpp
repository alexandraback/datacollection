#include <cstdio>
#include <algorithm>
using namespace std;

const int MAXLEVEL = 10000;
int T,N,X,Y;

int dp[MAXLEVEL];
int level; // 1 + (2+2+1) + (3+3+1)
/*
 a_n = n*(n+2)-2
*/ 
int count1,count2,left,right;
double ans,nall;

double nCr(int n,int r){
	double ans = 1.0;
	int i,j;
	for(i=r+1,j=1;i<=n && j<=n-r ;i++,j++) ans *= (double)i/(double)j;
	return ans/nall;
}
int main(){
	freopen("B-small-attempt4.in","r",stdin);
	freopen("B-small-output4.out","w",stdout);
	
	for(int i=1;i<MAXLEVEL;i++){
		dp[i] = i*(i+2)-2;
	//	printf("i = %d %d\n",i,dp[i]);
	}	
	scanf("%d",&T);
	for(int _i=1;_i<=T;_i++){
		printf("Case #%d: ",_i);
		
		scanf("%d %d %d",&N,&X,&Y);
		if(X == 0 && Y == 0){
			printf("1.0\n");
			continue;
		}
		int *p = lower_bound(&dp[1],&dp[MAXLEVEL],N);
		level = p-dp;
		
		//printf("levelN = %d  now = %d\n",level,(abs(X)+Y)/2+1);
		if(dp[level] == N){
			printf("1.0\n");
			continue;
		}
			
		if(  ((abs(X)+Y)/2)+1 > level) printf("0.0\n");
		else if(  ((abs(X)+Y)/2)+1 < level) printf("1.0\n");
		else{
			N -= dp[level-1];
			if(Y/2+1 == level){
				if(N == level+level+1) printf("1.0\n");
				else printf("0.0\n");
			}else if(Y/2+1 > N) printf("0.0\n");
			else{
				if(N <= level){
					left = right = false;
									
					if(X < 0) left = true;
					else      right = true;
							
					ans = 0.0;
					nall = 1.0;
					for(int i=1;i<=N;i++) nall *= 2.0;
					for(int i=0;i<=N;i++){
						int nleft = i;
						int nright = N-i;
											
						if(left && nleft > Y) ans = (ans + nCr(N,nleft));
						else if(right && nright > Y) ans = (ans + nCr(N,nright));
					}
					printf("%.6lf\n",ans);
				}else{
					left = right = false;
					if(X < 0) left = true;
					else      right = true;
											
					ans = 0.0;
					nall = 0.0; 
					double tmp = 1.0;
					for(int i=0;i<=level;i++){
						int nleft = i;
						int nright = N-nleft;
						if(nright > level) continue;
						
						tmp = 1.0;
						for(int j=nleft+1,k=1;j<=N && k<=nright;j++,k++) tmp *= (double)(j)/(double)(k);
						nall += tmp;
					}
					//printf("nall = %lf\n",nall);
					for(int i=0;i<=level;i++){
						int nleft = i;
						int nright = N-nleft;
						if(nright > level) continue;
						
						if(left && nleft > Y) ans = (ans + nCr(N,nleft));
						else if(right && nright > Y) ans = (ans + nCr(N,nright));
					}
					printf("%.6lf\n",ans);
				}
			}
		}
	}
	return 0;
}

/*
0 0 1
[2] 0 2
1 1
2 0
[3] 
0 4
1 3
2 2
3 1
4 0

*/