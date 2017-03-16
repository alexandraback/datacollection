#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <stack>
#include <queue>
using namespace std;

typedef long long ll;

ll g(ll r, ll n){
	return 2 * r * n - 3 * n + 2 * n * (n + 1);
}

ll f(ll r, ll t){
	ll low = 1ll, high = 10000ll, res;
	while( high - low > 2 ){
		ll mid = (low + high) / 2;
		//cout << "g(" << mid << ") = " << g(r, mid) << endl;
		if( g(r, mid) > t ){
			high = mid;
		}else{
			low = mid + 1;
		}
		//cout << "[" << ((ll)low) << "," << ((ll)high) << "]" << endl;
	}
	//if( g(r, high) > t ) res = high;
	//if( g(r, low) > t ) res = low;
	return (low + high) / 2;
}

ll solve(ll r, double t){
	ll sum = 0;
	for(ll k = 1; true ; k++){
		sum += 2 * r + 4 * k - 3;
		if( t < sum ){
			return k - 1;
		}
	}
	return 0;
}

int main(){
	int T;
	cin >> T;
	for(int t_ = 1; t_ <= T; t_++ ){
		ll r, t;
		cin >> r >> t;
		ll ans = solve(r, t);
		cout << "Case #" << t_ << ": " << ans << endl;
	}
}

