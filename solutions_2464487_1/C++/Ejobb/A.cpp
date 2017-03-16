#include <cmath>
#include <cstdio>
#include <iostream>
#include <algorithm>

#define LL				long long
#define CS				const static
#define Rep(i,l,r)			for(LL i = (l) ; i <= (r) ; i++)

using namespace std ;

int main()
{
	freopen("A-large.in","r",stdin) , freopen("2.txt","w",stdout) ;
	int T ; scanf("%d",&T) ; Rep(TT,1,T)
	{
		LL R,t ; cin >> R >> t ;
		LL l = 1 , r = (LL)sqrt((double)t) , ans , mid ;
		while(l <= r)
		{
			mid = (l+r) >> 1 ; double val = 2.0*mid*mid + 2.0 * R * mid - mid ;
			if(val <= 2e18)
			{
				LL v1 = 2*mid*mid + 2 * R * mid - mid ;
				if(v1 <= t)	l = mid + 1 , ans = mid ;
				else	r = mid - 1 ;
			}else	r = mid - 1 ;
		}
		cout << "Case #"<< TT <<": "<< ans << endl ;
	}
	return 0 ;
}
