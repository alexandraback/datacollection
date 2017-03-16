#include <iostream>
#include <set>
#include <string>
#include <iterator>
#include <vector>
#include <ctime>
#include <map>
#include <memory.h>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for(int i=(a), _b(b); i<_b; i++)
#define FORD(i, b, a) for(int i=(b)-1, _a(a); i>=_a; i--)
#define HAS(a, b) ((a).find(b) != (a).end())
#define SZ(a) (int)(a).size()
#define FILL(a, b) memset(a, b, sizeof(a))

typedef long long LL;
typedef vector<int> VI;
typedef pair<int, int> PII;
typedef pair<int, LL> PIL;

char maze[44][44];
int stx, sty;

int gcd(int a, int b) {
	return !b?a:gcd(b, a%b);
}

int main()
{
#ifdef ALMAG_LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int tc, ind=0; scanf("%d", &tc);

	while (tc --> 0)
	{
		int n, m, d; scanf("%d %d %d", &n, &m, &d);
		FOR(i, 0, n) scanf("%s", maze[i]);

		FOR(i, 0, n)
			FOR(j, 0, m)
				if (maze[i][j]=='X')
					stx=j, sty=i;

		set<PII> ss;

		FOR(x, -51, +52)
			FOR(y, -51, +52)
			{
				if (!x && !y) continue;
				int dx = (m-2)*(abs(x)-abs(x)%2) + (abs(x)%2)*((x<0)?(2*stx-1):(2*(m-stx-1)-1));
				int dy = (n-2)*(abs(y)-abs(y)%2) + (abs(y)%2)*((y>0)?(2*sty-1):(2*(n-sty-1)-1));
				if (dx*dx+dy*dy>d*d) continue;
				int g = gcd(abs(dx), abs(dy));
				if (x<0) dx=-dx; if (y<0) dy=-dy;

				ss.insert(make_pair(dx/g, dy/g));
			}

		printf("Case #%d: %d\n", ++ind, SZ(ss));
	}

    return 0;
}
