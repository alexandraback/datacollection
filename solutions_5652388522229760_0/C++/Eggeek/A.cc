#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void insert(ll& s, ll num) {
	while (num) {
		ll v = num % 10;
		s |= 1 << v;
		num /= 10;
	}
}

void print_b(ll s) {
	while (s) {
		printf("%lld", s%2);
		s /= 2l;
	}
	printf("\n");
}

void solve(ll n) {
	ll s = 0;
	ll sum = n;
	insert(s, sum);
	int times = 0;
	while (s != (1<<10)-1) {
		sum += n;	
		times++;
		insert(s, sum);
		if (times > 1000000) break;
	}
	if (s == (1<<10) - 1) {
		cout << sum << endl;
	}
	else {
		cout << "INSOMNIA" << endl;
	}
}

int main() {

	int cas;
	cin >> cas;
	for (int i=1; i<=cas; i++) {
		ll n;
		cin >> n;
		printf("Case #%d: ", i);
		solve(n);
	}
	return 0;
}
