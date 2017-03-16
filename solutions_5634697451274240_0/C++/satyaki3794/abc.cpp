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

char str[105];


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("B-small-attempt2.in", "r", stdin);
    // freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
   // t=1;
    while(t--){

    	cout<<"Case #"<<x++<<": ";
    	cin>>str;
    	if(strlen(str) == 1){
    		if(str[0] == '+')	cout<<"0\n";
    		else	cout<<"1\n";
    		continue;
    	}

    	int ans = 0;
    	for(int i=strlen(str)-1;i>=1;i--)
    		if(str[i] == '-'){

    			if(str[0] == '+'){
    				ans++;
    				for(int j=0;j<=i&&str[j]=='+';j++){
    					str[j] = '-';
    				}
    			}

    			ans++;
    			for(int j=0;j<i-j;j++)
    				swap(str[j], str[i-j]);
    			for(int j=0;j<=i;j++)
    				if(str[j] == '+')	str[j] = '-';
    				else	str[j] = '+';
    			// cout<<"after swapping "<<i<<" : "<<str<<endl;
    		}

    	// if(str[0] == '-' && str[1] == '-')	ans++;
    	// if(str[0] == '-' && str[1] == '+')	ans++;
    	// if(str[0] == '+' && str[1] == '-')	ans+=2;
    	if(str[0] == '-')	ans++;
    	cout<<ans<<endl;
    }

    return 0;
}






