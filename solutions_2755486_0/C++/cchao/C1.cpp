#include <cstdio>
#include <set>
#include <cstring>
using namespace std;

set<int> t;
int wall[5000] = {0};
int d[10], n[10], w[10], e[10], s[10], dd[10], dp[10], ds[10];

int main(){
	int T;
	scanf("%d", &T);
	for(int kase = 1; kase <= T; ++kase){
		memset(wall, 0, sizeof wall);
		int N;
		scanf("%d", &N);
		for(int i = 0; i < N; ++i){
			scanf("%d%d%d%d%d%d%d%d", &d[i], &n[i], &w[i], &e[i], &s[i], &dd[i], &dp[i], &ds[i]);
			w[i] *= 2, e[i] *= 2, dp[i]*= 2;
			w[i] += 2500, e[i] += 2500;
			for(int j = 0; j < n[i]; ++j)
				t.insert(d[i] + j*dd[i]);
		}
		int ans = 0;
		for(set<int>::iterator it = t.begin(); it != t.end(); ++it){
			int x = *it;
//			printf("day %d\n", x);
			for(int i = 0; i < N; ++i){
				if(x >= d[i] && (x-d[i])%dd[i]==0 && (x-d[i])/dd[i]<n[i]){
//					printf("tribe %d tried %d ~ %d\n", i, w[i]-2500, e[i]-2500);
					for(int j = w[i]; j <= e[i]; ++j)
						if(s[i] > wall[j]){
//							printf("tribe %d succeed attack %d ~ %d\n", i, w[i]-2500, e[i]-2500);
							ans++;
							break;
						}
				}
			}
			for(int i = 0; i < N; ++i){
				if(x >= d[i] && (x-d[i])%dd[i]==0 && (x-d[i])/dd[i]<n[i]){
					for(int j = w[i]; j <= e[i]; ++j)
						if(s[i] > wall[j]){
							wall[j] = s[i];
						}
					w[i] += dp[i]; e[i] += dp[i]; s[i] += ds[i];
				}
			}
		}
		printf("Case #%d: %d\n", kase, ans);
	}
	return 0;
}
