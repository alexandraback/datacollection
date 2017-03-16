#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

bool in[10];

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		printf("Case #%d: ", cas);
		int x;
		cin >> x;
		if(!x) {
			puts("INSOMNIA");
			continue;
		}
		memset(in, 0, sizeof(in));
		int cnt = 0;
		for(int j = 1; ; ++j) {
			int _ = x * j;
			while(_) {
				int temp = _ % 10;
				if(!in[temp]) in[temp] = true, ++cnt;
				_ /= 10;
			}
			if(cnt == 10) {
				cout << x*j << endl;
				break;
			}
		}
	}
	return 0;
}

