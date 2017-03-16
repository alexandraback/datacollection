#include <iostream>
#include <cmath>
using namespace std;

typedef long long ll;

bool palindrome(ll i) {
	ll ic = i, rev = 0;
	while(i > 0) {
		rev = rev * 10 + i % 10;
		i /= 10;
	}
	return rev == ic;
}

bool check(ll i) {
	return palindrome(i) && palindrome(i*i);
}

void test(int tn) {
	cout << "Case #" << tn << ": ";
	ll a, b;
	cin >> a >> b;
	ll start_sq = sqrt(a), end_sq = sqrt(b), cnt = 0;
	for (ll i = start_sq; i <= end_sq; i++)
		if(i * i >= a && i * i <= b && check(i))
			cnt++;
	cout << cnt << "\n";
}

int main() {
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
		test(i+1);
}
