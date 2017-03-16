#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<vector>
#include<algorithm>
#include<map>
#include<iostream>

using namespace std;

const int maxn = 60;

int T;
int n;

double ret;
int pos[maxn];
double s[maxn], p[maxn];

struct collisions
{
	double t;
	int u, v;
};
collisions a[3000];
int total;

void init()
{
	scanf("%d\n", &n);
	memset(s,0,sizeof(s));
	memset(p,0,sizeof(p));
	for (int i=0; i<n; i++) {
		char c;
		scanf("%c%lf%lf\n", &c, &s[i], &p[i]);
		if (c=='L') pos[i] = 0;
		else pos[i] = 1;
	}
	ret = 0;
	total = 0;
	memset(a, 0, sizeof(a));
}

bool empty(int po, double st, double ed, double t)
{
	for (int i=0; i<n; i++)
		if (pos[i]==po &&
			((st<=p[i]+s[i]*t && st>p[i]+s[i]*t-5) ||
			(ed<p[i]+s[i]*t && ed>=p[i]+s[i]*t-5)))
			return false;
	return true;
}

const double zero = 1e-8;

void dfs(int k)
{
	if (k>=total)
	{
		ret = 1e20;
		return;
	}
	if (a[k].t>ret)
		ret = a[k].t;
	if (ret >= 1e20-1e-8)
		return;

	int u = a[k].u, v = a[k].v;
	if (pos[u] != pos[v])
		dfs(k+1);
	else
	{
		if (empty(1-pos[u], p[u]+s[u]*a[k].t, p[u]+s[u]*a[k].t-5, a[k].t) &&
			empty(1-pos[u], p[u]+s[u]*(a[k].t+zero), p[u]+s[u]*(a[k].t+zero)-5, a[k].t+zero))
		{
			pos[u] = 1-pos[u];
			dfs(k+1);
			pos[u] = 1-pos[u];
		}
		if (empty(1-pos[u], p[v]+s[v]*(a[k].t+zero), p[v]+s[v]*(a[k].t+zero)-5, a[k].t+zero))
		{
			pos[v] = 1-pos[v];
			dfs(k+1);
			pos[v] = 1-pos[v];
		}
	}
}

void work()
{
	for (int i=0; i<n; i++)
		for (int j=0; j<n; j++)
			if (s[i] > s[j] && p[i] < p[j])
			{
				a[total].u = i;
				a[total].v = j;
				a[total].t = (p[j] - 5 - p[i]) / (s[i] - s[j]);
				total++;
			}
	for (int i=0; i<total; i++)
		for (int j=i; j<total; j++)
			if (a[j].t < a[i].t)
			{
				double t = a[i].t; a[i].t = a[j].t; a[j].t = t;
				int tt = a[i].u; a[i].u =a[j].u; a[j].u = tt;
				tt = a[i].v; a[i].v = a[j].v; a[j].v = tt;
			}
	dfs(0);
}

int main()
{
	//freopen("C:/Users/yaoyao/Downloads/in.txt", "r", stdin);
	freopen("C:/Users/yaoyao/Downloads/C-small-attempt4.in", "r", stdin);
	freopen("D:/workspace/Topcoder/Algorithm/Algorithm/out.txt", "w", stdout);
	scanf("%d", &T);
	for (int i=1; i<=T; i++)
	{
		init();
		work();
		if (ret == 1e20)
			printf("Case #%d: Possible\n", i);
		else
			printf("Case #%d: %.5lf\n", i, ret);
	}
}