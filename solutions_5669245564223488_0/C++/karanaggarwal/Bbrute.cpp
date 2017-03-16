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

int valid(string A)
{
    int n = A.size();
    int fre[26]={};
    fre[A[0]-'a']=1;
    for(int i=1; i<n;i++)
        if(A[i]!=A[i-1])
        {
            if(fre[A[i]-'a'])
                return 0;
            fre[A[i]-'a']=1;
        }
    return 1;
}


int main()
{
    int t,T; si(t); T=t;while(t--)
    {
        int n; cin>>n; 
        string A[10];
        int P[10];
        repi(i,10)P[i]=i;
        repi(i,n)cin>>A[i];
        sort(A,A+n);
        int c=0;
        do
        {
            string B = "";
           repi(i,n)
               B += A[P[i]];
           if(valid(B))c++;
        }while(next_permutation(P,P+n));
        cout<<"Case #"<<T-t<<": "<<c<<endl;
    }
    return 0;
}

