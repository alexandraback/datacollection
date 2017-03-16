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
int n, t, s[1000], x;
bool ok(double pp, int i)
{
	double r=s[i]+x*pp;
	double sp=pp;
	for (int j=0; j<n; j++)
	{
		if (j==i) continue;
		if (s[j]+eps>r) continue;
		sp+=(r-s[j])/x;
	}
	if (sp<1+eps) return 1;
	return 0;
}
double el(int i)
{
	double l=0, r=1;
	FOR(qqq, 1000)
	{
		double m=(l+r)/2;
		if (ok(m, i))
			l=m;
		else
			r=m;
	}
	return l*100;
}
int main()
{
	//double time=clock();
	//FIN;
	freopen("A.in", "r", stdin);
	freopen("A.out", "w", stdout);

	scanf("%d", &t);
	for (int tst=0; tst<t; tst++)
	{
		scanf("%d", &n); x=0;
		for (int i=0; i<n; i++) scanf("%d", &s[i]), x+=s[i];
		printf("Case #%d:", tst+1);
		for (int i=0; i<n; i++) printf(" %.9lf", el(i));
		puts("");
	}

	//printf("%lf\n", (clock()-time)/CLOCKS_PER_SEC);
	return 0;
}
