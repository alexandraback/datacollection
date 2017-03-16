#include <cstring>
#include <cassert>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <typeinfo>
#include <locale>
#include <iterator>
#include <valarray>
#include <complex>

using namespace std;

int main()
{
    long a,b,c,d,e,f,g,h,x,y,z;
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    scanf("%ld",&a);
    for(z=1;z<=a;z++)
    {
        scanf("%ld %ld",&b,&c);
        double p[10],q,r,s,t;
        double ar[99999],dp[100000];
        for(y=0;y<b;y++)
        {
            scanf("%lf",&ar[y]);
            if(y==0)dp[y]=ar[y];
            else dp[y]=ar[y]*dp[y-1];
        }
        d=0;
        q=99999999999.0;
        for(x=0;x<=b;x++)
        {
            r=dp[b-x+1];
            s=(r*(c-b+1+x+x))+(1-r)*(1+c-b+1+c+x+x);
            q=min(q,s);
        }
        q=min(q,2+(double)c);
        printf("Case #%ld: %lf\n",z,q);
    }
}
