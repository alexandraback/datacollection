#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <algorithm>
#include <cmath>

#include <cstdarg>

using namespace std;

#define DBG2 1

#define clr(a) memset(a, 0, sizeof(a))
#define fill(a, b) memset(a, b, sizeof(a))

void dbg(char * fmt, ...)
{
#ifdef DBG1
#if	DBG2
	FILE * file = stdout;

	va_list args;
	va_start(args, fmt);
	vfprintf(file, fmt, args);
	va_end(args);

	fflush(file);
#endif
#endif
}

typedef long long ll;
typedef unsigned long long ull;
typedef std::pair<int, int> pii;

struct Car {
	bool lane;
	int v;
	double dist;

	void read()
	{
		char ch;
		scanf(" %c %d %lf", &ch, &v, &dist);
		lane = ch == 'L';
	}

	bool operator < (const Car & c) const
	{
		return dist > c.dist;
	}

	void print()
	{
		dbg("%c %d %.4lf\n", lane ? 'R' : 'L', v, dist);
	}
};

const double INF = 1e100;
const double eps = 1e-8;
const double SIZE_CAR = 5.0;

const int N = 100;
int n;
bool QXX[10][10];
Car c[N];
Car old[N];

bool normalize(bool ZZZ = false)
{
	sort(c, c + n);
	for (int i = 0; i < n; ++i)
	{
		bool laneObgon;
		bool obgon = false;
		bool neObgon = false;
		for (int j = 0; j < n; ++j)
		{
			if (i == j)
				continue;
			if (c[j].dist - SIZE_CAR <= c[i].dist + eps && c[i].dist < c[j].dist + SIZE_CAR - eps && c[i].v > c[j].v)
			{
				if (ZZZ && c[i].lane == c[j].lane)
					return false;
                
                if (c[i].v > c[j].v)
                {
					obgon = true;
					laneObgon = QXX[i][j];
				}
				else if (c[i].v < c[j].v)
				{
					laneObgon = QXX[i][j];
					neObgon = true;
				}
			}
		}
		if (obgon)
			c[i].lane = laneObgon;
		if (neObgon)
			c[i].lane = !laneObgon;
	}
	return true;
}

double solve()
{
	double res = 0;
	vector <double> events;
	events.push_back(0);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
		{
			if (c[i].v == c[j].v)
				continue;
			double curT = (c[i].dist - (c[j].dist + SIZE_CAR)) / (c[j].v - c[i].v);
			if (curT > eps)
				events.push_back(curT);
		}
	sort(events.begin(), events.end());
	for (int ii = 1; ii < int(events.size()); ++ii)
	{
//		dbg("%.10lf\n", events[ii - 1]);
//		for (int i = 0; i < n; ++i)
//			c[i].print();
		if (!normalize())
			return res;

//		dbg("-----\n");
//		for (int i = 0; i < n; ++i)
//			c[i].print();
		if (!normalize(true))
			return res;
		double delta = events[ii] - events[ii - 1];
		res += delta;
		for (int i = 0; i < n; ++i)
			c[i].dist += c[i].v * delta;
	}
	return INF;
}

double solveBrute()
{
	memcpy(old, c, sizeof(c));
	double res = 0;
	int _pow = min(15, n * (n - 1) / 2);
	for (int i = 0; i < (1 << _pow); ++i)
	{
		int k = 0;
		for (int x = 0; x < n; ++x)
			for (int y = x + 1; y < n; ++y)
			{
				QXX[x][y] = QXX[y][x] = i & (1 << k);
				++k;
			}
		memcpy(c, old, sizeof(c));
		res = max(res, solve());
	}
	return res;
}

int main()
{
#ifdef DBG1
	freopen(".in", "r", stdin);
	freopen(".out", "w", stdout);
#endif

	int tt;
	scanf("%d", &tt);
	for (int ii = 1; ii <= tt; ++ii)
	{
		scanf("%d", &n);
		for (int i = 0; i < n; ++i)
			c[i].read();

		double res = solveBrute();
		printf("Case #%d: ", ii);
		if (fabs(res - INF)  < eps)
			printf("Possible\n");
		else
			printf("%.10lf\n", res);
	}

	return 0;
}
