#include <cmath>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <climits>
#include <cstring>
#include <vector>
#include <string>
#include <iostream>
#include <cassert>
#include <algorithm>

using namespace std;

const int N = 1000 + 10;

int n;
int deg[N];
int dist[N];
int anc[N];
int to[N];
int maxv[N];
int vis[N];
int good[N];

void solve()
{
	cin >> n;
	for(int i = 0; i < n; ++ i) {
		dist[i] = 0;
		deg[i] = 0;
		maxv[i] = 0;
		anc[i] = i;
		vis[i] = false;
		good[i] = false;
	}
	for(int i = 0; i < n; ++ i) {
		scanf("%d", to + i);
		to[i] --;
		deg[to[i]] ++;
	}
	vector<int> que;
	for(int i = 0; i < n; ++ i) {
		if (deg[i] == 0) {
			que.push_back(i);
		}
	}
	for(int i = 0; i < que.size(); ++ i) {
		int u = que[i];
		--deg[to[u]];
		if (deg[to[u]] == 0) {
			que.push_back(to[u]);
		}
	}
	for(int i = (int)que.size() - 1; i >= 0; -- i) {
		int u = que[i];
		dist[u] = dist[to[u]] + 1;
		anc[u] = anc[to[u]];
		maxv[anc[u]] = max(maxv[anc[u]], dist[u]);
	}
	int maxc = 0;
	for(int i = 0; i < n; ++ i) {
		if (deg[i]) {
			if (vis[i]) continue;
			vector<int> vec;
			for(int j = i; ! vis[j]; j = to[j]) {
				vis[j] = true;
				vec.push_back(j);
			}
			if (vec.size() == 2) {
				good[vec[0]] = good[vec[1]] = true;
			} else {
				maxc = max(maxc, (int)vec.size());
			}
		}
	}
	int tot = 0;
	for(int i = 0; i < n; ++ i) {
		if (good[i]) tot += maxv[i] + 1;
	}
	cout << max(tot, maxc) << endl;
}

int main()
{
	//freopen("C-small-attempt0.in", "r", stdin); freopen("C-small-attempt0.out", "w", stdout);
	freopen("C-small-attempt1.in", "r", stdin); freopen("C-small-attempt1.out", "w", stdout);
	//freopen("C-small-attempt2.in", "r", stdin); freopen("C-small-attempt2.out", "w", stdout);
	//freopen("C-large.in", "r", stdin); freopen("C-large.out", "w", stdout);
	int test_case;
	cin >> test_case;
	for(int i = 0; i < test_case; ++ i) {
		printf("Case #%d: ", i + 1);
		cerr << "Start: " << i << endl;
		solve();
	}
	return 0;
}
