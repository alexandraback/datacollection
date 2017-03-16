//satyaki3794
#include <bits/stdc++.h>
#define ff first
#define ss second
#define pb push_back
#define MOD (1000000007LL)
#define LEFT(n) (2*(n))
#define RIGHT(n) (2*(n)+1)

using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

ll pwr(ll base, ll p, ll mod = MOD){
ll ans = 1;while(p){if(p&1)ans=(ans*base)%mod;base=(base*base)%mod;p/=2;}return ans;
}



int main()
{
    ios_base::sync_with_stdio(0);
    freopen("D-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

    	cout<<"Case #"<<x++<<":";
    	ll k, c, s;
    	cin>>k>>c>>s;

    	if(s < k){
    		cout<<" IMPOSSIBLE\n";
    		continue;
    	}

    	for(int pos=1;pos<=k;pos++){
    		ll final = pos, rem = c-1;
    		while(rem--){
    			final = (final-1)*k + pos;
    		}
    		cout<<" "<<final;
    	}

    	cout<<endl;
    }

    return 0;
}







