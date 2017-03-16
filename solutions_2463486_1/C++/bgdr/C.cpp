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
void make_pal(ll x, ll & p1, ll &p2){
	char digits[100];
	int d = 0;
	ll _x = x;
	while(x) { digits[d++] = x % 10; x /= 10; }
	p1 = p2 = _x;
	p2 = p2 * 10 + digits[0];
	for(int i = 1; i < d; ++i) {
		p1 = (p1 * 10 + digits[i]);
		p2 = (p2 * 10 + digits[i]);
	}
}
ll count_large1(ll n){
	ll p1, p2;
	ll ans = 0;
	for(ll d = 1; ; d++){
		make_pal(d, p1, p2);
		if(p1 * p1 > n) break;
		if(is_pal(p1 * p1)) ans++;
		if(p2 * p2 <= n && is_pal(p2 * p2)) ans++;
	}
	return ans;
}
int main(){
	int T;
	ll A, B;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> A >> B;
		cout << "Case #" << cs << ": " << count_large1(B) - count_large1(A - 1) << endl;
	}
	return 0;
}
