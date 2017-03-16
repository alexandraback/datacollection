#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("Dl.in", "r", stdin);
	freopen("Dl.out", "w", stdout);
	int T, K, C, S;
	cin>>T;
	for(int i = 1; i <= T; i++){
		scanf("%d%d%d", &K, &C, &S);
		printf("Case #%d:", i);
		if (S * C < K)
			puts(" IMPOSSIBLE");
		else{
			for(int i = 1; i * C < K; i++){
				long long tot = 0, k = (i - 1) * C;
				for(int j = 0; j < C; j++)
					tot = tot * K + k + j;
				printf(" %lld", tot + 1);
			}
			long long p = max(0, K - C), tot = 0;
			for(int j = 0; j < C; j++)
				tot = tot * K + ((p + j < K) ? p + j : K - 1);
			printf(" %lld", tot + 1);
			puts("");
		}
	}
	return 0;
} 
