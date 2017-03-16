#include <bits/stdc++.h>

using namespace std;

long long reverse(long long a) {
	long long res = 0;
	while (a > 0) {
		res *= 10;
		res += a % 10;
		a /= 10;
	}
	return res;
}

bool isReversable(long long a) {
	return !(a%10 == 0);
}


long long f(long long a) {
	long long cnt = 0;
	while (a > 0) {
		long long rev = reverse(a);
		if (isReversable(a) && rev < a)
			a = rev;
		else
			a --;
		cnt++;
	}
	return cnt;
}

int main() {
	freopen("counter-big.in", "r", stdin);
	freopen("counter-big.out", "w", stdout);
	int t;
	cin >>t;
	for (int q = 1; q <= t; q++) {
		long long n;
		cin >> n;
		cout <<"Case #"<<q<<": "<<f(n)<<'\n';
	}
}