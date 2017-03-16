/* @coder: Sidharth Gupta */

#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <cassert>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>


#define MOD 1000000007
#define MIN(a,b) ((a)>(b)?(b):(a))
#define MAX(a,b) ((a)>(b)?(a):(b))
#define ABS(a) MAX(a,-(a))
#define SET(a,b) memset(a, b, sizeof(a))
#define EVEN(a) ((a&1)==0)
#define SQR(a) ((a)*(a))
#define EPS 0.0001

typedef long long int lli;
typedef unsigned long long int llui;
typedef unsigned int uint;

using namespace std;

bool check(lli n)
{
    if((n&(n-1)) == 0)
        return true;
    return false;
}

lli getAns(lli n)
{
    lli ans = 0;

    while(n)
    {
        n >>= 1;
        ++ans;
    }
    return ans;
}

lli gcd(lli a, lli b)
{
    if(b == 0)
        return a;
    return gcd(b, a%b);
}

int main()
{
    int tc, t;
    lli p, q;
    char c;

    scanf("%d",&tc);

    for(t=1;t<=tc;++t)
    {
        scanf("%lld%c%lld",&p,&c,&q);

        int i = 0;
        lli hcf = gcd(p, q);

        p /= hcf;
        q /= hcf;

        if(!check(q))
            printf("Case #%d: impossible\n",t);
        else
        {
            //cout << "here!";
            while(i <= 40)
            {
                if(p == q)
                    break;

                if(p*2 > q)
                {
                    p = 1;
                    q = 1;
                }
                else
                {
                    p *= 2;
                    lli tmp = gcd(p,q);
                    p /= tmp;
                    q /= tmp;
                }
                //cout << p << " " << q;
                ++i;
            }

            if(i > 40)
                printf("Case #%d: impossible\n",t);
            else
                printf("Case #%d: %d\n",t, i);
        }
    }

    return 0;
}
