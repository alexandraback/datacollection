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

lli get(lli s, lli e, lli c, lli r)
{
    lli m;
    lli preSum = s;
    lli ans = e;
    lli sum;
    ++s;
    while(s <= e)
    {
        m = (s+e)/2;
        sum = preSum + (((s+m)*(m-s+1))/2)*c;

        //cout << "s - "<< s << " m - " << m<< " e - " << e << " sum - " << sum << endl;
        //system("pause");

        if(sum > r)
        {
            e = m-1;
            ans = m;
        }
        else if(sum < r)
        {
            s = m+1;
        }
        else
        {
            return m;
        }
    }

    return ans;
}

int main()
{
    int tc;

    scanf("%d",&tc);

    for(int t=1;t<=tc;++t)
    {
        lli c,d,v;
        lli den[105] = {0};
        lli ans = 0;

        scanf("%lld%lld%lld",&c,&d,&v);
        for(lli i=0;i<d;++i)
        {
            scanf("%lld",den+i);
        }

        den[d] = v+1;

        lli runSum = 0;
        for(lli i=0;i<=d;++i)
        {
            if(runSum < den[i]-1)
            {
                //lli ret = get(runSum, den[i]-1, c, den[i]-1);
                //cout << "den - " << den[i] << " ret - " << ret << " runSum - "<< runSum <<endl;
                //ans += (ret - runSum);
                ans += 1;
                //runSum += ((ret - runSum)*(runSum+1+ret)/2)*c;
                runSum += (runSum+1)*c;
            }
            if(runSum >= den[i]-1)
                runSum += den[i]*c;
            else
                --i;
        }

        printf("Case #%d: %lld\n",t,ans);
    }

    return 0;
}
