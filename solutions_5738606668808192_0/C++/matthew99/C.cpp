#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = (a), _end_ = (b); i < _end_; ++i)
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define mp make_pair
#define x first
#define y second
#define pb push_back
#define SZ(x) (int((x).size()))
#define ALL(x) (x).begin(), (x).end()

template<typename T> inline bool chkmin(T &a, const T &b) { return a > b ? a = b, 1 : 0; }
template<typename T> inline bool chkmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

typedef long long LL;

const int oo = 0x3f3f3f3f;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	printf("Case #1:\n");
	scanf("%*d");
	int n, J;
	scanf("%d%d", &n, &J);
	int now[100];
	REP(i, 0, J)
	{
		memset(now, 0, sizeof now);
		now[n - 2] = now[0] = 1;
		int u = i;
		int cur = 2;
		while (u)
		{
			now[cur] = u & 1;
			u >>= 1, cur += 2;
		}
		for (int j = n - 2; j >= 0; --j) now[j + 1] |= now[j];
		for (int j = n - 1; j >= 0; --j) printf("%d", now[j]);
		REP(j, 2, 11) printf(" %d", j + 1);
		printf("\n");
	}
	return 0;
}
