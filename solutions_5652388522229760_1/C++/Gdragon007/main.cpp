#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#define LL long long
#define eps 1e-8
#define mem(a,b) memset(a,b,sizeof(a))
#define zero(x) ((x > +eps) - (x < -eps))
#define MAX 110
using namespace std;

bool vis[MAX];
int cnt;

void deal(int x)
{
    while(x)
    {
        int y = x % 10;
        if(!vis[y])
        {
            vis[y] = 1;
            cnt ++;
        }
        x /= 10;
    }
}

int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t, Case = 0, n;
    scanf("%d",&t);
    while(t --)
    {
        Case ++;
        printf("Case #%d: ",Case);
        scanf("%d",&n);
        if(n == 0)
        {
            printf("INSOMNIA\n");
            continue;
        }
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        cnt = 0;
        while(1)
        {
            ans += n;
            deal(ans);
            if(cnt == 10)
            {
                break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
