#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define N 15
#define M 10005
#define delta 5000
#define inf 0x3f3f3f3f
struct data
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
} tribe[N];
struct Strengthen
{
		int w, e, s;
		Strengthen(int ww, int ee, int ss) :
			w(ww), e(ee), s(ss)
		{
		}
		Strengthen()
		{
		}
} stk[N];
int n;
int ans;
int wall[M];
int top;
bool judge()
{
	for (int i = 0; i < n; i++)
		if (tribe[i].cnt < tribe[i].tot)
			return true;
	return false;
}
void next(data &a)
{
	a.strength += a.delta_strength;
	a.day += a.delta_day;
	a.w += a.move;
	a.e += a.move;
	a.cnt++;
}
bool job(Strengthen a)
{
	bool ret = false;
	for (int i = a.w; i < a.e; i++)
		if (wall[i + delta] < a.s)
			ret = true;
	return ret;
}
void work(Strengthen a)
{
	for (int i = a.w; i < a.e; i++)
		wall[i + delta] = max(a.s, wall[i + delta]);
}
int main()
{
	freopen("data.in", "r", stdin);
	freopen("data.out", "w", stdout);
	int t;
	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		printf("Case #%d: ", i + 1);
		scanf("%d", &n);
		for (int i = 0; i < n; i++)
		{
			scanf("%d%d%d%d", &tribe[i].day, &tribe[i].tot, &tribe[i].w,
			        &tribe[i].e);
			tribe[i].cnt = 0;
			scanf("%d", &tribe[i].strength);
			scanf("%d%d%d", &tribe[i].delta_day, &tribe[i].move,
			        &tribe[i].delta_strength);
		}
		memset(wall, 0, sizeof(wall));
		ans = 0;
		top = 0;
		while (judge())
		{
			int day = inf;
			for (int i = 0; i < n; i++)
				if (tribe[i].cnt < tribe[i].tot)
					day = min(day, tribe[i].day);
			for (int i = 0; i < n; i++)
				if (tribe[i].cnt < tribe[i].tot && day == tribe[i].day)
				{
					stk[top++] = Strengthen(tribe[i].w, tribe[i].e,
					        tribe[i].strength);
					if (job(stk[top - 1]))
						ans++;
					next(tribe[i]);
				}
			while (top > 0)
				work(stk[--top]);
		}
		cout<<ans<<endl;
	}

	return 0;
}

