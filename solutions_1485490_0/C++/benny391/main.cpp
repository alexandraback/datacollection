#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <string>

using namespace std;

int N,M;
const int maxn=100,maxm=200;
long long a[maxn],A[maxn],b[maxm],B[maxm];

long long ans,now;

void dfs(int x,int idx)
{
    //printf("%d %d\n",x, idx);
    if (x==N+1 || idx==M+1)
    {
        /*
        printf("=============\n");
        printf("x=%d i=%d\n",x,idx-1);
    for (int i=1;i<=3;i++)
        printf("%d ",a[i]);
    printf("\n");*/
        //printf("hello world\n");
        if (now>ans) ans=now;
        return;
    }
    /*
    printf("=============\n");
    printf("x=%d i=%d\n",x,idx-1);
    for (int i=1;i<=3;i++)
        printf("%d ",a[i]);
    printf("\n");*/
    int i=idx;
    bool o=false;
    if (a[x]>0)
    {
        if (A[x]==B[i])
        {
            if (a[x]-b[i]>0)
            {
                a[x]-=b[i];
                now+=b[i];
                dfs(x,i+1);
                //dfs(x+1,i);
                now-=b[i];
                a[x]+=b[i];
            }
            else
            {
                long long tmp=a[x];
                a[x]=0;
                now+=tmp;
                b[i]-=tmp;
                //printf("%d\n",now);
                dfs(x+1,i+1);
                dfs(x+1,i);
                o=true;
                b[i]+=tmp;
                now-=tmp;
                a[x]=tmp;
            }
        } else dfs(x,i+1);
    };
    if (!o) dfs(x+1,i);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T;
    scanf("%d",&T);
    for (int times=1; times<=T; times++)
    {
        scanf("%d %d",&N,&M);
        for (int i=1; i<=N; i++)
            scanf("%lld %d",&a[i],&A[i]);
        //printf("%d\n",N);
        for (int i=1; i<N; i++)
            if (A[i]==A[i+1])
            {
                a[i]+=a[i+1];
                a[i+1]=a[i+2];
                A[i+1]=A[i+2];
                N--;
            }
        //for (int i=1;i<=N;i++)
          //  printf("%d %d\n",a[i],A[i]);
        for (int i=1; i<=M; i++)
            scanf("%lld %d",&b[i],&B[i]);
        now=0;
        ans=0;
        dfs(1,1);
        printf("Case #%d: %lld\n",times,ans);
    }
}
