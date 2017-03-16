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

double C, F, X;

double calc(int N)
{
    double ret = 0.0, f = 2.0;

    for(int i = 0;i<N;++i)
    {
        ret += C/f;
        f += F;
    }
    return ret;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    int T = INPT_INT;

    for(int ca = 1;ca<=T;++ca)
    {
        scanf("%lf %lf %lf",&C,&F,&X);

        double res = X/2.0;

        int low = 0, high = 100000, mid1, mid2;
        while(low<=high)
        {
            mid1 = low + (high-low)/3;
            mid2 = high - (high-low)/3;

            double res1 = calc(mid1) + (mid1?X/(2.0+F*mid1):X/2.0);
            double res2 = calc(mid2) + (mid2?X/(2.0+F*mid2):X/2.0);

            if(res1 > res2) low = mid1+1;
            else if(res1 < res2) high = mid2-1;
            else {low = mid1+1; high = mid2-1;}

            res = min( res, min(res1,res2) );
        }
        printf("Case #%d: ",ca);
        printf("%.7lf\n",res);
    }
    return 0;
}
