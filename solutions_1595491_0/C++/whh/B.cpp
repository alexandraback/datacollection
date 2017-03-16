#include <cstdio>
#include <algorithm>
using namespace std;

int T , N, S, P, a[105];
int dp[105][105];

int max(int a,int b,int c){return max(a,max(b,c));}
int min(int a,int b,int c){return min(a,min(b,c));}

int main(){
	scanf("%d", &T);
	for (int tc=1;tc<=T;++tc){
		scanf("%d%d%d", &N, &S, &P);
		for (int i=1;i<=N;++i) scanf("%d", &a[i]);
		
		dp[0][0] = 0;
		
		for (int i=1;i<=N;++i){
			for (int j=0;j<=S && j<=i;++j){
				
				dp[i][j] = 0;
				
				for (int x=0;x<=10;++x){
					for (int y=0;y<=10;++y){
						for (int z=0;z<=10;++z){
							if (x+y+z!=a[i]) continue;
							if (max(x,y,z) - min(x,y,z) > 2) continue;
							
							if (max(x,y,z) - min(x,y,z) == 2){
								if (j==0) continue;
								if (max(x,y,z) >= P){
									dp[i][j] = max(dp[i][j] , dp[i-1][j-1] + 1);
								}else{
									dp[i][j] = max(dp[i][j] , dp[i-1][j-1]);
								}
							}else{
								if (max(x,y,z) >= P){
									dp[i][j] = max(dp[i][j] , dp[i-1][j] + 1);
								}else{
									dp[i][j] = max(dp[i][j] , dp[i-1][j]);
								}
							}
						}
					}
				}
				
			//	printf("%d %d : %d\n", i,j, dp[i][j]);
			}
		}
		
		printf("Case #%d: %d\n", tc, dp[N][S]);
	}
	return 0;
}