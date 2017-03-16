#include<stdio.h>
#include<iostream>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<limits.h>
#include<time.h>
#include<stdlib.h>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<vector>
#define LL long long
using namespace std;
int main()
{
    freopen("in.in", "r", stdin);
    freopen("out.out", "w", stdout);
    int T;
    while(~scanf("%d", &T))
    {
        int cse = 1;
        while(T--)
        {
            int r, c, w;
            scanf("%d%d%d", &r, &c, &w);
            int ans = 0;
            ans = r * (c / w);
            if(c % w == 0)
                ans += w - 1;
            else
            {
                ans += w;
            }
            printf("Case #%d: %d\n", cse++, ans);
        }
    }
    return 0;
}
