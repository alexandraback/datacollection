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

const int MAXN = 51;
const int MAXH = 2501;
int cas, n;
bool mark[MAXH];

void solve() {
	int loop = 0, temp = 0;
	scanf("%d", &cas);
	forn(i, cas) {
		memset(mark, 0, MAXH);
		printf("Case #%d: ", i + 1);
		scanf("%d", &n);
		loop = n * (2 * n - 1);
		forn(i, loop) {
			scanf("%d", &temp);
			mark[temp] = !mark[temp];
		}
		forn(i, MAXH) {
			if (mark[i]) printf("%d ", i);
		}
		printf(endl);
	}
}

int main() {
	freopen("B-large.in", "rt", stdin);
	freopen("B-large.out", "wt", stdout);
	
	solve();

	return 0;
}