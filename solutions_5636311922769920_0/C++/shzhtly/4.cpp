#include<bits/stdc++.h>
using namespace std;

typedef long long LL;

int n, m, s;

int main(){
//	freopen("D-small-attempt0.in", "r", stdin);
//	freopen("out_d.txt", "w", stdout);
	int T, cases = 0;
	scanf("%d", &T);
	while(T--){
		scanf("%d%d%d", &n, &m, &s);
		if(m * s < n){
			printf("Case #%d: IMPOSSIBLE\n", ++cases);
			continue;
		}
		LL UP = 1;
		for(int i = 0; i < m; ++i) UP *= n;
		vector<LL> ans;
		int up;
		for(int i = 0; i < n; i += m){
			up = min(m, n - i);
//			printf("up = %d\n", up);
			LL res = i;
			for(int j = 1; j < m; ++j){
				if(j >= up){
					res = res * n + i + up - 1;
				}
				else {
					res = res * n + i + j;
				}
//				printf("res = %d\n", res);
			}
			ans.push_back(res + 1);
		}
		printf("Case #%d:", ++cases);
		for(int i = 0; i < ans.size(); ++i){
			printf(" %lld", ans[i]);
		}
		puts("");
	}
	return 0;
}
