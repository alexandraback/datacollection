#include <stdio.h>
#include <string.h>
#include <vector>
#include <queue>
#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <math.h>
#include <stack>
#include <list>

#define SZ 10000002
#define EPS 1e-10
#define pb push_back
#define pi (acos(-1.0))


using namespace std;

typedef long long Long;


int main()
{
    int tst,cas;
    freopen("A.in","rt",stdin);
    freopen("A.out","wt",stdout);
    scanf("%d",&tst);
    Long r,t,n;

    for(cas=1;cas<=tst;cas++) {
        scanf("%lld%lld",&r,&t);
        Long lo,hi,mid;
        lo = 0;
        hi = 1000LL;
        while(lo<=hi) {
            mid = (lo+hi)/2;
            if((2*r*mid + 2*mid*mid - mid) <=t ) n = mid , lo = mid+1;

            else hi = mid - 1;

        }
        printf("Case #%d: %d\n",cas,n);

    }
    return 0;
}
