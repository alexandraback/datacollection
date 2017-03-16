#include <cstdio>
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <memory.h>
using namespace std;

#define fi first
#define sc second
#define mp make_pair
#define pb push_back
#define ALL(c) (c).begin(), (c).end()
#define RESET(a,b) memset( (a), b, sizeof(a) )
#define ren(a,b,c) for (int a=b; a<c; ++a)
#define red(a,b,c) for (int a=b; a>=c; --a)
#define repi(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)

const double eps = 1e-9;
typedef long long ll;
typedef pair <int,int> pii;

//lintaor1's template

double i[100002];

double f( int, int&, int&, double );
double solve();

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	//-------
	int TT, T=0;
	scanf("%d",&TT);
	while (T<TT)
	{
		printf("Case #%d: %lf\n", ++T, solve() );
	}
	return 0;
}

//----------------------------------------
double solve()
{
	double ret;
	int A, B;
	
	scanf("%d%d",&A,&B);
	ren (x,0,A) scanf("%lf", &i[x]);
	ret = (double)(B+2);
	
	++B;
	ret = min( ret, f( 0, A, B, 1.0 ) );
	
	return ret;
}

double f( int a, int &A, int &B, double ch )
{
	double ret = B * (2.0 - ch) + A - 2*a;
	if (a<A) ret = min( ret, f( a+1, A, B, ch*i[a] ) );
	return ret;
}
