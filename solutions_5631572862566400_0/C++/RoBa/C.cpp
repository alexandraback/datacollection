#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <map>
#include <algorithm>
using namespace std;

#define MP make_pair

const int MAXN = 1024;
int a[MAXN];
int vis[MAXN];
int inloop[MAXN];
map<pair<int,int>,int> mp;

int solve(int p) {
	int start = p;
	memset(vis, 0, sizeof(vis));
	vis[p] = 1;
	int pre = -1, cnt = 1;
	while (1) {
		int tmp = p;
		p = a[p];
		// if (inloop[p])
		// 	return 0;
		if (vis[p]) {
			if (p == pre) {
				if (cnt > mp[MP(tmp, p)]) {
					mp[MP(tmp,p)] = cnt;
					// printf("start:%d (%d,%d)=>%d\n", start, tmp, p, cnt);
				}
				return 0; //cnt;
			}
			if (p == start) {
				// inloop[start] = 1;
				return cnt;
			}
			return 0;
		}
		vis[p] = 1;
		pre = tmp;
		++cnt;
	}
}

int main() {
	int T, n;
	scanf("%d",&T);
	for (int ca = 1 ; ca <= T ; ++ca) {
		scanf("%d",&n);
		for (int i = 0 ; i < n ; ++i) {
			scanf("%d", &a[i]);
			--a[i];
		}
		// memset(inloop, 0, sizeof(inloop));
		mp.clear();
		int best = 0;
		for (int i = 0 ; i < n ; ++i) {
			int tmp = solve(i);
			// printf("=== start from %d, ans:%d\n", i, tmp);
			if (tmp > best) best = tmp;
			// best += tmp;
		}
		int best2 = 0;
		for (auto itr : mp) {
			int v1 = itr.first.first;
			int v2 = itr.first.second;
			if (v1 > v2) continue;
			int tmp = itr.second + mp[MP(v2,v1)] - 2;
			// if (tmp > best) best = tmp;
			// printf("v1:%d v2:%d tmp:%d (%d,%d)\n", v1, v2, tmp, itr.second, mp[MP(v2,v1)]);
			best2 += tmp;
		}
		// printf("best:%d best2:%d\n", best, best2);
		printf("Case #%d: %d\n", ca, max(best, best2));
	}
	return 0;
}