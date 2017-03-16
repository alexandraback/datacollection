// karanaggarwal
#include<bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define F first
#define S second
#define SZ(a) (int)(a.size())
#define CLR(a) a.clear()
#define SET(a,b) memset(a,b,sizeof(a))
#define LET(x,a) __typeof(a) x(a)
#define TR(v,it) for( LET(it,v.begin()) ; it != v.end() ; it++)
#define FORi(i,a,b) for(LET(i,a) ; i<b; i++)
#define repi(i,n) FORi(i,(__typeof(n))0,n)
#define FOR(i,a,b) for(i=a ; i<b; i++)
#define rep(i,n) FOR(i,0,n)
#define si(n) scanf("%d",&n)
#define sll(n) scanf("%lld",&n)
#define pi(n) printf("%d",n)
#define piw(n) printf("%d ",n)
#define pin(n) printf("%d\n",n)
using namespace std;

typedef long long LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector< PII > VPII;
LL power(LL a, LL p, LL mod)
{LL ret = 1;while(p){if(p&1)ret = (ret*a)%mod;a=(a*a)%mod;p/=2;}return ret;}

LL gcd(LL a, LL b)
{
    if(b)
        return gcd(b,a%b);
    return a;
}
int main()
{
    int t,T; si(t); T=t; while(t--)
    {
        cout<<"Case #"<<T-t<<": ";
            LL x,y; 
            scanf("%lld/%lld",&x,&y);
            LL g= gcd(x,y);
            x/=g; y/=g;
            int c=0;
            if(y & (y-1))
            {
                cout<<"impossible\n";
                continue;
            }
            while(x<y)
            {
                c++; 
                x<<=1;
            }
            cout<<c<<endl;
    }
    return 0;
}

