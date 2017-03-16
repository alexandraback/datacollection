#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

char s[105];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	int ans = 0;
	while (n > 0 && s[n - 1] == '+')
		--n;
	FOR(i,0,n)
	{
		if (i == 0 || s[i] != s[i - 1])
			++ans;
	}
	printf("%d\n", ans);
}

int main() {
#ifdef LOCAL
	freopen("in","r",stdin);
#endif
	int T, Case = 0;
	scanf("%d", &T);
	while (T--) {
		printf("Case #%d: ", ++Case);
		solve();
	}
	return 0;
}
