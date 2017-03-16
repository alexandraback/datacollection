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

pii i[1024];

struct bunga
{
	bool operator()( const pii &a, const pii &b )
	{
		if (a.fi != b.fi) return a.fi > b.fi;
		return i[a.sc].sc < i[b.sc].sc;
	}
};

int ud[1024];
int solve();

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("B-small", "w", stdout);
	//-------
	int TT, T=0, res;
	scanf("%d",&TT);
	while (T<TT)
	{
		res = solve();
		printf("Case #%d: ", ++T );
		if (res == -1) printf("Too Bad\n"); else printf("%d\n", res);
	}
	return 0;
}


//----------------
int solve()
{
	int ret = 0, n, cur = 0;
	priority_queue < pii, vector< pii >, bunga > s1, s2;
	RESET( ud,0 );
	
	scanf("%d",&n);
	ren (x,0,n)
	{
		scanf("%d%d", &i[x].fi, &i[x].sc);
		s1.push( mp( i[x].fi,x ) );
		s2.push( mp( i[x].sc,x ) );
	}
	
	/*
	while (!s1.empty())
	{
		printf("%d %d\n", s1.top().fi, s1.top().sc);
		s1.pop();
	}
	*/
	
	while (!s2.empty())
	{
		if (s2.top().fi <= cur)
		{
			pii tmp = s2.top(); s2.pop();
			++ret;
			cur += 2-ud[ tmp.sc ];
			ud[ tmp.sc ] = 2;
			//printf("2: %d (%d)\n", tmp.sc, cur);
		}
		else if (!s1.empty() && s1.top().fi <= cur)
		{
			pii tmp = s1.top(); s1.pop();
			if (!ud[tmp.sc])
			{
				++ret;
				++cur;
				ud[tmp.sc] = 1;
				//printf("1: %d (%d)\n", tmp.sc, cur);
			}
		}
		else break;
	}
	
	return (s2.empty() ? ret : -1 );
}
