#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <memory.h>
#include <string>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <assert.h>

#define file_name ""

typedef long long ll;

const int N = 1e5+5;

using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int test;
    ll r,h,d,ans=0;
    scanf("%d",&test);
    for(int t=1;t<=test;++t)
    {
        scanf("%lld%lld",&r,&h);
        ans=0;
        while (1)
        {
            d = 2*r+1;
            if (h>=d) h-=d;
            else break;
            r+=2;
            ans++;
        }
        printf("Case #%d: %d\n",t,ans);
    }

    return 0;
}
