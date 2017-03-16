#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;

#define maxn 15
#define maxm 10005
#define delta 5000
#define inf 0x3f3f3f3f

struct Tribe
{
	int day;
	int tot;
	int w;
	int e;
	int strength;
	int delta_day;
	int move;
	int cnt;
	int delta_strength;
}tribe[maxn];

struct Strengthen
{
	int w, e, s;
	Strengthen(int ww, int ee, int ss): w(ww), e(ee), s(ss)
	{}
	Strengthen()
	{}
}stk[maxn];

int n;
int ans;
int wall[maxm];
int top;

void input()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d%d%d%d", &tribe[i].day, &tribe[i].tot, &tribe[i].w, &tribe[i].e);
		tribe[i].cnt = 0;
		scanf("%d", &tribe[i].strength);
		scanf("%d%d%d", &tribe[i].delta_day, &tribe[i].move, &tribe[i].delta_strength);
	}
}

bool check()
{
	for (int i = 0; i < n; i++)
		if (tribe[i].cnt < tribe[i].tot)
			return true;
	return false;
}

int min_day()
{
	int ret = inf;
	for (int i = 0; i < n; i++)
		if (tribe[i].cnt < tribe[i].tot)
			ret = min(ret, tribe[i].day);
	return ret;
}

void do_next(Tribe &a)
{
	a.strength += a.delta_strength;
	a.day += a.delta_day;
	a.w += a.move;
	a.e += a.move;
	a.cnt++;
}

bool attack(Strengthen a)
{
	bool ret = false;
	for (int i = a.w; i < a.e; i++)
		if (wall[i + delta] < a.s)
			ret = true;
	return ret;
}


void make(Strengthen a)
{
	for (int i = a.w; i < a.e; i++)
		wall[i + delta] = max(a.s, wall[i + delta]);
}

void work()
{
	ans = 0;
	top = 0;
	while (check())
	{
		int day = min_day();
		for (int i = 0; i < n; i++)
			if (tribe[i].cnt < tribe[i].tot && day == tribe[i].day)
			{
				stk[top++] = Strengthen(tribe[i].w, tribe[i].e, tribe[i].strength);
				if (attack(stk[top - 1]))
					ans++;
				do_next(tribe[i]);
			}
		while (top > 0)
			make(stk[--top]);
	}
}

int main()
{
//	freopen("t.txt", "r", stdin);
//	freopen("y.txt", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		input();
		memset(wall, 0, sizeof(wall));
		work();
		printf("%d\n", ans);
	}
	return 0;
}
