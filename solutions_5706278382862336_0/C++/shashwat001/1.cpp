//shashwat001

#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <list>
#include <utility>
#include <algorithm>
#include <cassert>

using namespace std;

#define INF 2147483647
#define LINF 9223372036854775807
#define mp make_pair
#define pb push_back

typedef long long int lli;
typedef pair<int,int> pi;

lli gcd(lli p,lli q)
{
	if(q == 0)
		return p;
	return gcd(q,p%q);
}

int main ()
{
	int t;
	scanf("%d",&t);
	for(int T = 1; T <= t;T++)
	{
		lli p,q;
		scanf("%lld/%lld",&p,&q);
		lli g = gcd(p,q);
		lli a = p/g;
		lli b = q/g;
		if( (b & (b-1)) != 0)
		{
			printf("Case #%d: impossible\n",T);
		}
		else
		{
			lli cnt = 0;
			while(a < b)
			{
				a = a*2;
				cnt++;
			}
			printf("Case #%d: %lld\n",T,cnt);
		}
	}
	return 0;
}
