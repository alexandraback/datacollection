#define _CRT_SECURE_NO_DEPRECATE
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <string>
#include <string.h>
#include <utility>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <ctime>
#include <queue>
#include <cmath>
#include <deque>
#include <list>
#include <sstream>
#include <bitset>
#include <complex>
#pragma comment(linker, "/STACK:16777216")
#pragma warning(default :4)
#define mp make_pair
#define ll long long
#define ull unsigned long long
#define eps 1e-18
#define INF 1000000001
//#define oo 0x3F3F3F3F
#define oo INF
#define MOD 1000000007
#define cint const int &
#define cll const ll &
#define cull const ull &
#define FOR(i, x) for (int i = 0; i < (int)(x); ++i)
#define CL(x) memset(x, 0, sizeof(x))
#define SVAL(x, y) memset(x, y, sizeof(x))
#define FIN freopen("in.txt", "r", stdin);
#define FOUT freopen("out.txt", "w", stdout);
#define y1 Y1
using namespace std;
typedef vector<int> VINT;
typedef pair<int, int> PII;
typedef complex<double> Cn;
int t, n;
long long a[1000], s[1<<22];
int r1, r2;
bool tr(int msk)
{
	for (int m=1; m<msk; m++)
	{
		int pm=msk^m, sm=pm;
		while (sm>0)
		{
			if (s[m]==s[sm])
			{
				r1=m;
				r2=sm;
				return 1;
			}
			sm=(sm-1)&pm;
		}
	}
	return 0;
}
int main()
{
	//double time=clock();
	//FIN;
	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);

	scanf("%d", &t);
	for (int tst=0; tst<t; tst++)
	{
		scanf("%d", &n);
		for (int i=0; i<n; i++)
			scanf("%lld", &a[i]);
		int msk=1<<n;
		for (int m=0; m<msk; m++)
		{
			ll ts=0;
			for (int i=0, j=1; i<n; i++, j<<=1)
				if (m&j) ts+=a[i];
			s[m]=ts;
		}
		printf("Case #%d:\n", tst+1);
		if (tr(msk-1))
		{
			int ft=0;
			for (int i=0, j=1; i<n; i++, j<<=1)
			{
				if ((r1&j)==0) continue;
				if (ft++) printf(" ");
				printf("%lld", a[i]);
			}
			puts("");
			ft=0;
			for (int i=0, j=1; i<n; i++, j<<=1)
			{
				if ((r2&j)==0) continue;
				if (ft++) printf(" ");
				printf("%lld", a[i]);
			}
			puts("");
		}
		else puts("Impossible");
	}

	//printf("%lf\n", (clock()-time)/CLOCKS_PER_SEC);
	return 0;
}
