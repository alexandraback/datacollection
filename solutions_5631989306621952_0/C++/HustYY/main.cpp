#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    int t;
    char s[1111],ans[2222];
    scanf("%d",&t);
    for (int cas=1;cas<=t;++cas)
    {
        scanf("%s",s);
        int bg=1000,ed=1000;
        for (int i=0;s[i];++i)
            if (bg==ed)
                ans[ed++]=s[i];
            else
            {
                if (s[i]>=ans[bg]) ans[--bg]=s[i];
                else ans[ed++]=s[i];
            }
        ans[ed]=0;
        printf("Case #%d: ",cas);
        puts(ans+bg);
    }
    return 0;
}
