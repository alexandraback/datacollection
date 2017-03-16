#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int maxn = 110, maxs = 1100;

int n;
int datn[maxn], datd[maxn], date[maxn], datw[maxn], dats[maxn], datdd[maxn], datdp[maxn], datds[maxn];

void init()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d%d%d%d%d%d%d%d", &datd[i], &datn[i], &datw[i], &date[i], &dats[i], &datdd[i], &datdp[i], &datds[i]);
}

struct event
{
	event() {}
	event(int _d, int _l, int _r, int _s) : d(_d), l(_l), r(_r), s(_s) {}
	int d, l, r, s;
};

bool comp(const event& a, const event& b)
{
	return a.d < b.d;
}

void work()
{
	static event eves[maxs];
	int ecnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < datn[i]; j++)
			eves[ecnt++] = event(datd[i] + datdd[i] * j, datw[i] + datdp[i] * j, date[i] + datdp[i] * j, dats[i] + datds[i] * j);
	}
	
	sort(eves, eves + ecnt, comp);
	
	static int now[maxs], temp[maxs];
	for (int i = -1000; i <= 1000; i++) now[i] = temp[i] = 0;
	
	int ret = 0;
	for (int i = 0; i < ecnt; i++)
	{
		bool found = false;
		for (int j = eves[i].l; j < eves[i].r; j++)
		{
			temp[j] = max(temp[j], eves[i].s);
			if (now[j] < eves[i].s) found = true;
		}
		
		ret += found;
		
		if (i > ecnt - 1 || eves[i].d != eves[i + 1].d)
		{
			for (int j = -210; j <= 210; j++)
			{
				now[j] = max(now[j], temp[j]);
				temp[j] = 0;
			}
		}
	}
	
	printf("%d\n", ret);
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
