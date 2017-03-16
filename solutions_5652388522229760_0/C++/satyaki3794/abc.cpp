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


bool done[10];


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    int t, x = 1;
    cin>>t;
   // t=1;
    while(t--){

    	cout<<"Case #"<<x++<<": ";
    	int n;
    	cin>>n;

    	if(n == 0){
    		cout<<"INSOMNIA\n";
    		continue;
    	}

    	memset(done, 0, sizeof(done));
    	int rem = 10, jump = n;
    	while(rem > 0){

    		int temp = n;
    		while(temp){
    			if(!done[temp % 10])	rem--;
    			done[temp % 10] = true;
    			temp /= 10;
    		}
    // cout<<"after n = "<<n<<" : ";for(int i=0;i<10;i++)cout<<done[i]<<" ";cout<<" and rem = "<<rem<<endl;
    		n += jump;
    	}

    	cout<<n-jump<<endl;
    }

    return 0;
}







