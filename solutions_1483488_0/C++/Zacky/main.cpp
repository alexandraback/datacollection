#include <iostream>
#include <cstdio>
using namespace std;
const int maxn = 1002;
int st,end;

int cal(int x)
{
    int ans = 1;
    while(x)
    {
        ans *= 10;
        x /= 10;
    }
    return ans/10;
}

void solve()
{
    scanf("%d %d",&st,&end);
    int cnt = 0;
    for(int i=st;i<=end;i++)
    {
        int wei = cal(i);
        int tmp = i;
        while(true)
        {
            tmp = tmp / 10 + wei * (tmp % 10);
            if(tmp == i)
            {
                break;
            }
            if(tmp > i && tmp <= end)
            {
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    return;
}

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);
    int cas,x = 0;
    scanf("%d",&cas);
    while(x < cas)
    {
        printf("Case #%d: ",++x);
        solve();
    }
    return 0;
}
