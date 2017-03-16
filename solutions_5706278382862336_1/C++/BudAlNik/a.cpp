#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;

int t;
long long p, q;

long long gcd(long long a, long long b) {
	if (b == 0) {
		return a;
	}
	return gcd(b, a % b);
}

int main() {
	cin >> t;
	for (int i = 0; i < t; ++i) {
		//cin >> p >> q;
		scanf("%lld/%lld\n", &p, &q);
		long long tmp = gcd(p, q);
		p /= tmp;
		q /= tmp;
		if (q & (q - 1)) {
			cout << "Case #" << i + 1 << ": impossible" << endl;
			continue;
		}
		long long temp = p;
		int c = 0;
		while (temp < q) {
			c++;
			temp *= 2;
		}
		
		cout << "Case #" << i + 1 << ": " << c << endl;
	}
	
	return 0;
}
