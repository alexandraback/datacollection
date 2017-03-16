#include <iostream>
#include <algorithm>
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
	int T;
	cin >> T;
	for(int t = 1; t <= T; t++){
		int ans = 0;
		ll A, B;
		cin >> A >> B;
		for(ll i = 1; i * i <= B; i++){
			if( A <= i * i ){
				if( is_palindromic(i * i) && is_palindromic(i) ){
					ans++;
				}
			}
		}
		cout << "Case #" << t << ": " << ans << endl;
	}
}

