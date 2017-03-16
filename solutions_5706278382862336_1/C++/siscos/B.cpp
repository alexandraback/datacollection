#include <vector>
#include <valarray>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <algorithm>
#include <sstream>
#include <bitset>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <complex>
using namespace std;
typedef long long ll;
#define FOR(i, a, b) for(int i = (a); i < (b); ++i)

ll Gcd(ll m, ll n){
	if (n>m)
	{
		ll tmp = n;
		n = m;
		m = tmp;
	}

	ll gcd = 1;
	while(true)
	{
		if (m%n==0)
		{
			gcd = n;
			break;
		}
		else
		{
			ll tmp = m;
			m = n;
			n = tmp %n;
		}
	}
	return gcd;
}

int main()
{
	freopen("A-large.in","rt",stdin);
	freopen("A-large.out","wt",stdout);
    int t;
    cin>>t;
    for(int zz=0;zz<t;zz++)
    {
        ll p,q;
        scanf("%lld/%lld",&p,&q);
        int c=0;
        ll gc = Gcd(p,q);
        p /= gc;
        q /= gc;
        bool find = false;
        ll t = q;
        int cnt = 0;
        while(t!=1)
        {
            if (t % 2 != 0)
            {
                find = true;
                break;
            }
            t /= 2;
            cnt++;
        }
        if (find)
        {
            printf("Case #%d: impossible\n",zz+1);
            continue;
        }
        int cnt1 =0;
        int d = 2;
        while(true)
        {
            if (p/(q/2)==1)
            {
                break;
            }
            else
                cnt1++;
            q/=2;
        }
        printf("Case #%d: %d\n",zz+1,cnt1+1);

    }
    fcloseall();
    return 0;
}