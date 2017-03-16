#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <queue>

#define LL long long
#define mp(x, y) make_pair(x, y)
#define pb(x) push_back(x)
#define PII pair<int, int>
#define PID pair<int, double>

using namespace std;

int n, T, cnt;
int f[1010], d[1010], cs[1010];
int vis[1010];
int cl[1010];
bool ref[1010];
vector<vector<int>> L;
int K[1010];

int get(int x, int sign) {
	if (vis[x]) {
		if (vis[x] != sign) return 0;
		else return x;
	}
	if (x != sign) ref[x] = true;
	vis[x] = sign;
	int r = get(f[x], sign);
	if (r == 0) {
		d[x] = d[f[x]] + 1;
		return 0;
	} else {
		d[x] = 0;
		cs[x] = cnt;
		cl[cnt]++;
		if (x == r) {
			cnt++;
			return 0;
		}
		return r;
	}
}

int main(){
	cin >> T;
	for (int v = 0; v < T; v++) {
		cout << "Case #" << v + 1 << ": ";
		cin >> n;
		for (int i = 1; i <= n; ++i) cin >> f[i];

		cnt = 0;
		memset(d, 0, sizeof(d));
		memset(vis, 0, sizeof(vis));
		memset(ref, false, sizeof(ref));
		memset(cs, -1, sizeof(cs));
		memset(cl, 0, sizeof(cl));
		for (int i = 1; i <= n; ++i)
			get(i, i);

		map<int, int> T;
		L.clear();
		int c = 0;
		for (int i = 0; i < cnt; ++i)
			if (cl[i] == 2) {
				T[i] = c++;
			}
		L.resize(c);
		memset(K, 0, sizeof(K));
		for (int i = 1; i <= n; ++i) {
			if (ref[i]) continue;
			int x = i;
			while (d[x] > 0) x = f[x];
			K[x] = max(K[x], d[i]);
			//int s = cs[x];
			//if (cl[s] > 2) continue;
			//L[s].pb(d[i]);
		}
		for (int i = 1; i <= n; ++i)
			if (K[i] > 0) {
				int s = cs[i];
				if (cl[s] > 2) continue;
				L[T[s]].pb(K[i]);
			}

		int ans = 0, sum = 0;
		sort(cl, cl + cnt);
		ans = cl[cnt-1];
		for (int i = 0; i < L.size(); ++i) {
			sort(L[i].begin(), L[i].end());
			int s = L[i].size();
			sum += 2;
			if (s > 0) sum += L[i][s-1];
			if (s > 1) sum += L[i][s-2];
		}
		if (sum > ans) ans = sum;
		cout << ans << endl;
	}
}
