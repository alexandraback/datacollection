#include <cstdio>
#include <cstring>

int mark[2000000+1];

int check(int x,int low,int high,int id)
{
    if (x<=10) return 0;
    int tmp=x,h=1;
    while (x!=0)
    {
        x/=10;
        h*=10;
    }
    h/=10;
    x=tmp;
    int ret=0,smallest=x;
    while (tmp>0)
    {
        if (x>=h && x>=low && x<=high && mark[x]!=id)
        {
            ++ret;
            mark[x]=id;
            if (x<smallest) return 0;
        }
        tmp/=10;
        x=x/10+x%10*h;
    }
    return ret*(ret-1)/2;
}

int main()
{
    freopen("a.in","r",stdin);
    freopen("a.out","w",stdout);
    int tot_tc;
    scanf("%d",&tot_tc);
    memset(mark,0,sizeof(mark));
    for (int tc=1;tc<=tot_tc;++tc)
    {
        int low, high;
        int ans=0;
        scanf("%d %d",&low,&high);
        for (int j=low;j<=high;++j)
            ans+=check(j,low,high,tc);
        printf("Case #%d: %d\n", tc, ans);
    }
    return 0;
}
