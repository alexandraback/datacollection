#include<functional>
#include<algorithm>
#include<iostream>
#include<fstream>
#include<sstream>
#include<iomanip>
#include<numeric>
#include<cstring>
#include<climits>
#include<cassert>
#include<cstdio>
#include<string>
#include<vector>
#include<bitset>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<list>
#include<set>
#include<map>
using namespace std;
int getnum()//读大量数据特别快
{
    char ch;
    while(ch=getchar(),ch==10||ch==32);
    int ans=ch-48;
    while((ch=getchar())!=EOF&&(ch>='0'&&ch<='9'))
    {
        ans*=10;
        ans+=ch-'0';
    }
    return ans;
}
int q[100010],w[100010];
#define eps 1e-10
int n;
double cala(double x)
{
    double ans=0;
    for(int i=0;i<=n-1;i++)
        ans+=sqrt((q[i]-x)*(q[i]-x)+w[i]*w[i]);
    return ans;
}
double ternarySearch(double l,double r)
{
    while(r-l>eps)
    {
        double ll=(2*l+r)/3;
        double rr=(l+2*r)/3;
        double ans1=cala(ll);
        double ans2=cala(rr);
        if(ans1>ans2)
            l=ll;
        else
            r=rr;
    }
    return l;
}  
int main(int argc,char *argv[])
{
    int t;
    scanf("%d",&t);
    for(int cas=1;cas<=t;cas++)
    {
        scanf("%d",&n);
        double l=100000000,r=-100000000;
        for(int i=0;i<=n-1;i++)
        {
            scanf("%d %d",&q[i],&w[i]);
            if(q[i]<l) l=q[i];
            if(q[i]>r) r=q[i];
        }
        double ans=ternarySearch(l,r);
        printf("Case %d: %.6lf\n",cas,ans);
    }
    return 0;
}

