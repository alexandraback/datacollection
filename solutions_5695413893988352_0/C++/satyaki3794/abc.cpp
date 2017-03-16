//satyaki3794
#include <bits/stdc++.h>
#include <iomanip>
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


int n;
bool valid(int num, string str){
// cout<<"now valid "<<num<<" "<<str<<endl;
	for(int i=n-1;i>=0;i--){
// cout<<"at i = "<<i<<" we have "<<str[i]<<" "<<num%10<<endl;
		if(str[i] == '?'){
			num /= 10;
			continue;
		}
		if(str[i]-'0' != num%10)	return false;
		num /= 10;
	}
	return true;
}


int main()
{
    ios_base::sync_with_stdio(0);

    freopen("B-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
   // t=1;
    while(t--){

    	cout<<"Case #"<<x++<<": ";

    	string a, b;
    	cin>>a>>b;

    	n = a.length();
    	int lim = 1;
    	while(n--)	lim *= 10;
    	n = a.length();

    	int till_now = MOD;
    	ii ans (MOD, MOD);
    	// lim=1;
// cout<<valid(1, a)<<endl;

// lim=0;
    	for(int i=0;i<lim;i++)
    		for(int j=0;j<lim;j++)
    			if(valid(i, a) && valid(j, b)){
    		// cout<<"check "<<i<<" "<<j<<endl;
    				if(abs(i-j) < till_now){
    					till_now = abs(i-j);
    					ans = ii (i, j);
    				}
    				else if(abs(i-j) == till_now)
    					ans = min(ans, ii(i, j));
    			}


    	if(n >= 3 && ans.ff < 100)	cout<<"0";
    	if(n >= 2 && ans.ff < 10)	cout<<"0";
    	cout<<ans.ff<<" ";
    	if(n >= 3 && ans.ss < 100)	cout<<"0";
    	if(n >= 2 && ans.ss < 10)	cout<<"0";
    	cout<<ans.ss<<"\n";
    }

    return 0;
}







