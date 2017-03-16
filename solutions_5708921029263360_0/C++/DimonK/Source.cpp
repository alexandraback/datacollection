#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdexcept>
#include <string>
#include <assert.h>
#include <set>
#include <time.h>
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

const int N = 100055;

int n, m;
int cur;
bool used[N];

int sF, tF;

struct edge
{
	int to;
	int cap;

	edge(int to, int cap)
	{
		this->to = to;
		this->cap = cap;
	}

	edge() :to(0), cap(0)
	{

	}
};

vector <edge> edges;
vector <int> g[N];

inline void add(int a, int b, int cap, int cap2)
{
	g[a].push_back(edges.size());
	edges.push_back(edge(b, cap));
	g[b].push_back(edges.size());
	edges.push_back(edge(a, cap2));
}

bool dfs(int v)
{
	used[v] = true;
	if (v == tF)
	{
		return true;
	}

	for (int i = 0; i < g[v].size(); i++)
	{
		int idx = g[v][i];
		if (!used[edges[idx].to] && edges[idx].cap >= cur && dfs(edges[idx].to))
		{
			edges[idx].cap -= cur;
			edges[idx ^ 1].cap += cur;
			return true;
		}
	}

	return false;
}


int flow() {

	int ans = 0;
	cur = 151515;
	while (cur > 0)
	{
		memset(used, false, sizeof(used));
		if (!dfs(sF))
		{
			cur = (cur >> 1);
		}
		else
		{
			ans += cur;
		}
	}
	return ans;
}

int matr1[11][11];
int matr2[11][11];
pair<int, int> nums[N];

int cnt1[3][3];
int cnt2[3][3];
int cnt3[3][3];
int gg[3][3][3][11];
int gm[3][3][3][11];
bool was[3][3][3];

int main() {

	freopen("cq.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	cin >> tests;
	for (int te = 1; te <= tests; te++) {
		int j, p, s, k;
		
		cin >> j >> p >> s >> k;
		
		vector<pair<int, pair<int, int>>> v;
		for (int from = 0; from < j; from++)
			for (int to = 0; to < p; to++) {
				for (int to2 = 0; to2 < s; to2++) {
					v.push_back(make_pair(from, make_pair(to, to2)));
				}
			}


		if (!was[j][p][s]) {
			was[j][p][s] = true;
			int cnt = (int)v.size();
			for (int mask = 0; mask < (1 << cnt); mask++) {
				memset(cnt1, 0, sizeof cnt1);
				memset(cnt2, 0, sizeof cnt2);
				memset(cnt3, 0, sizeof cnt3);

				int mx = -1;
				int col = 0;

				for (int i = 0; i < v.size(); i++) {
					if ((mask & (1 << i)) != 0) {
						cnt1[v[i].second.first][v[i].second.second]++;
						cnt2[v[i].first][v[i].second.second]++;
						cnt3[v[i].first][v[i].second.first]++;
						mx = max(mx, cnt1[v[i].second.first][v[i].second.second]);
						mx = max(mx, cnt2[v[i].first][v[i].second.second]);
						mx = max(mx, cnt3[v[i].first][v[i].second.first]);
						col++;
					}
				}
				for (int kj = mx; kj <= 10; kj++) {
					if (col > gg[j][p][s][kj]) {
						gg[j][p][s][kj] = col;
						gm[j][p][s][kj] = mask;
					}
				}
			}
		}

		int ans = gg[j][p][s][k];
		int maskans = gm[j][p][s][k];
		cout << "Case #" << te << ": " << ans << endl;
		for (int i = 0; i < v.size(); i++) 
			if ((maskans & (1 << i)) != 0)
				cout << v[i].first + 1<< " " << v[i].second.first+1 << " " << v[i].second.second+1 << endl;
	
	}

}