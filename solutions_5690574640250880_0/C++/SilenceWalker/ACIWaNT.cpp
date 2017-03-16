#include<iostream>
#include<queue>
#include<cstring>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<list>
using namespace std;
const int maxn = 50 + 5;
int n, m, k;
const int Move[2][8] = { { -1, -1, 0, 1, 1, 1, 0, -1 }, { 0, 1, 1, 1, 0, -1, -1, -1 } };
inline bool inRange(int r, int c)  { return 0 <= r&&r < n && 0 <= c&&c < m; }
inline int getx(int r, int c) { return r*m + c; }
inline int row(int x) { return x / m; }
inline int col(int x) { return x%m; }
char out[maxn][maxn];
int deg[maxn][maxn];

struct Mine
{
	int d;
	int x;
	bool operator<(const Mine&m) const
	{
		if (d == m.d) return x < m.x;
		return d < m.d;
	}
};

struct State
{
	int x;
	int d;
	bool operator<(const State&st) const
	{
		return d>st.d;
	}
	State(int x, int d)
		:x(x), d(d)  { }
};

int vis[maxn][maxn];

void output()
{
	puts("------------------");
	for (int i = 0; i < n; ++i)
		printf("%s\n", out[i]);
	puts("-----------------");
}

void modify(State&st)
{
	int x = st.x;
	st.d = 0;
	int r = row(x), c = col(x);
	for (int i = 0; i < 8; ++i)
	{
		int rr = r + Move[0][i];
		int cc = c + Move[1][i];
		if (!inRange(rr, cc) || vis[rr][cc]) continue;
		++st.d;
	}
}

typedef list<State>::iterator Iter;
bool solve()
{
	out[0][0] = 'c';/*
	for (int i = 0; i<n; ++i)
	for (int j = 0; j < m; ++j)
		deg[i][j] = 8;
	for (int j = 0; j < m; ++j) deg[0][j]-=3, deg[n - 1][j]-=3;
	for (int i = 0; i < n; ++i) deg[i][0]-=3, deg[i][m - 1]-=3;
	++deg[0][0], ++deg[n - 1][m - 1], ++deg[n - 1][0], ++deg[0][m - 1];*/
	list<State> v;
	v.push_back(State(0, 3));
	k = n*m - k;
	--k;
	memset(vis, 0, sizeof(vis));
	while (v.size() && k>0)
	{
		Iter z = v.end();
		for (Iter p = v.begin(); p != v.end(); )
		{
			modify(*p);
			if (p->d == 0) { v.erase(p++); continue; }
			if (k % 2 == p->d % 2) {
				if (z == v.end())  z = p;
				else if (z->d > p->d) z = p;
			}
			++p;
		}
		if (z == v.end())
		{
			z = v.begin();
			for (Iter p = v.begin(); p != v.end();++p)
			if (z->d > p->d) z = p;
		}
		int x = z->x;
		v.erase(z);
		
		int r = row(x), c = col(x);
		vis[r][c] = true;
		for (int i = 0; i < 8; ++i)
		{
			int rr = r + Move[0][i];
			int cc = c + Move[1][i];
			if (!inRange(rr, cc) || vis[rr][cc]) continue;
			vis[rr][cc] = true;
			out[rr][cc] = '.';
			--k;
			v.push_back(State(getx(rr, cc),0));
		}
		//output();
	}
	return k == 0;
}

int main()
{
	freopen("input.in", "r", stdin);
	freopen("output.out", "w", stdout);
	int T; cin >> T;
	int c = 0;
	while (T--)
	{
		scanf("%d%d%d", &n, &m, &k);
		memset(out, 0, sizeof(out));
		for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			out[i][j] = '*';
		++c;
		printf("Case #%d:\n", c);
		if (!solve()) printf("Impossible\n");
		else
		{
			for (int i = 0; i < n; ++i)
				printf("%s\n", out[i]);
		}
	}
}