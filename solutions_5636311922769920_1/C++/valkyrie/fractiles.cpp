#include <bits/stdc++.h>

#define TRACE(x) cerr << #x << " " << x << endl
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define REP(i, n) FOR(i, 0, n)
using namespace std;
typedef long long ll;

int main()
{
	int T;
	cin>>T;
	REP(w, T){
		int K, C, S;
		scanf("%d%d%d", &K, &C, &S);
		if (S * C < K){
			printf("Case #%d: IMPOSSIBLE\n", w + 1);
			continue;
		}
		int kant = 0;
		printf("Case #%d: ", w + 1);
		while (kant < K){
			ll num = 0;
			REP(expo, C){
				num *= K;
				num += (kant >= K) ? 0 : kant;
				if (kant < K)
					kant++;
			}
			printf("%lld ", num + 1);
		}
		printf("\n");
	}
	return 0;
}

