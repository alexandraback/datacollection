#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <ctime>
#include <cctype>
#include <cassert>

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)

using namespace std;

typedef long long LL;

const int oo = 0x3f3f3f3f;

const int maxn = 10000;

int f[4][4] = {{0, 1, 2, 3}, {1, 0, 3, 2}, {2, 3, 0, 1}, {3, 2, 1, 0}};
int sign[4][4] = {{1, 1, 1, 1}, {1, -1, 1, -1}, {1, -1, -1, 1}, {1, 1, -1, -1}};

int n;
LL k;

char s[maxn + 5];

char id[256];

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
#endif
	id['1'] = 0, id['i'] = 1, id['j'] = 2, id['k'] = 3;
	static int T;
	scanf("%d", &T);
	for (int Case = 1; Case <= T; ++Case)
	{
		printf("Case #%d: ", Case);
		scanf("%d%I64d", &n, &k);
		scanf("%s", s);
		int cur = 0, si = 1;
		REP(i, 0, n) 
		{
			int tmp = id[(int)s[i]];
			si *= sign[cur][tmp];
			cur = f[cur][tmp];
		}
		int tmp = cur, tmp0 = si;
		int K = k % 8;
		REP(i, 1, K) si *= sign[cur][tmp] * tmp0, cur = f[cur][tmp];
		if (cur != 0 || si != -1)
		{
			printf("NO\n");
			continue;
		}
		cur = 0, si = 1;
		bool flag = 0;
		REP(j, 0, (int)min(k, 8LL))
		{
			REP(i, 0, n) 
			{
				int tmp = id[(int)s[i]];
				si *= sign[cur][tmp];
				cur = f[cur][tmp];
				if (flag == 0 && (cur == 1 && si == 1)) flag = 1;
				if (flag == 1 && (cur == 3 && si == 1))
				{
					printf("YES\n");
					goto lyc;
				}
			}
		}
		printf("NO\n");
lyc:;
	}
	return 0;
}
