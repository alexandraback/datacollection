#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
using namespace std;

const int treeSize = (1 << 21);
const int inf = (int) 1e9;

int dayFirst[1005], sFirst[1005];
int m[1005];
int w[1005], e[1005];
int dayDelta[1005], distDelta[1005], sDelta[1005];
int n;

pair < int , pair < pair < int , int > , int > > p[2000005];
int scaledPos[1005][1005][2];
int pSize;

pair < int , pair < pair < int , int > , int > > events[2000005];
int eventsSize;

int tree[treeSize * 2 + 5], com[treeSize * 2 + 5];
pair < pair < int , int > , int > hRenew[2000005];
int hRenewSize;

void buildPos (int sPos, int side)
{
	for (int i = 0; i < n; i++)
	{
		int curPos = sPos;

		for (int j = 0; j < m[i]; j++)
		{
			p[pSize++] = make_pair(curPos, make_pair(make_pair(i, j), side) );

			curPos += distDelta[i];
		}
	}
}

void scalePos ()
{
	sort(p, p + pSize);

	scaledPos[p[0].second.first.first][p[0].second.first.second][p[0].second.second] = 0;
	int cnt = 0;
	for (int i = 1; i < pSize; i++)
	{
		if (p[i].first != p[i - 1].first)
			cnt++;

		scaledPos[p[i].second.first.first][p[i].second.first.second][p[i].second.second] = cnt;
	}
}

bool cmpEvents (pair < int , pair < pair < int , int > , int > > a, pair < int , pair < pair < int , int > , int > > b)
{
	return a.first < b.first;
}

void genEvents ()
{
	eventsSize = 0;

	for (int i = 0; i < n; i++)
	{
		int curStrength = sFirst[i];
		int curDay = dayFirst[i];

		for (int j = 0; j < m[i]; j++)
		{
			events[eventsSize++] = make_pair(curDay, make_pair(make_pair(scaledPos[i][j][0], scaledPos[i][j][1]), curStrength) );

			curStrength += sDelta[i];
			curDay += dayDelta[i];
		}
	}

	sort(events, events + eventsSize, cmpEvents);
}

void buildTree ()
{
	for (int i = 0; i < treeSize; i++)
	{
		tree[treeSize + i] = 0;
		com[treeSize + i] = 0;
	}

	for (int i = treeSize - 1; i > 0; i--)
	{
		tree[i] = 0;
		com[i] = 0;
	}
}

void tree_set (int v, int tl, int tr, int l, int r, int val)
{
	if (tr < l || tl > r)
		return ;

	if (l <= tl && tr <= r)
	{
		com[v] = max(com[v], val);
		tree[v] = com[v];
		return ;
	}

	com[v * 2] = max(com[v * 2], com[v] );
	com[v * 2 + 1] = max(com[v * 2 + 1], com[v] );
	com[v] = 0;

	int mid = (tl + tr) / 2;

	tree_set(v * 2, tl, mid, l, r, val);
	tree_set(v * 2 + 1, mid + 1, tr, l, r, val);

	tree[v] = min(tree[v * 2], tree[v * 2 + 1] );
}

void treeSet (int l, int r, int strength)
{
	tree_set(1, 0, treeSize - 1, l, r, strength);
}

int tree_get (int v, int tl, int tr, int l, int r)
{
	if (tr < l || tl > r)
		return inf;

	if (l <= tl && tr <= r)
		return tree[v];

	int mid = (tl + tr) / 2;

	return min(tree_get(v * 2, tl, mid, l, r), tree_get(v * 2 + 1, mid + 1, tr, l, r) );
}

int treeGet (int l, int r)
{
	return tree_get(1, 0, treeSize - 1, l, r);
}

void renewH ()
{
	for (int i = 0; i < hRenewSize; i++)
	{
		int l = hRenew[i].first.first;
		int r = hRenew[i].first.second;
		int strength = hRenew[i].second;

		treeSet(l, r, strength);
	}
}

void solve ()
{
	pSize = 0;
	for (int i = 0; i < n; i++)
	{
		buildPos(w[i], 0);
		buildPos(e[i], 1);
	}
	scalePos();

	genEvents();

	buildTree();

	// counting attacks

	int ans = 0;

	hRenewSize = 0;
	int day = -1;
	for (int i = 0; i < eventsSize; i++)
	{
		int curDay = events[i].first;
		int l = events[i].second.first.first;
		int r = events[i].second.first.second;
		int curStrength = events[i].second.second;

		if (curDay != day)
			renewH();

		day = curDay;

		if (treeGet(l, r) < curStrength)
		{
			ans++;

			hRenew[hRenewSize++] = make_pair(make_pair(l, r), curStrength);
		}
	}

	printf("%d", ans);
}

int main ()
{
	freopen("input.txt", "rt", stdin);
	freopen("output.txt", "wt", stdout);
	int test, t;

	scanf("%d\n", &test);
	for (t = 0; t < test; t++)
	{
		if (t)
			printf("\n");

		printf("Case #%d: ", t + 1);

		// input

		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d%d%d%d%d", &dayFirst[i], &m[i], &w[i], &e[i], &sFirst[i], &dayDelta[i], &distDelta[i], &sDelta[i] );
		}

		// #input

		solve();
	}

	return 0;
}