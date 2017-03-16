#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		int k, c, s;
		cin >> k >> c >> s;
		printf("Case #%d:", cas);
		if((k+c-1) / c > s) {
			puts(" IMPOSSIBLE");
			continue;
		}
		int pre = 0;
		while(pre < k) {
			LL t = 0;
			int _ = c;
			rep(i, c) {
				t *= k;
				t += pre++, --_;
				if(pre == k) break;
			}
			++t;
			while(_--) t *= k;
			cout << ' ' << t;
		}
		puts("");
	}
	return 0;
}

