#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

typedef long long ll;
const ll max_sqr = 10000000; // 10^7

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
vector<ll> nums;
void prepare() {
	for (ll i = 1; i <= max_sqr; i++)
		if(check(i))
			nums.push_back(i*i);
}

void test(int tn) {
	cout << "Case #" << tn << ": ";
	ll a, b;
	cin >> a >> b;
	ll res = 0;
	for (int i = 0; i < nums.size(); i++)
		if(nums[i] > b) break;
		else if(nums[i] >= a) res++;
	cout << res << "\n";
}

int main() {
	prepare();
	int tc;
	cin >> tc;
	for (int i = 0; i < tc; i++)
		test(i+1);
}
