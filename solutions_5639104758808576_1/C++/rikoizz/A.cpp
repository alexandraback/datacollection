#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;
int n;
char num[1010];
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int _;scanf("%d",&_);
    for (int __ = 1;__ <= _ ;__++)
    {
        scanf("%d%s",&n,num);
        int ans = 0,cnt = 0;
        for (int i = 0;i <= n;i++)
        if (cnt < i)
        {
            ans += i - cnt;
            cnt = i + num[i]-'0';
        }
        else
            cnt += num[i] - '0';
        printf("Case #%d: %d\n",__,ans);
    }
}
