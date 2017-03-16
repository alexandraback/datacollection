#include <stdio.h>
#include <stdarg.h>
#include <cstring>
#include <algorithm>
#include <set>
#include <vector>
#define clr(a) memset(a, 0, sizeof(a))

typedef long long ll;
typedef std::pair<int, int> pii;
#define DEBUG 1

void dbg(const char * fmt, ...)
{
#if DEBUG
	va_list args;
	va_start(args, fmt);
	vfprintf(stdout, fmt, args);
	va_end(args);
#endif
}

const int size = 100;
std::vector<int> adjlist[size];
int idx[size];

const int open = 0;
const int current = 1;
const int closed = 2;

bool use[size];
int state[size];

int dfs(int v)
{	
	if (use[v] || state[v])
		return 0;
	use[v] = 1;
	int ans = 1;
	for(int i = 0; i < (int) adjlist[v].size(); i++)
		ans += dfs(adjlist[v][i]);
	return ans;
}


void solve(int test_case)
{
	printf("Case #%d: ", test_case);
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < n; i++)
	{
		adjlist[i].clear();
		scanf("%d", &idx[i]);
	}
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a--; b--;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	int best = -1;
	clr(state);
	for (int i = 0; i < n; i++)
	{
		clr(use);
		if (dfs(i) == n && (best == -1 || idx[i] < idx[best]))
			best = i;
	}
	std::vector<int> path;
	std::vector<int> ans;
	int cnt = 1;
	path.push_back(best);
	ans.push_back(best);
	clr(use);
	while(cnt < n)
	{
		clr(use);
		for(int i = 0; i < (int) path.size(); i++)
			state[path[i]] = 1;
		int cnt_avail = 0;
		int idx_good = -1;
		for(int i = 0; i < (int) path.size(); i++)
		{
			state[path[i]] = 0;
			cnt_avail += dfs(path[i]);
			state[path[i]] = 1;
			if (cnt_avail + cnt - i - 1 == n)
			{
				idx_good = i;
				break;
			}
		}
		if (idx_good == -1)
		{
			dbg("Cnt = %d, path = \n", cnt);
			for(int i = 0; i < (int) path.size(); i++)
				printf("%d %d\n", path[i]+1, state[path[i]]);
			throw 42;
		}
		int best_cur = -1;
		int best_next = -1;
		for(int i = idx_good; i < (int) path.size(); i++)
		{
			for(int j = 0; j < (int) adjlist[path[i]].size(); j++)
			{
				int cn = adjlist[path[i]][j];
				if (state[cn] == 0 && (best_next == -1 || pii(idx[best_next], i) > pii(idx[cn], best_cur)))
				{
					best_next = cn;
					best_cur = i;
				}
			}
		}
		path.resize(best_cur+1);
		path.push_back(best_next);
		ans.push_back(best_next);
		cnt++;
	}
	for(int i = 0; i < (int) ans.size(); i++)
		printf("%d", idx[ans[i]]);
	printf("\n");
}

int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		solve(i);

	return 0;
}
