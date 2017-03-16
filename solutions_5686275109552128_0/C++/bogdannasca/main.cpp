#include <stdio.h>
#include <vector>
#include <algorithm>
#define INF 1<<30
#define mod(a,b)((a%b!=0)?1:0)
using namespace std;
long long t,n,time,ktime,x;
std::vector<long long> a[1005],b,c;
bool CMP(long long A,long long B)
{
    return A>B;
}
int main()
{
    freopen("text.in","r",stdin);
    freopen("text.out","w",stdout);
    scanf("%lld",&t);
    for(int i=1;i<=1001;++i)
    {
        a[i].resize(i+2);
        fill(a[i].begin(),a[i].end(),INF);
        for(int j=1;j<=i;++j)
        {
            if(a[i][i/j+mod(i,j)]>j-1)a[i][i/j+mod(i,j)]=j-1;
        }
    }
    for(int i=1;i<=1001;++i)
    {
        x = INF;
        for(int j=1;j<=i;++j)
        {
            if(a[i][j]<x&&a[i][j]>0)x = a[i][j];
            if(a[i][j]>x)a[i][j] = x;
        }
    }
    for(int k=1;k<=t;++k)
    {
        printf("Case #%d: ",k);
        scanf("%lld",&n);
        b.clear();
        c.clear();
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&x);
            b.push_back(x);
        }
        sort(b.begin(),b.end(),CMP);
        c = a[b[0]];
        for(int i=1;i<b.size();++i)
        {
            for(int j=1;j<a[b[i]].size();++j)
            {
                if(a[b[i]][j]!=INF)c[j] += a[b[i]][j];
            }
        }
        time = INF;
        for(int i=1;i<=c.size();++i)
        {
            if(c[i]+i<time)time = c[i]+i;
        }
        printf("%lld\n",time);
    }
    return 0;
}
