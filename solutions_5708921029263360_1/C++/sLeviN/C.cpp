#include <bits/stdc++.h>
using namespace std;

#define f(i,a)  for(int i=0;(i)<(a);++i)
#define fab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define fba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define fit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()
#define pb push_back
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef char u8;
typedef vector <int> vi;
typedef pair <int, int> pii;

ll pw(ll b,int p, int m){
    ll a=1;
    while(p){
        if(p&1)
            a=(a*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return a;
}

ll gcd(ll a, ll b){
    if(a<b)
        swap(a,b);
    if(!b)
        return a;
    return gcd(b,a%b);
}
bool comp (pair<int,char> i,pair<int,char> j) { return (i.first>j.first); }
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T,J,P,K,S,x;
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        cin>>J>>P>>S>>K;
        cout<<J*P*min(S,K)<<"\n";
        f(j,J){
            x=(j*K)%S;
            f(p,P){
                f(s,min(S,K)){
                    cout<<j+1<<" "<<p+1<<" "<<x+1<<"\n";
                    x=(x+1)%S;
                }
            }
        }
        
    }
    return 0;
}

