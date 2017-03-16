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

int solve( const int&, int, int );

int main()
{
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("Bs0.out", "w", stdout);
	
	int TT;
	scanf("%d",&TT);
	ren (T,0,TT)
	{
		int n, s, p;
		scanf("%d%d%d",&n,&s,&p);
		printf("Case #%d: %d\n", T+1, solve( n, s, p));
	}
	return 0;
}

//------
int solve( const int &n, int s, int p )
{
	if (p==0)
	{
		ren (x,0,n) scanf("%*d");
		return n;
	}
	else if (p==1)
	{
		int tmp, ret = 0;
		ren (x,0,n)
		{
			scanf("%d", &tmp);
			if (tmp>0) ++ret;
		}
		return ret;
	}
	
	//--- else ---
	int ret = 0, tmp;
	
	p = (p-1) * 3;
	ren (x,0,n)
	{
		scanf("%d", &tmp);
		if (tmp > p) ++ret;
			else if ((s>0) && (tmp > p-2)) ++ret, --s;
	}
	
	return ret;
}
