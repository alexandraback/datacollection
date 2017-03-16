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

bool ud[10000002];
ll solve( const int&, const int& );

int main()
{
	freopen("C-large.in", "r", stdin);
	freopen("Cl.out", "w", stdout);
	
	int TT;
	scanf("%d",&TT);
	ren (T,0,TT)
	{
		int a, b;
		scanf("%d%d",&a,&b); ++b;
		printf("Case #%d: %I64d\n", T+1, solve( a,b ));
		fflush(stdout);
	}
	return 0;
}

ll solve( const int &a, const int &b )
{
	ll ret = 0LL;
	int len, tmp, zro=1, cnt;
	RESET( ud,0 );
	
	tmp = a;
	do ++len, zro*=10; while (tmp/=10);
	
	ren (x,a,b) if (!ud[x])
	{
		cnt = 0;
		tmp = x;
		
		//printf("%d:",x);
		while (!ud[tmp])
		{
			if ((a<=tmp) && (tmp<b))
			{
				++cnt;
				ud[tmp] = true;
			}
			tmp = (tmp + (tmp%10)*zro) / 10;
		}
		//printf("\n");
		
		ret += (ll)cnt * (cnt-1LL) / 2LL;
	}
	
	return ret;
}
