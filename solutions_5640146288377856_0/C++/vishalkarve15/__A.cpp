#include<bits/stdc++.h>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);

    for(int tt=1;tt<=t;tt++)
    {
        int r,c,w;
        scanf("%d%d%d",&r,&c,&w);
        int ans=(r-1)*(c/w);

        if(c%w==0)
        {
            ans+=c/w-1;
            ans+=w;
            printf("Case #%d: %d\n",tt,ans);
            continue;
        }
        ans+=c/w-1;
        ans+=w+1;
        printf("Case #%d: %d\n",tt,ans);
        continue;
    }
    return 0;
}
