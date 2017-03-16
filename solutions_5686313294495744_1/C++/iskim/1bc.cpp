#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

// in: n, m, graph
// out: match, matched
// vertex cover: (reached[0][left_node] == 0) || (reached[1][right_node] == 1)
struct BipartiteMatching
{
	int n, m;
	vector<vector<int> > graph;
	vector<int> matched, match;
	vector<int> edgeview;
	vector<int> level;
	vector<int> reached[2];
	BipartiteMatching(int n, int m) : n(n), m(m), graph(n), matched(m, -1), match(n, -1) {}

	bool assignLevel()
	{
		bool reachable = false;
		level.assign(n, -1);
		reached[0].assign(n, 0);
		reached[1].assign(m, 0);
		queue<int> q;
		for (int i = 0; i < n; i++) {
			if (match[i] == -1) {
				level[i] = 0;
				reached[0][i] = 1;
				q.push(i);
			}
		}
		while (!q.empty()) {
			auto cur = q.front(); q.pop();
			for (auto adj : graph[cur]) {
				reached[1][adj] = 1;
				auto next = matched[adj];
				if (next == -1) {
					reachable = true;
				}
				else if (level[next] == -1) {
					level[next] = level[cur] + 1;
					reached[0][next] = 1;
					q.push(next);
				}
			}
		}
		return reachable;
	}

	int findpath(int nod) {
		for (int &i = edgeview[nod]; i < graph[nod].size(); i++) {
			int adj = graph[nod][i];
			int next = matched[adj];
			if (next >= 0 && level[next] != level[nod] + 1) continue;
			if (next == -1 || findpath(next)) {
				match[nod] = adj;
				matched[adj] = nod;
				return 1;
			}
		}
		return 0;
	}

	int solve()
	{
		int ans = 0;
		while (assignLevel()) {
			edgeview.assign(n, 0);
			for (int i = 0; i < n; i++)
				if (match[i] == -1)
					ans += findpath(i);
		}
		return ans;
	}
};


char str1[30], str2[30];
vector<pair<string, string>> dat;
map<string, int> s1;
map<string, int> s2;

int main()
{
	freopen(R"(C:\Users\Unused\Downloads\C-large.in)", "r", stdin);
	freopen(R"(C:\Users\Unused\Downloads\C-large.out)", "w", stdout);
	int T;
	scanf("%d", &T);
	for (int tt = 1; tt <= T; tt++)
	{
		dat.clear();
		s1.clear();
		s2.clear();
		printf("Case #%d: ", tt);
		int n;
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%s%s", str1, str2);
			dat.emplace_back(str1, str2);
			s1.emplace(str1, 0);
			s2.emplace(str2, 0);
		}
		int idx = 0;
		for (auto &&elem : s1)
		{
			elem.second = idx++;
		}
		idx = 0;
		for (auto &&elem : s2)
		{
			elem.second = idx++;
		}

		BipartiteMatching bm(s1.size(), s2.size());
		for (int i = 0; i < n; i++)
		{
			bm.graph[s1[dat[i].first]].push_back(s2[dat[i].second]);
		}

		int matching = bm.solve();
		int remain = s1.size() + s2.size() - matching * 2;
		printf("%d\n", n - (matching + remain));
	}
}