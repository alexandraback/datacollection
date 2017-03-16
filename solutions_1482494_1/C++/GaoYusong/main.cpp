#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <string>
#include <iostream>
#include <vector>
#include <map>
#include <utility>
#include <algorithm>
#include <queue>
#include <set>
#include <stack>
#include <list>

using namespace std;

//GyS Loves Algorithm
#define X first
#define Y second
#define all(x) x.begin(), x.end()
#define mk(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define rep(x, n) for (int x = 0; x < n; x++)
#define range(x, a, b)for (int x = a; x <= b; x++)
#define sz(x) x.size()
#define setv(x, y) memset(x, y, sizeof(x))
#define repi(it, x) for (typeof(x.begin()) it = x.begin(); it != x.end(); ++it)
#define pl() printf("\n")

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

pii aa[1100];
int n;

bool solve(int mid)
{
	int vis[1100];
	memset(vis, 0, sizeof(vis));
	int lim = mid;
	int star = 0;
	int cnt = 0;
	while (true) {
		//printf("lim %d %d\n", star, lim);
		bool ok = true;
		for (int i = 0; i < n && ok; i++) {
			if (vis[i] == 0 && aa[i].Y <= star) {
				if (lim > 0) {
					vis[i] = 2;
					star += 2;
					cnt++;
					ok = false;
					lim--;
					break;
				}
			}
		}
		for (int i = 0; i < n && ok; i++) {
			if (vis[i] == 1 && aa[i].Y <= star) {
				if (lim > 0) {
					vis[i] = 2;
					star += 1;
					cnt++;
					ok = false;
					lim--;
					break;
				}
			}
		}
		int mini = -1, minv = -1;
		for (int i = 0; i < n && ok; i++) {
			if (vis[i] == 0 && aa[i].X <= star) {
				if (minv < aa[i].Y) {
					minv = aa[i].Y;
					mini = i;
				}
			}
		}
		if (mini != -1) {
			if (lim > 0) {
				vis[mini] = 1;
				star += 1;
				ok = false;
				lim--;
			}
		}
		
		if (ok) {
			break;
		}
	}
	return cnt == n;
}

void check()
{
	int id[20];
	for (int i = 0; i < n; i++) 
		id[i] = i;

	int ans = 0;

	do {
		int ret = 0;
		int star = 0;
		for (int i = 0; i < n; i++) {
			if (aa[id[i]].Y <= star) {
				star += 2;
				ret++;
			} else {
			}
		}
	} while (next_permutation(id, id + n));

}

int main()
{
	int cn = 0, T;

	freopen("B-large.in", "r", stdin);
	freopen("B-large.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d%d", &aa[i].X, &aa[i].Y);
		}

		//sort(aa, aa + n);
		int l = n, r = 2 * n + 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (solve(mid)) {
				r = mid;
			} else {
				l = mid + 1;
			}
		}
		printf("Case #%d: ", ++cn);
		if (r == 2 * n + 1) {
			printf("Too Bad\n");
		} else {
			printf("%d\n", r);
		}
	}
	return 0;
}
