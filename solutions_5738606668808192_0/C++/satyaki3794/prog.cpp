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


ll isPrime(ll n){
	for(ll i=2;i*i<=n;i++)
		if(n % i == 0)
			return i;
	return -1;
}


int bits[20];
ll arr[12];
ll powers[12][18];


int main()
{
    ios_base::sync_with_stdio(0);
    freopen("C-small-attempt1.in", "r", stdin);
    // freopen("B-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);


    cout<<"Case #1:\n";
    int t;
    cin>>t>>t>>t;

    for(int i=2;i<=10;i++){
    	powers[i][0] = 1;
    	for(int j=1;j<=16;j++)
    		powers[i][j] = powers[i][j-1] * i;
    }

    int cnt = 0;
    for(int mask=(1<<15)+1;mask<(1<<16);mask+=2){
    	bool ok = true;
    	for(int j=2;j<=10;j++){
    		ll val = 0;
    		for(int i=0;i<16;i++)
    			if((mask>>i) & 1)
    				val += powers[j][i];
    		arr[j] = isPrime(val);
    		if(arr[j] == -1)	ok = false;
    	}
    	if(ok){
    		for(int i=0;i<16;i++)	bits[i] = ((mask>>i)&1);
    		for(int i=15;i>=0;i--)	cout<<bits[i];
    		for(int i=2;i<=10;i++)	cout<<" "<<arr[i];
    		cout<<endl;
    		cnt++;
    	}
    	if(cnt == 50)	break;
    }

    return 0;
}







