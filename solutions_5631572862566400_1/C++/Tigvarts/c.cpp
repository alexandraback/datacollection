#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int bff[2000];
int ans[2000];
vector<int> prev[2000];
queue<pair<int, int> > q;
vector<pair<int, int> > prs;

int
go(int v)
{
	int cur = v;
	for (int i = 0; i < n; ++i) {
		cur = bff[cur];
		if (cur == v) {
			return i + 1;
		}
	}
	return 0;
}

int
bfs(int v1, int v2)
{
	int ans = 0;
	while (!q.empty()) {
		pair<int, int> cur = q.front();
		q.pop();
		ans = max(ans, cur.second);
		for (int i = 0; i < prev[cur.first].size(); ++i) {
			if (prev[cur.first][i] != v1 && prev[cur.first][i] != v2) {
				q.push(make_pair(prev[cur.first][i], cur.second + 1));
			}
		}
	}
	return ans;
}

void
solve()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		prev[i].clear();
	}
	for (int i = 0; i < n; ++i) {
		scanf("%d", &bff[i]);
		bff[i]--;
		prev[bff[i]].push_back(i);
	}
	int bestans = 0;
	for (int i = 0; i < n; ++i) {
		bestans = max(bestans, go(i));
	}
	prs.clear();
	for (int i = 0; i < n; ++i) {
		if (bff[i] > i && bff[bff[i]] == i) {
			q.push(make_pair(i, 0));
			int len1 = bfs(i, bff[i]);
			q.push(make_pair(bff[i], 0));
			int len2 = bfs(i, bff[i]);
			if (bestans < len1 + len2 + 2) {
				bestans = len1 + len2 + 2;
			}
			prs.push_back(make_pair(max(len1, len2), min(len1, len2)));
		}
	}
	int lans = 0;
	for (int i = 0; i < prs.size(); ++i) {
		lans += 2 + prs[i].first + prs[i].second;
	}
	bestans = max(lans, bestans);
	printf("%d\n", bestans);
}

int
main()
{
    int t;
    scanf("%d\n", &t);
    for (int i = 0; i < t; ++i) {
        printf("Case #%d: ", i + 1);
        solve();
    }
}
