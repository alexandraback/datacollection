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

LL f(LL a, LL b, LL x)
{
    if(a<=x || b<=x) return (a+1)*(b+1);
    if(b<a)swap(a,b);
    LL one = 1;
    int l = 0;
    while( (one<<l)   <= b)l++;
    l--;
    int A,B,X;
    A =  (a>>l)&1;
    B =  (b>>l)&1;
    X =  (x>>l)&1;
    if(X==0)
    {
        if(A==0)return f(a,(one<<l)-1,x) + f(a,b-(one<<l),x);
        return f((one<<l)-1 , (one<<l) - 1, x) + f((one<<l)-1 , b - (one<<l) , x) + f(a-(one<<l) , (one<<l)-1 ,x);
    }
        return f(a-(one<<l) , b-(one<<l) , x - (one<<l)) + (a+1)*(b+1) - (a+1-(one<<l))*(b+1 - (one<<l));
}

int main()
{
    int t; cin>>t; int T = t; while(t--)
    {
    
        LL a,b,x;
        cin>>a>>b>>x;
        cout<<"Case #"<<T-t<<": "<<f(a-1,b-1,x-1)<<endl;
    }
    return 0;
}

