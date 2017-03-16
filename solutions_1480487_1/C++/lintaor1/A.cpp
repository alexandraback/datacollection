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

void solve( const int& );

int main()
{
	freopen("A-large.in", "r", stdin);
	freopen("A-large.out", "w", stdout);
	//----
	int TT;
	scanf("%d",&TT); ++TT;
	ren (T,1,TT) solve( T );
	return 0;
}


//-------------------------------
void solve( const int &T )
{
	int n, i[207];
	double a=1000000.0, b=0.0, tot=0.0;
	
	scanf("%d",&n);
	ren (x,0,n) scanf("%d",&i[x]), a=min( a,(double)i[x] ), b+=i[x], tot+=i[x];
	
	while (abs( a-b ) > eps)
	{
		double m = (a+b)/2.0;
		bool pos = true;
		//printf("%lf %lf %lf\n", a, b, m);
		
		//---
		double tmp = tot;
		ren (x,0,n) if (tmp < m-i[x])
		{
			pos = false;
			break;
		}
		else
		{
			if (m > (double)i[x]) tmp -= m-i[x];
		}
		//---
		
		if (pos) a=m; else b=m;
	}
	
	//-------
	printf("Case #%d:", T);
	ren (x,0,n) printf(" %lf", max( 0.0, (b-i[x])*100.0/tot ) );
	printf("\n");
	//printf("%lf\n", b);
}
