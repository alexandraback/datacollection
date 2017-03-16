#include<iostream>
using namespace std;
typedef long long ll;

inline bool is_pal(ll x){
	char digits[100];
	int d = 0;
	while(x) { digits[d++] = x % 10; x /= 10; }
	for(int i = 0; i < d; ++i)
		if(digits[i] != digits[d - 1 - i]) return false;
	return true;
}
ll count_small(ll n){
	ll ans = 0;
	for(ll d = 1; d * d <= n; ++d){
		if(is_pal(d) && is_pal(d * d)) ans++;
	}
	return ans;
}
int main(){
	int T;
	ll A, B;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> A >> B;
		cout << "Case #" << cs << ": " << count_small(B) - count_small(A - 1) << endl;
	}
	return 0;
}
