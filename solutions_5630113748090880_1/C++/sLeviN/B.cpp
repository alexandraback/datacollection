#include <bits/stdc++.h>
using namespace std;

#define f(i,a)  for(int i=0;(i)<(a);++i)
#define fab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define fba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define fit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()
#define MOD 1000000007

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef char u8;
typedef vector <int> vi;
typedef pair <int, int> pii;

ll pw(ll b, int p){
    ll a=1;
    while(p){
        if(p&1)
            a=(a*b)%MOD;
        b=(b*b)%MOD;
        p>>=1;
    }
    return a;
}

int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);
    int T,t,n,A[2501],k;
    vector<int> v;
    cin>>T;
    f(t,T){
        cout<<"Case #"<<t+1<<": ";
        cin>>n;
        f(i,2501)
            A[i]=0;
        v.clear();
        f(i,2*n-1){
            f(j,n){
                cin>>k;
                A[k]++;
            }
        }
        f(i,2501)
            if(A[i]&1)
                v.push_back(i);
        sort(v.begin(),v.end());
        f(i,v.size())
            cout<<v[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
