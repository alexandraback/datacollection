#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int i,j,k,l,n,m,s,an;
const int N=22;
int sum[N],a[N][N],need[N],b[N];
int f[1<<N],ans[1<<N];
bool cheak(int x,int y)
{
    if (y<0) return true;
     int w[N];
    int s=0;
    for (int p=x;p;p=f[p])
    w[++s]=ans[p];
    int w1[N];
    s=0;
    for (int p=y;p;p=f[p])
    w1[++s]=ans[p];
    for (int i=s;i>=1;i--)
    if (w[i]<w1[i]) return true;
    else if (w[i]>w1[i]) return false;
    return false;
}
int main()
{
    freopen("d.in","r",stdin);
    freopen("d.out","w",stdout);
     int T;
    scanf("%d",&T);
     for (int t=1;t<=T;t++)
     {
            scanf("%d%d",&k,&n);
            memset(sum,0,sizeof(sum));
            for (int i=1,x;i<=k;i++)
            scanf("%d",&x),sum[x]++;
            for (int i=1;i<=n;i++)
            {
                scanf("%d",&need[i]);
                scanf("%d",&a[i][0]);
                for (int j=1;j<=a[i][0];j++)
                scanf("%d",&a[i][j]);
            }
            int M=1<<n;
            memset(f,255,sizeof(f));
            f[0]=0;
            for (int now=0;now<M;now++)
            if (f[now]>=0)
            {
                memcpy(b,sum,sizeof(b));
                for (int i=1;i<=n;i++)
                if ((now&(1<<(i-1))))
                {
                    b[need[i]]--;
                    for (int j=1;j<=a[i][0];j++)
                    b[a[i][j]]++;
                }
                for (int i=1;i<=n;i++)
                if  (!(now&(1<<(i-1))))
                if (b[need[i]]&&(cheak(now,f[now|(1<<(i-1))])))
               //if (b[need[i]]&&(f[now|(1<<(i-1))]==-1))
                f[now|(1<<(i-1))]=now,ans[now|(1<<(i-1))]=i;
            }
                printf("Case #%d: ",t);
            if (f[M-1]<0) printf("IMPOSSIBLE\n");
            else
            {
                int w[N];
                int s=0;
                for (int p=M-1;p;p=f[p])
                w[++s]=ans[p];
                for (int i=s;i>=1;i--)
                {printf("%d",w[i]);if (i!=1) printf(" ");}
                printf("\n");
            }
        }
       // system("pause");
        return 0;
}
            
            
            
