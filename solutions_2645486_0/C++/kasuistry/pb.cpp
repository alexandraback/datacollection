
#include <cstdio>

int min(int a, int b){return (a < b) ? a : b; }

int main(){
	
	int s[10][6];
	int g[10];
	int t; scanf("%d", &t);
	int e, r, n;

	for(int testcase=1; testcase<=t; ++testcase){
		scanf("%d%d%d", &e, &r, &n);
		for(int i=0; i<n; ++i){
			scanf("%d", &g[i]);
		}
		for(int i=0; i<n; ++i){
			for(int j=0; j<=e; ++j){
				s[i][j] = -1;
			}
		}
		for(int i=0; i<n; ++i){
			if(i == 0){
				for(int j=0; j<=e; ++j){
					s[i][min(e, e-j+r)] = j*g[i];
				}
			}else{
				for(int j=0; j<=e; ++j){
					for(int k=0; k<=j; ++k){
						int sum = s[i-1][j] + k*g[i];
						int idx = min(e, j-k+r);
						if(s[i][idx] == -1 || s[i][idx] < sum){
							s[i][idx] = sum;
						}
					}
				}
			}
		}
		int ans = s[n-1][0];
		for(int i=0; i<=e; ++i){
			if(s[n-1][i] > ans){
				ans = s[n-1][i];
			}
		}
		printf("Case #%d: %d\n", testcase, ans);
	}
	return 0;
}
