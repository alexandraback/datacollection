#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define forn(i, n) for (int i = 0; i < n; ++i)
#define ford(i, n) for (int i = n - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = a; i < b; ++i)
#define forl(i, x) for (int i = 0; i < x.size(); ++i)
#define ul unsigned long
#define ll long long
#define pii std::pair<int, int>
#define vpii vector<pii >
#define all(x) x.begin(), x.end()

const int MAXN = 1005;
char s[MAXN];
string res;
int cas;

void solve() {
	scanf("%d", &cas);
	getc(stdin);
	forn(i, cas) {
		res.clear();
		printf("Case #%d: ", i + 1);
		gets(s);
		res = s[0];
		fore(i, 1, strlen(s)) {
			if (s[i] >= res[0]) res = s[i] + res;
			else res = res + s[i];
		}
		cout << res << endl;
	}
}

int main() {
	freopen("A-small-attempt0.in", "rt", stdin);
	freopen("A-small-attempt0.out", "wt", stdout);
	
	solve();

	return 0;
}