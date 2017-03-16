#include<cstdio>
#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cstring>
#include<cmath>
using namespace std;
int check(int x,int r,int c)
{
    if(x==1) return 0;
    if(x==2)
    {
        if(r*c%2) return 1;
        else return 0;
    }
    if(r<c) swap(r,c);
    if(x>r) return 1;
    if((r*c)%x) return 1;
    if(x==4&&r==4&&c==2) return 1;
    if(c==1) return 1;
    if(x%2==1&&x/2>c) return 1;
    if(c==2) return 0;
    if(x>=8) return 1;
    return 0;
}
main()
{
    freopen("D-large.in","r",stdin);
    freopen("D-large.out","w",stdout);
    int T;scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        int x,r,c;scanf("%d%d%d",&x,&r,&c);
        int ans=check(x,r,c);
        printf("Case #%d: ",cas);
        if(ans)
        puts("RICHARD");
        else puts("GABRIEL");
    }
}
