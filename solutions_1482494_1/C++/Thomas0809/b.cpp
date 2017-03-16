#include<cstdio>
#include<cstring>
int T,n,a[1111],b[1111],ans,sum,x;
bool h1[1111],h2[1111];

int find1(int x)
{
    int bb=0,res=0;
    for (int i=1; i<=n; i++)
        if (!h1[i] && a[i]<=x && b[i]>bb)
            bb=b[i],res=i;
    return res;
}

int find2(int x)
{
    for (int i=1; i<=n; i++)
        if (!h2[i] && b[i]<=x)
            return i;
    return 0;
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for (int tt=1; tt<=T; tt++)
    {
        scanf("%d",&n);
        for (int i=1; i<=n; i++)
            scanf("%d%d",&a[i],&b[i]);
        ans=0; sum=0;
        memset(h1,false,sizeof h1);
        memset(h2,false,sizeof h2);
        while (sum<2*n)
        {
              x=find2(sum);
              if (x!=0)
              {
                  ans++; sum+=(!h1[x])+(!h2[x]);
                  h1[x]=h2[x]=true;
              }
              else
              {
                  x=find1(sum);
                  if (x==0) break;
                  h1[x]=true;
                  ans++; sum++;
              }
        }
        printf("Case #%d: ",tt);
        if (sum<2*n)
            printf("Too Bad\n");
        else
            printf("%d\n",ans);
    }
    return 0;
}
