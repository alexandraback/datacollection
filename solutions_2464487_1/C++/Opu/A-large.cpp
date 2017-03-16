#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cctype>
#include <cstdlib>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <bitset>
#include <numeric>
#include <algorithm>
#include <functional>
using namespace std;

const inline int __GET_INT(){int ret;scanf("%d",&ret);return ret;}
#define INPT_INT __GET_INT()

typedef long long LL;

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    LL T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        LL r,t;
        cin>>r>>t;

        LL low = 1, high = min( (LL)(2000000000LL) , t/r ), mid, res = -1;

        while( low <= high )
        {
            mid = (low+high)/2;

            LL cur = (mid*(mid-1)) / 2;

            LL dif = r * mid + cur;

            if( dif <= t )
            {
                res = mid;
                low = mid+1;
            }
            else high = mid-1;
        }

        int ans = 0;
        if( res != -1 )
        {
            ans = res/2;
        }
        printf("Case #%d: %d\n",ca,ans);
    }
    return 0;
}
