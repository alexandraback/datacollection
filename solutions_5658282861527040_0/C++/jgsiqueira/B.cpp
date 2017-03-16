#include <cstdio>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#include <map>
#include <utility>
#include <cmath>
#include <queue>
#include <stack>
#include <set>
#include <deque>
#include <iostream>
#include <math.h>
#include <sstream>
#include <assert.h>
#include <numeric>
#include <limits>
#define INF 0x3f3f3f3f

using namespace std;

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    for(int caso=1; caso<=t; caso++)
    {
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        for(int i=0; i<a; i++)
        {
            for(int j=0; j<b; j++)
            {
                if((i&j) < k) ans++;
            }
        }
        printf("Case #%d: %d\n",caso,ans);
    }
    return 0;
}

