#include<bits/stdc++.h>
#define pf printf
#define sf scanf
#define ll  long long
#define llu unsigned long long
#define M 2500
#define pb push_back
#define ppb pop_back
#define F first
#define S second
#define Check(x,w) (x&(1<<w))==(1<<w)?true:false
#define pii pair<ll,ll>
#define X 5800000
#define PI acos(-1)
#define MOD 100000000
using namespace std;

template<class T>
inline bool fs(T &x)
{
    int c=getchar();
    int sgn=1;
    while(~c&&c<'0'||c>'9')
    {
        if(c=='-')sgn=-1;
        c=getchar();
    }
    for(x=0; ~c&&'0'<=c&&c<='9'; c=getchar())
        x=x*10+c-'0';
    x*=sgn;
    return ~c;
}

int ara[M+5],n;

int main()
{
    freopen("OB.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,tt,i,j,a,b,c,d;
    fs(tt);
    for(t=1; t<=tt; t++)
    {
        fs(n);
        memset(ara,0,sizeof(ara));
        for(i=1; i<2*n; i++)
        {
            for(j=0; j<n; j++)
            {
                fs(a);
                ara[a]++;
            }
        }
        pf("Case #%d:",t);
        c=0;
        for(i=1; i<=2500 && c<n; i++)
        {
            if(ara[i]%2!=0)
                c++,pf(" %d",i);
        }
        pf("\n");
    }
    return 0;
}
