#include<stdio.h>
#include<algorithm>
#define maxn 1000
using namespace std;

int T,C,D,V;
int a[maxn],ok[maxn],aux[maxn];
int sol;


void update(int x)
{
    for(int i=V;i>=0;i--)
     if(i-x>=0 && ok[i-x]) ok[i]=1;
}

void solve()
{
    ok[0]=1;
    for(int i=1;i<=V;i++) ok[i]=0;

     for(int j=1;j<=D;j++)
      for(int i=V;i>=0;i--)
      if(i-a[j]>=0 && ok[i-a[j]]) ok[i]=1;

     //for(int i=1;i<=V;i++) printf("%d ",ok[i]);

     for(int i=1;i<=V;i++)
      if(!ok[i]) sol++,update(i);
}

int main()
{
    freopen("date.in","r",stdin);
    freopen("date.out","w",stdout);

    scanf("%d",&T);
    for(int it=1;it<=T;it++)
    {
        sol=0;

        scanf("%d %d %d",&C,&D,&V);
        for(int i=1;i<=D;i++)
        {
            scanf("%d",&a[i]);
        }

        solve();
        printf("Case #%d: %d\n",it,sol);
    }

    fclose(stdin);
    fclose(stdout);
    return 0;
}
