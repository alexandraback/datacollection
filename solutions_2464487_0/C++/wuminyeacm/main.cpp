#include <stdio.h>
int r,t,m;
inline int gets(int n)
{
    return 2*n*n-n+2*n*r;
}
int findp(int i,int j,int k)
{
    if (i>j) return m-1;
    if (i==j) return i;
    int mid=(i+j)>>1;
    int tem=gets(mid);
    if (k==tem) return mid;
    if (k>tem) return findp(mid+1,j,k);
    return findp(i,mid,k);
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T,cas=0;
    scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&r,&t);
        int ans=findp(1,1000,t);
        if (gets(ans)!=t) --ans;
        printf("Case #%d: %d\n",++cas,ans);
    }
}
