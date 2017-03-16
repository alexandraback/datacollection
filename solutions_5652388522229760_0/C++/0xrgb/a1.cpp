#include <iostream>
#include <string>
#include <etc/cppformat/format.cc>

using namespace std;

long long solve(long long);

int main() {
	ios::ios_base::sync_with_stdio(false);

	int tc;
	cin >> tc;

	for(int i = 1 ; i <= tc ; ++i) {
		int x;
		cin >> x;

		long long ans = solve(x);

		if( ans > 0 ) {
			cout << fmt::format("Case #{}: {}", i, ans) << endl;
		} else {
			cout << fmt::format("Case #{}: INSOMNIA", i) << endl;
		}
	}

	return 0;
}

long long solve(long long x) {
	if( x <= 0 ) {
		return -1;
	}

	unsigned int v = 0;

	for(long long k = x ; ; k += x ) {
		long long l = k;

		while(l > 0) {
			v |= (1U << (l%10));
			l /= 10;
		}

		if( v == 0b11'1111'1111 ) {
			return k;
		}
	}

	return -1;
}