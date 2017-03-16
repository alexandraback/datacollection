#include <iostream>
#include <cstdio>
#include<vector>
#include<cstring>
using namespace std;
int n,m;
long long res;
struct Po
{
    long long v,t;
}p[109],k[109],pp[109],kk[109];
void tt(int x,int y,long long ans)
{
    if(p[y].v==0LL)return ;
    res=max(res,ans);
    for(int i=x;i<m;i++)
    {
        if(k[i].v==0LL)continue;
      //  cout<<x<<" "<<y<<endl;
        if(k[i].t==p[y].t)
        {
            long long tmp=min(k[i].v,p[y].v);
            res=max(res,ans+tmp);
            k[i].v-=tmp;
            p[y].v-=tmp;
         //   cout<<i<<" "<<y<<" "<<tmp<<endl;
            for(int j=y;j<n;j++)
            {
            tt(i,j,ans+tmp);
            }
            k[i].v+=tmp;
            p[y].v+=tmp;
        }
       // for(int j=y+1;j<n;j++)
       // tt(i,j,ans);
    }
}
void solve()
{
    res=0;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
    cin>>pp[i].v>>pp[i].t;
    for(int j=0;j<m;j++)
    cin>>kk[j].v>>kk[j].t;
    for(int i=0;i<n;i++)
    {

        tt(0,i,0);
    }
    cout<<res<<endl;
}
int main()
{
    int ca;
   freopen("C-small-attempt3.in","r",stdin);
    freopen("b.out","w",stdout);
    scanf("%d",&ca);
    for(int ii=1;ii<=ca;ii++)
    {
        printf("Case #%d: ",ii);
        solve();
    }
    return 0;
}
