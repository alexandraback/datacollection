#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

// solution for the easy case
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

const int W = 40;
const double eps = 1e-9;

int R, C, D;
int selfR, selfC;

int GetExpand()
{
	int divisor = min(R, C);
	return (D + divisor - 1) / divisor + 1;
}

double getMapping(double from, double bound, int repeat)
{
	if (repeat > 0 && repeat % 2 == 1 || repeat < 0 && -repeat % 2 == 0) from = bound - from;
	if (repeat < 0) from = -from;
	if (repeat < 0) ++repeat;
	return from + repeat * bound;
}

pdd getWorldPosition(int wr, int wc)
{
	return make_pair(getMapping(selfR + 0.5, R, wr), getMapping(selfC + 0.5, C, wc));
}

double dist(pdd point)
{
	double oy = selfR + 0.5;
	double ox = selfC + 0.5;
	double dy = point.first - oy, dx = point.second - ox;

	return sqrt(dy * dy + dx * dx);
}

bool isZero(double d)
{
	return fabs(d) <= eps;
}

double cross(pdd a, pdd b, pdd c)
{
	double Y1 = b.first - a.first, X1 = b.second - a.second;
	double Y2 = c.first - a.first, X2 = c.second - a.second;
	return X1 * Y2 - X2 * Y1;
}

double dot(pdd a, pdd b, pdd c)
{
	double Y1 = b.first - a.first, X1 = b.second - a.second;
	double Y2 = c.first - a.first, X2 = c.second - a.second;

	return X1 * X2 + Y1 * Y2;
}

bool inBetween(pdd mid, pdd far)
{
	pdd near = make_pair(selfR + 0.5, selfC + 0.5);

	if (!isZero(cross(near, mid, far))) return false;
	if (dot(near, mid, far) < -eps) return false;
	if (dot(far, mid, near) < -eps) return false;
	return true;
}

void solve()
{
	int expand = GetExpand();

	int answer = 0;
	for (int r = -expand; r <= expand; r++)
	{
		for (int c = -expand; c <= expand; c++)
		{
			//printf("r=%d c=%d\n", r, c);
			if (r == 0 && c == 0) continue;
			pdd pos = getWorldPosition(r, c);
			double dst = dist(pos);
			if (dst > D + eps) continue;

			// check whether other reflected self image lies in the same line
			bool fnd = false;
			int lowerR = min(r, 0), lowerC = min(c, 0);
			int upperR = max(r, 0), upperC = max(c, 0);
			for (int i = lowerR; i <= upperR; i++) {
				for (int j = lowerC; j <= upperC; j++) {
					if (i == 0 && j == 0) continue;
					if (i == r && j == c) continue;
					pdd point = getWorldPosition(i, j);
					if (inBetween(point, pos))
					{
						//printf("fnd r=%d c=%d i=%d j=%d\n", r, c, i, j);
						fnd = true;
						break;
					}
				}
				if (fnd) break;
			}

			answer += !fnd;
		}
	}

	printf("%d\n", answer);
}

int main()
{
	int T;
	scanf("%d", &T);
	for (int t = 0; t < T; t++)
	{
		printf("Case #%d: ", t + 1);
		scanf("%d %d %d\n", &R, &C, &D);
		for (int r = 0; r < R; r++)
		{
			char buf[W];
			fgets(buf, sizeof buf, stdin);
			int len = strlen(buf);
			for (int i = 0; i < len; i++)
			{
				if (buf[i] == 'X')
				{
					selfR = r - 1;
					selfC = i - 1;
					break;
				}
			}
		}
		R -= 2;
		C -= 2;
		solve();
	}
}