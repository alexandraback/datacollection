#include <cstdio>
#include <cstring>

int a[1000],x[1000],y[1000];
int T,n,sum1,sum2,p1,p2,ans;

void dfs(int m)
{
    if (m>n){
       if (sum1==sum2 && sum1!=0){
          for (int i=1;i<p1;i++) printf("%d ",a[x[i]]);printf("%d\n",a[x[p1]]);
          for (int i=1;i<p2;i++) printf("%d ",a[y[i]]);printf("%d\n",a[y[p2]]);
          ans=1;
       }
       return;
    }
    dfs(m+1);
    if (ans==1) return;
    sum1+=a[m];x[++p1]=m;dfs(m+1);sum1-=a[m];x[p1--]=0;
    if (ans==1) return;
    sum2+=a[m];y[++p2]=m;dfs(m+1);sum2-=a[m];y[p2--]=0;
    if (ans==1) return;
}

int main()
{
    freopen("b.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&T);
    for (int Case=1;Case<=T;Case++){
        scanf("%d",&n);
        ans=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        sum1=sum2=0;
        printf("Case #%d:\n",Case);
        dfs(1);if (ans==0) printf("Impossible\n");
    }
}