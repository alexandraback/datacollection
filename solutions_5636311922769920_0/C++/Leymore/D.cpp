#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int T, K, C, S;

int main() {
	freopen("D.in", "r", stdin);
	freopen("D.out", "w", stdout);
	scanf("%d", &T);
	for(int cas = 1; cas <= T; cas ++) {
		scanf("%d%d%d", &K, &C, &S);
		vector <ll> res;
		for(int i = 0; i < K;) {
			ll tmp = 0;
			for(int j = 0; j < C && i < K; j ++, i ++) {
				tmp = tmp * K + i;
			}
			res.push_back(tmp + 1);
		}
		printf("Case #%d: ", cas);
		if(res.size() > S) printf("IMPOSSIBLE\n");
		else {
			for(unsigned i = 0; i < res.size(); i ++)
				printf("%lld%c", res[i], i == res.size()-1 ? '\n' : ' ');
		}
	}
	return 0;
}
