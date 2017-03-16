#include <bits/stdc++.h>
using namespace std;

#define INIT(c,v) memset(c,v,sizeof(c))
#define REP(a,b,c) for (int a=b, _c=c; a<_c; ++a)
#define RED(a,b,c) for (int a=b, _c=c; a>=_c; --a)

#define PB push_back
#define MP make_pair
#define fi first
#define sc second

typedef long long ll;
typedef pair<ll,ll> puu;
typedef pair<int,int> pii;
typedef pair<int,char> pic;

#define _MULTI_TC_
// =========================================== //
void solve(int);
int main()
{
#ifdef _MULTI_TC_
	int TC;
	scanf("%d", &TC);
	REP(tc,1,TC+1) solve(tc);
#else
	solve(0);
#endif
	return 0;
}
// =========================================== //


void solve(int tc) {
	int b;
	ll m;
	scanf("%d%I64d", &b, &m);
	if (b==2) // special case
	{
		if (m>1LL || m<0LL)
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);
		}
		else
		{
			printf("Case #%d: POSSIBLE\n", tc);
			printf("0%d\n00\n", (m?1:0));
		}
	}
	else
	{
		if ((1LL<<(b-2)) < m)
		{
			printf("Case #%d: IMPOSSIBLE\n", tc);
		}
		else
		{
			printf("Case #%d: POSSIBLE\n", tc);
			if ((1LL<<(b-2)) == m)
			{
				REP(x,0,b) printf("%d",(x?1:0));
				printf("\n");
			}
			else
			{
				printf("0");
				RED(x,b-3,0) printf("%d", (((1LL<<x)&m)?1:0) );
				printf("0\n");
			}

			REP(x,1,b-1)
			{
				printf("0");
				REP(y,1,b-1) printf("%d", ((y>x)?1:0) );
				printf("1\n");
			}
			REP(y,0,b) printf("0"); printf("\n");
		}
	}
}