#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    int cas,run=0,r,c,w;
    scanf("%d",&cas);
    while (cas--)
    {
        scanf("%d%d%d",&r,&c,&w);
        printf("Case #%d: %d\n",++run,c%w==0?c/w*r+w-1:c/w*r+w);
    }
    return 0;
}
