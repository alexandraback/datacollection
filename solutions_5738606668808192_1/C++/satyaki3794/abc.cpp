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


int arr[50], factors[100005];
int p, seive[100005];
ll primes[100005];


int main()
{
    ios_base::sync_with_stdio(0);
    // freopen("C-small-attempt1.in", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("output.txt", "w", stdout);

    seive[1] = 1;
    for(int i=2;i<=100000;i++)
    	if(!seive[i]){
    		primes[p++] = i;
    		for(int j=2*i;j<=100000;j+=i)
    			seive[j] = 1;
    	}


    cout<<"Case #1:\n";
    int t;
    cin>>t>>t>>t;

    arr[31] = 1;
    int cnt = 0;
    for(int mask=(1<<15)+1;mask<(1<<16);mask+=2){
    	
    	for(int i=0;i<16;i++)	arr[i] = ((mask>>i) & 1);

    	bool ok = true;
    	for(int base=2;base<=10;base++){

    		int factor = -1;
	    	for(int i=0;i<p;i++){
	    		int pval = primes[i];
	    		ll mod = 0, temp = 1;
	    		for(int j=0;j<32;j++){
	    			if(arr[j] == 1)	mod = (mod + temp) % pval;
	    			temp = (temp * base) % pval;
	    		}
	    		if(mod == 0){
	    			factor = pval;
	    			break;
	    		}
	    	}

	    	if(factor == -1)	ok = false;
	    	factors[base] = factor;
	    }

	    if(ok){

	    	for(int i=31;i>=0;i--)	cout<<arr[i];
	    	for(int base=2;base<=10;base++)	cout<<" "<<factors[base];
	    	cout<<endl;

	    	cnt++;
	    // cout<<cnt<<endl;
	    	if(cnt == 500)	break;
	    }
    }

// cout<<cnt<<endl;
    return 0;
}







