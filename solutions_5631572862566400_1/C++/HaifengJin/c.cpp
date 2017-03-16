#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

#define d(x) 

const int MAX_N = 1010;

int degree[MAX_N];

int bff[MAX_N];
int n;
int ans;
bool vis[MAX_N];
int depth[MAX_N];

vector<int> edge[MAX_N];

void topo(int node_num)
{
	//indexes start from 0
	queue<int> q;
	for (int i = 0; i < node_num; i++)
	{
		if (degree[i] == 0)
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		//push u into an array to get the topological order sequence
		int v = bff[u];
		if (degree[v] == 0)
		{
			continue;
		}
		degree[v]--;
		if (degree[v] == 0)
		{
			q.push(v);
		}
	}
	//if degree[i] != 0 now, it means there is a circle on the connected component with vertex i.
}

void init_edge()
{
	for (int i = 0; i < MAX_N; i++)
		edge[i].clear();
}

void input()
{
	memset(degree, 0, sizeof(degree));
	scanf("%d", &n);
	init_edge();
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &bff[i]);
		bff[i]--;
		edge[bff[i]].push_back(i);
		degree[bff[i]]++;
	}
}

int find_circle()
{
	topo(n);
	memset(vis, 0, sizeof(vis));
	int ret = 1;
	for (int i = 0; i < n; i++)
	{
		if (degree[i] == 0)
			continue;
		if (vis[i])
			continue;
		int temp = i;
		vis[i] = true;
		int cnt = 1;
		while (!vis[bff[temp]])
		{
			temp = bff[temp];
			vis[temp] = true;
			cnt++;
		}
		ret = max(ret, cnt);
	}
	return ret;
}

int find_deepest(int a, int b)
{
		d(printf("a=%d\n", a));
	memset(vis, 0, sizeof(vis));
	memset(depth, 0, sizeof(depth));
	vis[b] = true;
	vis[a] = true;
	queue<int> q;
	q.push(a);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		d(printf("u=%d\n", u));
		for (int i = 0; i < (int)edge[u].size(); i++)
		{
			int v = edge[u][i];
			if (vis[v])
				continue;
			q.push(v);
			vis[v] = true;
			depth[v] = depth[u] + 1;
		}
	}

	return *max_element(depth, depth + n);
}

int work()
{
	int ret = 0;
	for (int i = 0; i < n; i++)
	{
		if (i != bff[bff[i]])
			continue;
		if (i > bff[i])
			continue;
		ret += find_deepest(i, bff[i]) + find_deepest(bff[i], i) + 2;
		d(printf("ret=%d\n", ret));
	}
	return ret;
}

int main()
{
	int t;
	scanf("%d", &t);
	int case_num = 0;
	while (t--)
	{
		case_num++;
		printf("Case #%d: ", case_num);
		input();
		ans = 1;
		ans = max(ans, find_circle());
		ans = max(ans, work());
		printf("%d\n", ans);
	}
	return 0;
}
