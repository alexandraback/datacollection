#include <iostream>
#include <cstdio>
#include <queue>
#include <vector>
#include <stack>
#include <utility>
#include <functional>
using namespace std;

const int maxn = 60;

int n, m;
int dat[maxn], deg[maxn];
vector<int> ga[maxn];

int col, cpvis[maxn];

bool checkpoint(int st, int* vis)
{
	if (cpvis[st] == col) return false;
	if (vis[st] == -1) return true;
	if (vis[st] == -2) return false;
	cpvis[st] = col;
	for (vector<int>::iterator it = ga[st].begin(); it != ga[st].end(); it++)
		if (checkpoint(*it, vis)) return true;
	return false;
}

void init()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &dat[i]);
		ga[i].clear();
		deg[i] = 0;
	}
	for (int i = 0; i < m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		ga[x].push_back(y);
		ga[y].push_back(x);
		deg[x]++;
		deg[y]++;
	}
}

void work()
{
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > Q;
	stack<int, vector<int> > S;
	static int vis[maxn];
	
	for (int i = 1; i <= n; i++) vis[i] = 0;
	while (!Q.empty()) Q.pop();
	while (!S.empty()) S.pop();
	
	int now = 1;
	for (int i = 2; i <= n; i++)
		if (dat[i] < dat[now]) now = i;
	
	for (int i = 1; i <= n; i++)
	{
		vis[now] = -1;
		S.push(now);
		printf("%d", dat[now]);
		for (vector<int>::iterator it = ga[now].begin(); it != ga[now].end(); it++)
		{
			if (vis[*it] != -1)
				if (vis[*it]++ == 0) Q.push(make_pair(dat[*it], *it));
		}
		
		while (!Q.empty() && vis[Q.top().second] <= 0) Q.pop();
		if (Q.empty()) break;
		int mind = Q.top().first;
		bool found = false;
		for (vector<int>::iterator it = ga[now].begin(); it != ga[now].end(); it++)
		{
			if (dat[*it] == mind)
			{
				found = true;
				break;
			}
		}
		while (!S.empty() && !found)
		{
			int j = S.top();
			vis[j] = -2;
			col++;
			for (vector<int>::iterator it = ga[j].begin(); it != ga[j].end(); it++)
			{
				if (vis[*it] <= 0) continue;
				if (!checkpoint(*it, vis))
				{
					found = true;
					break;
				}
			}
			if (found)
			{
				found = false;
				vis[j] = -1;
				break;
			}
			for (vector<int>::iterator it = ga[j].begin(); it != ga[j].end(); it++)
				if (vis[*it] > 0) vis[*it]--;
			S.pop();
			if (S.empty()) break;
			j = S.top();
			found = false;
			for (vector<int>::iterator it = ga[j].begin(); it != ga[j].end(); it++)
			{
				if (dat[*it] == mind)
				{
					found = true;
					break;
				}
			}
		}
		if (S.empty()) break;
		if (found)
			now = Q.top().second;
		else
		{
			int j = S.top(), minj = -1;
			for (vector<int>::iterator it = ga[j].begin(); it != ga[j].end(); it++)
			{
				if (vis[*it] <= 0) continue;
				if (minj == -1 || dat[*it] < dat[minj]) minj = *it;
			}
			now = minj;
		}
	}
	
	printf("\n");
}

int main()
{
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		init();
		printf("Case #%d: ", i);
		work();
	}
	return 0;
}
