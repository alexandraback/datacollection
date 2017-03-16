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
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T,b;
    ll m;
    string S;
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        cin>>b>>m;
        S.clear();
        if(m>((ll)1<<(b-2))){
            cout<<"IMPOSSIBLE\n";
            continue;
        }
        cout<<"POSSIBLE\n";
        S.push_back('0');
        f(i,b-1)
            S.push_back('1');
        f(i,b){
            if(i && (m&1)==0){
                S.pop_back();
                S.push_back('0');
            }
            cout<<setfill ('0') << std::setw (b)<< S << "\n";
            S.pop_back();
            if(i)
                m>>=1;
            else
                m--;
        }
    }
    return 0;
}

