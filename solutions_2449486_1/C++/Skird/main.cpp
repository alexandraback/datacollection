#include <cmath>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>

#include <algorithm>
#include <iostream>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

using namespace std;

typedef long long ll;
typedef long double lf;

const int maxn = 100, maxv = 100;

int data[maxn][maxn], temp[maxn][maxn], row[maxn], col[maxn], n, m;
vector< pair<int, int> > pos[maxv];

string solve()
{
	for (int i = 0; i < maxv; i++) pos[i].clear();
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &data[i][j]),
			pos[--data[i][j]].push_back(make_pair(i, j));
	for (int i = 0; i < maxv; i++)
		for (size_t j = 0; j < pos[i].size(); j++)
		{
			int x = pos[i][j].first, y = pos[i][j].second;
			row[x] = i, col[y] = i;
		}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = maxv;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			temp[i][j] = min(temp[i][j], row[i]);
	for (int j = 0; j < m; j++)
		for (int i = 0; i < n; i++)
			temp[i][j] = min(temp[i][j], col[j]);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (data[i][j] != temp[i][j]) return "NO";
	return "YES";
}

int main()
{
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
#endif
	int t;
	scanf("%d\n", &t);
	for (int i = 0; i < t; i++) cout << "Case #" << i + 1 << ": " << solve() << endl;
	return 0;
}
