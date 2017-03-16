#include <cstdio>
#include <iostream>
#include <string>

using namespace std;

#define FOR(i,a,b) for (int i=int(a);i<=int(b);++i)
#define REP(i,n) FOR(i,0,(n)-1)
#define PB push_back

int bff[1010], vis[1010], longest[1010];

int main() {
	int tN;
	cin >> tN;
	FOR(cN, 1, tN) {
		int n;
		cin >> n;
		REP(i, n) {
			cin >> bff[i];
			--bff[i];
		}
		int ans = 0;
		memset(longest, 0, sizeof(longest));
		REP(i, n) {
			memset(vis, 0, sizeof(vis));
			int k = i, id = 0;
			vis[k] = ++id;
			while (vis[bff[k]] == 0) {
				k = bff[k];
				vis[k] = ++id;
			}
			if (vis[bff[k]] == id-1) longest[bff[k]] = max(longest[bff[k]], id-1);
			else ans = max(ans, id - vis[bff[k]] + 1);
		}
		int ans2 = 0;
		REP(i, n) ans2 += longest[i];
		// REP(i, n) printf("longest[%d] = %d\n", i, longest[i]);
		// printf("ans = %d, ans2 = %d\n", ans, ans2);
		ans = max(ans, ans2);
		cout << "Case #" << cN << ": " << ans << endl;
	}
}
