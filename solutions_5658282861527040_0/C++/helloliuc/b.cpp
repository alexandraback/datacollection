#include <string>
#include <sstream>
#include <cstring>
#include <algorithm>
#include <functional>
#include <stack>
#include <set>
#include <queue>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef long long ll;
const double eps = 1e-6;
const int maxint = -1u>>2;

int main()
{
    freopen("in.txt","r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d",&T);

    for(int cas =1 ;cas <= T;cas++)
    {
        int ans = 0;
        int a,b,k;
        scanf("%d%d%d",&a,&b,&k);
        for(int i=0;i<a;i++)
        {
            for(int j=0;j<b;j++)
            {
                if((i&j) < k)
                {
                    ans ++;
                }
            }
        }
        printf("Case #%d: %d\n",cas, ans);
    }


    return 0;
}

