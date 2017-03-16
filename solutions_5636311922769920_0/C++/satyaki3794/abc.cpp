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


ll powers[105];


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
    while(t--){

    	cout<<"Case #"<<x++<<": ";

    	int k, c, s;
    	cin>>k>>c>>s;

    	if(k == 1 || c == 1){
    		cout<<"1";
    		for(int i=1;i<k;i++)
    			cout<<" "<<i+1;
    		cout<<endl;
    		continue;
    	}

    	powers[0] = 1;
    	for(int i=1;i<=c;i++)
    		powers[i] = powers[i-1] * k;

    	cout<<"1";
    	ll last = 1;
    	for(int i=1;i<k;i++){
    		last += powers[c-1];
    		cout<<" "<<last;
    	}
    	cout<<endl;
    }

    return 0;
}







