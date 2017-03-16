#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <cmath>

using namespace std;

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) 42
#endif

const double eps = 1e-12;
const int N = (int)1e5 + 100;

bool Eq(double a, double b)
{
	return fabs(a - b) < eps;
}

bool Ls(double a, double b)
{
	return a < b && !Eq(a, b);
}

bool LsEq(double a, double b)
{
	return a < b || Eq(a, b);
}

bool Gr(double a, double b)
{
	return a > b && !Eq(a, b);
}

struct Hiker
{
	double start;
	double speed;
	Hiker () {}
	Hiker (double _start, double _speed) : start(_start), speed(_speed) {}
};

Hiker hikers[N];
int cntH = 0;

double getPos(int id, double curTime)
{
	double pos = hikers[id].start + hikers[id].speed * curTime;
	while (Gr(pos, 360))
		pos -= 360;
	return pos;
}

int getNext(double curA, double curTime)
{
	int id = -1;
	for (int i = 0; i < cntH; i++)
	{
		double hA = getPos(i, curTime);
		if (Gr(hA, curA) && (id == -1 || Ls(hA, getPos(id, curTime))))
			id = i;
	}
	return id;
}

double getTimeCollision(int id, double curTime)
{
	double tme = 1e18;
	for (int i = 0; i < cntH; i++)
	{
		if (i == id) continue;
		double s = hikers[i].speed - hikers[id].speed;
		if (LsEq(s, 0))
			continue;
		double p1 = getPos(i, curTime);
		double p2 = getPos(id, curTime);
		double delta = p2 - p1;
		if (Eq(delta, 0))
		{
			tme = min(tme, 360 / fabs(s));
			continue;
		}
		if (Ls(delta, 0))
			delta += 360;
		if (Gr(s, 0))
			tme = min(tme, delta / s);
		else
			tme = min(tme, (360 - delta) / fabs(s));
	}
	return tme;
}

int getCountLike(int id)
{
	int cnt = 0;
	for (int i = 0; i < cntH; i++)
	{
		if (Eq(hikers[i].start, hikers[id].start) && Eq(hikers[i].speed, hikers[id].speed))
			cnt++;
	}
	return cnt;
}

const double NORM = 1;

void solve()
{
	cntH = 0;
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		int d, sz, tme;
		scanf("%d%d%d", &d, &sz, &tme);
		for (int s = 0; s < sz; s++)
			hikers[cntH++] = Hiker((double)d, NORM * 360. / (tme + s));
	}
	int answer = 0;
	double cur = 0;
	double curTime = 0;
	while (Ls(cur, 360))
	{
		int nxt = getNext(cur, curTime);
		if (nxt == -1)
			break;
		double time1 = (360 - getPos(nxt, curTime)) / hikers[nxt].speed;
		double time2 = getTimeCollision(nxt, curTime);
		if (Ls(time1, time2))
			break;
		else if (Eq(time1, time2))
		{
			answer += getCountLike(nxt);
			break;
		}
		else
		{
			cur = getPos(nxt, time2);
			answer += getCountLike(nxt);
			curTime = time2;
		}
	}
	printf("%d\n", answer);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		printf("Case #%d: ", i);
		solve();
	}
	return 0;
}
