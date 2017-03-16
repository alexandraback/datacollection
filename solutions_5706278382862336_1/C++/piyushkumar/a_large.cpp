#include <bits/stdc++.h>
using namespace std;

#define ll long long int
#define ull unsigned long long int
#define uint unsigned int

typedef pair<int,int> pii;
#define x first
#define y second

#define read(n) scanf("%d",&n)
#define readll(n) scanf("%lld",&n)
#define read2(n,m) scanf("%d%d",&n,&m)
#define read3(n,m,l) scanf("%d%d%d",&n,&m,&l)

#define fr(i,n)     for(int i=0;i<n;i++)
#define frr(i,a,b)   for(int i=a;i<b;i++)
#define rf(i,n)     for(int i=n-1;i>=0;i--)

#define init(mem,v) memset(mem,v,sizeof(mem))

#define DB(x)              cout<<__LINE__<<" :: "<<#x<< ": "<<x<<endl;
#define DB2(x, y)          cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<endl;
#define DB3(x, y, z)       cout<<__LINE__<<" :: "<<#x<< ": "<<x<<" | "<<#y<< ": "<<y<<" | "<<#z<<": "<<z<<endl;
#define DB4(a, b, c, d)    cout<<__LINE__<<" :: "<<#a<< ": "<<a<<" | "<<#b<< ": "<<b<<" | "<<#c<<": "<<c<<" | "<<#d<<": "<<d<<endl;

bool twopow(ll n){
    return (n & (n-1))==0;
}

ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}

bool valid(ll a,ll b,int h){
    if(h>40) return false;
    if(a==0) return true;
    if(a==b) return true;

    while(a<b){
        b/=2;
        h++;
    }
    return valid(a-b,b,h);
}

int main(){
    int t;
    ll a,b;
    read(t);
    for(int ii=1;ii<=t;ii++){
        scanf("%lld/%lld",&a,&b);
        ll g=gcd(a,b);
        a=a/g;
        b=b/g;

        if(!twopow(b)){
            printf("Case #%d: impossible\n",ii);
            continue;
        }

        int ans=0;
        while(a<b){
            b/=2;
            ans++;
        }
        if(!valid(a-b,b,ans)) ans=41;
        if(ans<=40) printf("Case #%d: %d\n",ii,ans);
        else printf("Case #%d: impossible\n",ii);
    }
}
