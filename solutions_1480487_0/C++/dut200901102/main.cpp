#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

const int MAXN=210;
const double EPS=1e-9;
const double INF=1e9;

int n;
double ans[MAXN],finalAns[MAXN];
double sum,Sum;

struct Node
{
    double v;
    int id;
    friend bool operator <(const Node &x,const Node &y)
    {
        return x.v+EPS<y.v;
    }
} p[MAXN];

void init()
{
    scanf("%d",&n);
    sum=0;
    for(int i=0; i<n; ++i)
    {
        scanf("%lf",&p[i].v);
        p[i].id=i;
        sum+=p[i].v;
    }
}
void solve()
{
    Sum=sum;
    sort(p,p+n);
    p[n].v=INF;
    for(int i=0; i<=n; ++i)ans[i]=0;

    for(int i=0; i<n; ++i)
    {
        if(sum-(i+1)*(p[i+1].v-p[i].v)>EPS)
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
    for(int i=n-1; i>=0; --i)
        ans[i]+=ans[i+1];
    for(int i=0; i<n; ++i)
    {
        int id=p[i].id;
        finalAns[id]=ans[i];
    }
    for(int i=0; i<n; ++i)
        printf(" %.6f",finalAns[i]/Sum*100);
    printf("\n");
}
int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t,cases=1;
    for(scanf("%d",&t); t--;)
    {
        printf("Case #%d:",cases++);
        init();
        solve();
    }
    return 0;
}
