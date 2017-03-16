#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#define MAXN 210
#define MAX 1000000000

using namespace std;
int n;
double sum,S;

int fun(double x,double y)
{
    if(fabs(x-y)<1e-9)return 0;
    return x<y?-1:1;
}
struct node
{
    double v;
    int id;
    bool operator <(const node &a)const
    {
        return fun(v,a.v)<0;
    }
}p[MAXN];

double ans[MAXN],ans2[MAXN];

void init()
{
    sum=0;
    memset(ans,0,sizeof(ans));
}

void input()
{
    scanf("%d",&n);
    for(int i=0;i<n;++i)
    {
        scanf("%lf",&p[i].v);
        p[i].id=i;
        sum+=p[i].v;
    }
}

void solve()
{
    S=sum;
    sort(p,p+n);
    p[n].v=MAX;
    for(int i=0;i<n;i++)
    {
        if(fun(sum,(i+1)*(p[i+1].v-p[i].v))>0)
        {
            ans[i]=(p[i+1].v-p[i].v);
            sum-=ans[i]*(i+1);
        }
        else
        {
            ans[i]=sum/(i+1);
            break;
        }
    }
    for(int i=n-1;i>=0;i--) ans[i]+=ans[i+1];
    for(int i=0;i<n;i++)
    {
        int id=p[i].id;
        ans2[id]=ans[i];
    }
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int cas=1;cas<=t;++cas)
    {
        init();
        input();
        solve();
        printf("Case #%d:",cas);
        for(int i=0;i<n;++i) printf(" %.6f",ans2[i]/S*100);
        printf("\n");
    }
    return 0;
}
