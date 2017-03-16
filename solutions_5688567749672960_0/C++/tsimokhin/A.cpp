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

const int MAXN = 1e6;

long long mem[MAXN];
bool isMem[MAXN];

long long f(long long a) {
	if (a == 0)
		return 0;
	if (a < 0)
		return 0;
	if (!isMem[a]) {
		long long rev = reverse(a);
		if (rev >= a || !isReversable(a))
			mem[a] = f(a - 1) + 1;
		else
			mem[a] = min(f(a-1), f(rev)) + 1;
		isMem[a] = true;
	}
	return mem[a];
}

int main() {
	freopen("counter-small.in", "r", stdin);
	freopen("counter-small.out", "w", stdout);
	int t;
	cin >>t;
	for (int q = 1; q <= t; q++) {
		long long n;
		cin >> n;
		cout <<"Case #"<<q<<": "<<f(n)<<'\n';
	}
}