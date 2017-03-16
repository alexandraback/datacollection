#include <stdio.h>
#include <string>
#include <string.h>
#include <vector>
#include <algorithm>
#include <math.h>
#include <queue>
#include <map>
#include <stack>
#include <iostream>
using namespace std;
typedef long long ll;
const double eps = 1e-10;
//const double PI = acos(-1);
const int maxn = 105;
const int maxm=maxn*maxn;
const int inf = 0x3fffffff;
const int mod = 1000000007;

int a,b,k;

int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("out.out","w",stdout);
    int T,ncase=0;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&a,&b,&k);
        int ret=0;
        for(int i=0; i<a; i++)
            for(int j=0; j<b; j++)
                if((i&j)<k)ret++;
        printf("Case #%d: %d\n",++ncase,ret);
    }
    return 0;
}
