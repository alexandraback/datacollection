#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
vector <ll> a;
bool check(ll x)
{
    int n=0,a[20];
    while (x)
    {
        a[++n]=x%10;
        x/=10;
    }
    for (int i=1;i<=n/2;i++)
        if (a[i]!=a[n-i+1])
            return(false);
    return(true);
}
void init()
{
    for (int i=1;i<=10000000;i++)
        if (check(i) && check(ll(i)*i))
            a.push_back(ll(i)*i);
}
ll get(ll x)
{
    return(upper_bound(a.begin(),a.end(),x)-a.begin()-1);
}
int main()
{
    init();
    int T;
    scanf("%d",&T);
    while (T--)
    {
        ll A,B;
        scanf("%I64d%I64d",&A,&B);
        static int id=0;
        printf("Case #%d: %I64d\n",++id,get(B)-get(A-1));
    }
    return(0);
}

