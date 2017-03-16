#include <iostream>
#include <cstdio> // for printf
#include <numeric>
#include <iterator>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <stack>
#include <string>
#include <sstream>
#include <math.h>

#define REP(i,n) for(int i = 0; i<(n); i++)
#define ITER(i,v) for(auto i : v)
#define INF 1000000000
#define F(v) (v).begin(), (v).end()
#ifdef DEBUG
const bool DEBUG = true;
#else
const bool DEBUG = false;
#endif

using namespace std;

template <class T>
using priority_queue_asc =  priority_queue<T,vector<T>, greater<T> >;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef vector<bool> vb;

ll reverse(ll n){
	ll ans = 0;
	while(n>0){
		ans*=10;
		ans += n%10;
		n/=10;
	}
	return ans;
}

int digits(ll N){
	int digits = 0;
	while(N>0) digits++, N/=10;
	return digits;
}

int solve(ll n){
	cerr << "solve: "<<n<<"\n";
	// first set the last half to ...000001
	int d = digits(n);
	cerr << "digits: "<<d<<"\n";
	// thus, set (d/2) digits
	int ans=0;
	ll t = n; // target
	ll pow = 1;
	REP(i,(d+1)/2) pow*=10;
	t = pow*(n/pow) + 1;
	cerr << "target1: "<<t<<"\n";
	if(t==1)
		return n-t;
	if(t<=n){
		ans += n-t;
		n=t;
	} else {
		return solve(n-1)+1;
	}
	// now reverse and go to 99999..9999
	t = reverse(n);
	if(t<n) n=t, ans++;
	cerr << "reverse: "<<n<<"\n";
	if(t==1)
		return n-t;

	// go to 10^(d-1)-1
	pow = 1;
	REP(i,d-1) pow*=10;
	t = pow-1;
	cerr << "target2: "<<t<<"\n";
	ans += n-t;
	cerr << "return: "<<ans<<"\n";
	return ans + solve(t);
}

int main(){
	ios_base::sync_with_stdio(false);cin.tie(0);
	int TC; cin >> TC;
	for(int tc=1;tc<=TC;tc++){
		ll N; cin >> N;

		cout << "Case #"<<tc<<": "<< 1+solve(N) <<"\n";
	}
	return 0;
}


