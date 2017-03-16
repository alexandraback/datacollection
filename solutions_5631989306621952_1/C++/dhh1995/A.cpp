#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
#define FOR(i, x, y) for(int i = x; i < y; ++ i)
#define pb push_back
#define mk make_pair

const int N = 1123;
char s[N];

void solve() {
	scanf("%s", s);
	int n = strlen(s);
	string t = "";
	FOR(i,0,n)
	{
		if (t + s[i] > s[i] + t)
			t += s[i];
		else
			t = s[i] + t;
	}
	printf("%s\n", t.c_str());
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
