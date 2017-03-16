#include <stdio.h>
#include <set>
#include <vector>
using namespace std;

int T, N;
int BFF[2000];
vector<int> iv_BFF[2000];
int visit[2000];

void dfs(int v, int root, set<int> &s, int &cnt)
{
	if (v == root && s.find(v) != s.end())
		cnt = 1;
	if (s.find(v) != s.end())
		return;
	s.insert(v);
	dfs(BFF[v], root, s, cnt);
	if (cnt == 1)
		visit[v] = 1;
}

int dfs_path(int v)
{
	if (int(iv_BFF[v].size()) == 0)
		return 1;
	int res = 1;
	for (int i = 0; i < int(iv_BFF[v].size()); i++) {
		if (iv_BFF[v][i] == BFF[v])
			continue;
		int tmp = dfs_path(iv_BFF[v][i]) + 1;
		res = res > tmp ? res : tmp;
	}
	return res;
}

int solve()
{
	int res = 0;
	int res_2 = 0;

	for (int i = 1; i <= N; i++) {
		int cnt = 0;
		set<int> s;
		if (visit[i] == 0) {
			dfs(i, i, s, cnt);
			if (cnt == 1) {
				if (int(s.size()) > 2) {
					res = res > int(s.size()) ? res : int(s.size());
				} else {
					res_2 += dfs_path(i) + dfs_path(BFF[i]);
				}
			}
		}
	}	

	return res>res_2 ? res : res_2;
}

int main()
{
	scanf(" %d", &T);
	for (int cas = 1; cas <= T; cas++) {
		scanf(" %d", &N);
		for (int i = 1; i <= N; i++)
			iv_BFF[i].clear();
		for (int i = 1; i <= N; i++) {
			scanf(" %d", &BFF[i]);
			iv_BFF[BFF[i]].push_back(i);
			visit[i] = 0;
		}
		int res = solve();
		printf("Case #%d: %d\n", cas, res);
	}

	return 0;
}