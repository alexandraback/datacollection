#include "bits/stdc++.h"
using namespace std;

typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef pair<int,int> PII;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define FOREACH(it,v) for(decltype((v).begin())it=(v).begin();it!=(v).end();++it)
#define ST first
#define ND second
#define MP make_pair
#define PB push_back
#define ALL(v) (v).begin(),(v).end()
#define SIZE(x) ((int)(x).size())
#define DBG(x) cerr<<">> "<<#x<<" = "<<x<<endl;
const int MX = 1e6 + 5;
const int INF = 1e9 + 5;

int cases, Res, r, c, w;

int suf(int x, int y)
{
	if (x % y == 0)
		return x / y;
	return x / y + 1;
}

int main()
{
//	ios_base::sync_with_stdio(false);	
	scanf("%d", &cases); for (int ca = 1; ca <= cases; ++ ca)
	{	
		scanf("%d%d%d", &r, &c, &w);

		if ( w == 1 )
			Res = r * c;
		else
		{
			if ( w > r )
				Res = suf(r * c, w) + w - 1;
			else
				Res = suf(r * c, w) + w;
		}

		printf("Case #%d: %d\n", ca, Res);
	}


	return 0;
}
