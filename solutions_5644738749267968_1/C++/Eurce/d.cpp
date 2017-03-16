#include<cstdio>
#include<cstring>
#include<algorithm>
#include<functional>
using namespace std;

#define eps 1e-8

int t,n,s1,s2;
double a[1000],b[1000];

void init()
{
    s1=s2=0;
    int i;
    for(i=0;i<n;i++)
        scanf("%lf",a+i);
    for(i=0;i<n;i++)
        scanf("%lf",b+i);
}

void solve()
{
    int i,j,k,l;
    sort(a,a+n,less<double>());
    sort(b,b+n,less<double>());
    for(i=j=0;i<n;i++)
    {
        if(a[i]>b[j]+eps)
        {
            s1++;
            j++;
        }
    }
    for(i=j=0;i<n;i++)
    {
        if(b[i]>a[j]+eps)
        {
            s2++;
            j++;
        }
    }
    printf("Case #%d: %d %d\n",++t,s1,n-s2);
}

int main()
{
    scanf("%*d");
    while(~scanf("%d",&n))
    {
        init();
        solve();
    }
    return 0;
}
