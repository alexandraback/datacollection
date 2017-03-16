#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <stack>
#include <cassert>
#include <cstdio>
#include <stdio.h>
#include <string.h>
#include <ctime>
#include <algorithm>

using namespace std;
typedef long long LL;
#define FOR(k,a,b) for(LL k(a); k < (b); ++k)
#define REP(k,a) for(int k=0; k < (a); ++k)

typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<vector<int> > VVI;
typedef vector<bool> VB;

inline bool is_pal(LL a)
{
	VL t,z;
	t.reserve(15);
	while(a)
	{
		t.push_back(a%10);
		a/=10;
	}
	z=t;
	reverse(z.begin(),z.end());
	return z==t;
}

int main()
{
#ifdef HOME
	freopen ("C-large-1.in","r",stdin);
	freopen ("C-large-1.out","w",stdout);
#endif
	VL v;
	FOR(i,1,1e7+1)
	{
		if(is_pal(i) && is_pal(i*i))
			v.push_back(i*i);
	}
	int T;
	scanf("%d",&T);
	FOR(testcase,1,T+1)
	{
		LL A,B;
		scanf("%lld %lld",&A,&B);
		VL::iterator lit=lower_bound(v.begin(),v.end(),A);
		VL::iterator hit=lower_bound(v.begin(),v.end(),B);
		if(hit!=v.end() && *hit==B)
		{
			++hit;
		}

		int res=distance(lit,hit);
		printf("Case #%d: ",testcase);
		printf("%d\n",res);

	}
	return 0;
} 