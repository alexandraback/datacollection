#include <cstdio>

int main()
{
    freopen("A-large.in","r",stdin);
    freopen("A-large.out","w",stdout);
    int T,R,C,W,ans;
    scanf("%d",&T);
    for(int tc=1;tc<=T;tc++)
    {
        scanf("%d%d%d",&R,&C,&W);
        if(C%W==0)
        {
            ans=C/W-1+W;
        }
        else
        {
            ans=C/W-1+W+1;
        }
        if(R>1)
        {
            ans+=(R-1)*C/W;
        }
        printf("Case #%d: %d\n",tc,ans);
    }
    return 0;
}

