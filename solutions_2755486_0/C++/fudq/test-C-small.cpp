/*
 * test.cpp
 *
 *  Created on: 2013-05-12
 *      Author: fudq
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <ctime>
#include <iostream>
#include <algorithm>
#include <queue>
#include <set>
#include <map>
#include <stack>
#include <string>
#include <vector>
#include <deque>
#include <list>
#include <functional>
#include <numeric>
#include <cctype>
using namespace std;
#define maxn 15
#define maxm 10005
#define tmp 5000
#define inf 0x7fffffff
struct Tribe {
	int day,tot,w,e,strength,tmp_day,move,cnt,tmp_strength;
}tri[maxn];
struct Strengthen {
	int w, e, s;
	Strengthen(int ww, int ee, int ss) :
		w(ww), e(ee), s(ss) {
	}
	Strengthen() {
	}
}S[maxn];
int n,ans,top;
int GW[maxm];

bool jud()
{
	for (int i = 0; i < n; i++)
		if (tri[i].cnt < tri[i].tot)
			return true;
	return false;
}

int min_day()
{
	int ret = inf;
	for (int i = 0; i < n; i++)
		if (tri[i].cnt < tri[i].tot)
			ret = min(ret, tri[i].day);
	return ret;
}

void do_next(Tribe &a)
{
	a.strength += a.tmp_strength;
	a.day += a.tmp_day;
	a.w += a.move;
	a.e += a.move;
	a.cnt++;
}

bool attack(Strengthen a)
{
	bool ret = false;
	for (int i = a.w; i < a.e; i++)
		if (GW[i + tmp] < a.s)
			ret = true;
	return ret;
}

void make(Strengthen a)
{
	for (int i = a.w; i < a.e; i++)
		GW[i + tmp] = max(a.s, GW[i + tmp]);
}

void fun()
{
	ans = 0;
	top = 0;
	while (jud())
	{
		int day = min_day();
		for (int i = 0; i < n; i++)
			if (tri[i].cnt < tri[i].tot && day == tri[i].day)
			{
				S[top++] = Strengthen(tri[i].w, tri[i].e,tri[i].strength);
				if (attack(S[top - 1]))
					ans++;
				do_next(tri[i]);
			}
		while(top > 0)
			make(S[--top]);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("testin.txt","r",stdin);
    freopen("testout.txt","w",stdout);
#endif
	int T,cas=1;
	scanf("%d", &T);
	while(T--)
	{
		printf("Case #%d: ", cas++);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &tri[i].day, &tri[i].tot, &tri[i].w,&tri[i].e);
			tri[i].cnt = 0;
			scanf("%d", &tri[i].strength);
			scanf("%d%d%d", &tri[i].tmp_day, &tri[i].move,&tri[i].tmp_strength);
		}
		memset(GW, 0, sizeof(GW));
		fun();
		printf("%d\n", ans);
	}
	return 0;
}
