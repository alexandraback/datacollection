#include<cstdio>
int main()
{
    int t,a,b,k;
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    scanf("%d",&t);
    for(int cas=1; cas<=t; ++cas)
    {
        scanf("%d%d%d",&a,&b,&k);
        int ans=0;
        for(int i=0; i<a; ++i)
            for(int j=0; j<b; ++j)
                if((i&j)<k)
                    ++ans;
        printf("Case #%d: %d\n",cas,ans);
    }
}
