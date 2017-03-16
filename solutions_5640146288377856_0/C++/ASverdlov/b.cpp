#include <bits/stdc++.h>
using namespace std;
#define forn(i, n)    for (int i = 0; i < (int)(n); ++i)
#define ford(i, n)    for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)
#define DB(v) cerr << #v << ": " << v << endl
#define fi first
#define se second

int main()
{
#ifdef HOME
	freopen("input.txt", "r", stdin);
	freopen("output_new.txt", "w", stdout);
#endif

	int T; cin >> T;
	for (int t = 1; t <= T; ++t) {
		int r, c, w;
		cin >> r >> c >> w;
		int vmoves = r * c / w;
		int ans = vmoves + w - 1 + ((c % w) > 0);
		cout << "Case #" << t << ": " << ans << '\n';
	}

#ifdef HOME
	//cout << "\nTime elapsed: " << clock() << '\n';
#endif
	return 0;
}
