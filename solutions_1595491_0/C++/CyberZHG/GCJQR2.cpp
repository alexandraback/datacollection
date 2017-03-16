#include<cstdio>

int main()
{
    //freopen("B-small-attempt0.in","r",stdin);
    //freopen("B-small-attempt0.out","w",stdout);
    int t,n,s,p,a[1024],b;
    scanf("%d",&t);
    for(int k=1;k<=t;++k)
    {
        scanf("%d%d%d",&n,&s,&p);
        int ans = 0;
        for(int i=0;i<n;++i)
        {
            scanf("%d", &a[i]);
            b = a[i] - p;
            if(b < 0)
            {
                continue;
            }
            b >>= 1;
            if(b >= p-1)
            {
                ++ans;
            }
            if(b == p-2 && s > 0)
            {
                ++ans;
                --s;
            }
        }
        printf("Case #%d: %d\n",k,ans);
    }
    return 0;
}
