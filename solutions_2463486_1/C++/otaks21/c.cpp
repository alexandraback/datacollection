#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
using namespace std;

typedef long long ll;

bool is_palindromic(ll a){
	ll x = a, b = 0;
	while( x > 0 ){
		b *= 10;
		b += x % 10;
		x /= 10;
	}
	return a == b;
}

int main(){
	vector<ll> v;
	for(ll i = 1ll; i <= 10000000ll; i++){
		if( is_palindromic(i * i) && is_palindromic(i) ){
			v.push_back(i * i);
		}
	}
	
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int ans = 0;
		ll A, B;
		cin >> A >> B;
		for(int i = 0; i < v.size(); i++){
			if( A <= v[i] && v[i] <= B ) ans++;
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

