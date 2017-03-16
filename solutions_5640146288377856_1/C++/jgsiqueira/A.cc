#include <bits/stdc++.h>

using namespace std;

int main()
{
    //freopen("in.txt","r",stdin);
    //freopen("out.txt","w",stdout);

    int t;
    scanf("%d",&t);

    for(int caso=1; caso<=t; caso++)
    {
        int r,c,w;
        scanf("%d%d%d",&r,&c,&w);

        int ans = r*(c/w) + (w-1);
        if(c%w) ans++;

        printf("Case #%d: %d\n",caso,ans);
    }

    return 0;
}
