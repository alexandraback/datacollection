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
	ll low = 1ll, high = 707106781ll, mid;
	while( high - low > 1 ){
		mid = (low + high) / 2;
		if( t <= g(r, mid) ){
			high = mid;
		}else{
			low = mid;
		}
	}
	mid = (low + high) / 2;
	return mid;
}

ll solve(ll r, double t, ll s = 1){
	ll sum = 0;
	for(ll k = s; true ; k++){
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
		ll r, t, ans;
		cin >> r >> t;
		if( 1000000 < (t / r) ){
			ans = f(r, t);
		}else{
			ans = solve(r, t);
		}
		cout << "Case #" << t_ << ": " << ans << endl;
	}
}

