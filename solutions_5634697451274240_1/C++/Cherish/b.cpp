#include <bits/stdc++.h>
using namespace std;
#define ULL unsigned long long
#define LL long long
#define INF 0x3f3f3f3f
#define MAXN 1
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < n; ++i)
#define Rep(i,n) for(int i = 1; i <= n; ++i)

char s[110];

int main()
{
	int t, cas = 0;
	cin >> t;
	while(cas++ < t) {
		cin >> s;
		printf("Case #%d: ", cas);
		int cnt = unique(s, s+strlen(s)) - s;
		cnt -= s[cnt-1] == '+';
		cout << cnt << endl;
	}
	return 0;
}

