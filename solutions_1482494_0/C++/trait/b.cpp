#define FILEIO

#define INPUT "in"
#define OUTPUT "out"

#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cctype>
#include <vector>
#include <cassert>

#define mp make_pair
#define pb push_back
#define foreach(i,T) for(__typeof(T.begin()) i = T.begin(); i != T.end(); ++i)

using namespace std;

namespace Solve {
	const int MAXN = 1050;

	pair<int, int> a[MAXN]; int n;
	int vis[MAXN];

	inline void Input(void) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].second, &a[i].first);
	}

	inline int Cal(void) {
		sort(a + 1, a + n + 1);
		int t = 0, s = 0;
		while (true) {
			if (s == n * 2) return t;
			bool flag = false;
			for (int i = 1; i <= n; i++) if (vis[i] == 0 && s >= a[i].first) {
				vis[i] = 2;
				s += 2;
				flag = true;
				t++;
				break;
			}
			if (flag) continue;
			for (int i = 1; i <= n; i++) if (vis[i] == 1 && s >= a[i].first) {
				vis[i] = 2;
				s += 1;
				flag = true;
				t++;
				break;
			}
			if (flag) continue;
			for (int i = n; i >= 1; i--) if (vis[i] == 0 && s >= a[i].second) {
				vis[i] = 1;
				s += 1;
				flag = true;
				t++;
				break;
			}
			if (!flag) return t = -1;
		}
	}

	inline void solve(void) {
		memset(vis, 0, sizeof vis);
		Input();
		int Ans = Cal();
		if (Ans == -1) puts("Too Bad"); else
		printf("%d\n", Ans);
	}
}

int main(void) {
	#ifdef FILEIO
		freopen(INPUT, "r", stdin);
		freopen(OUTPUT, "w", stdout);
	#endif
	int t, i; for (scanf("%d", &t), i = 1; i <= t; i++) {
		printf("Case #%d: ", i);
		Solve::solve();
	}
	return 0;
}
