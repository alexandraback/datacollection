#include <cstdlib>
#include <cstring>
#include <cctype>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#define X first
#define Y second
#define sqr(x) ((x)*(x)) 
using namespace std;
const double eps = 1e-8 ;


typedef long long LL ;

int main(int argc, char const *argv[])
{
	freopen("A-large.in","r",stdin);
	freopen("A-large.out","w",stdout);
	int T;
	scanf("%d",&T);
	for(int t=1;t<=T;++t)
	{
		LL tt,r;
		scanf("%lld %lld",&r,&tt);
		LL L=1,R=min((1e18+r-1)/r,1e9),mid,ans;
		while(L<=R)
		{
			mid = (L+R)>>1;
			if(2*r*mid+2*mid*mid-mid<=tt)
			{
				ans = mid;
				L = mid + 1; 
			}
			else 
			{
				R = mid - 1;
			}
		}
		printf("Case #%d: %lld\n",t,ans);
	}
	return 0;
}