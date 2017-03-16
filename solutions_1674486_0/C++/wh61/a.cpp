#include <iostream>
#include <cstring>
#include <cstdio>
#define N 1200
#define M 20000
using namespace std;
int a[N][N];
int ve[M],nx[M],st[N];
int tot=0;
int ok[N];
int n;
int T;
int flag;
void add(int i,int a,int b)
{
    ve[i]=b;
    nx[i]=st[a];
    st[a]=i;
}
void dfs(int v)
{
    ok[v]++;
    for (int i=st[v];i;i=nx[i])
    if (!ok[ve[i]])
    {
        dfs(ve[i]);
    }
    else
      flag=1;
    if (flag) return ;
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    cin>>T;
    for (int ttt=1;ttt<=T;ttt++)
    {
        cin>>n;
        tot=0;
        memset(st,0,sizeof(st));
        memset(nx,0,sizeof(nx));
        for (int k=1;k<=n;k++)
        {
            int num,y;
            scanf("%d",&num);
            for (int i=1;i<=num;i++)
            {
                scanf("%d",&y);
                add(++tot,k,y);
            }
        }
        flag=0;
        for (int i=1;i<=n;i++)
        {
            memset(ok,0,sizeof(ok));
            dfs(i);
            for (int j=1;j<=n;j++)
            if (ok[j]>1)
                flag=1;
            if (flag)break;
        }
        if (flag)
        printf("Case #%d: Yes\n",ttt);
        else
        printf("Case #%d: No\n",ttt);
    }
    return 0;
}
