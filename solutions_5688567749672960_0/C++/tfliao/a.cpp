#include <iostream>
using namespace std;

typedef unsigned long long ULL;

int digits(ULL x) {
	int c = 1;
	while (x >= 10) { x/=10, c++; }
	return c;
}

ULL rev(ULL x) {
	ULL r = 0;
	while (x) { r = (r * 10) + (x % 10); x /= 10; }
	return r;
}

ULL pow10[16] = {};

void init() {
	pow10[0] = 1;
	for (int i=1;i<16;++i) pow10[i] = pow10[i-1] * 10;
}

ULL solv(ULL n)
{
	if (n <= 10) return n;
	int d = digits(n);
	ULL cost = 10;
	for (int i=2; i<d;++i) {
		cost += pow10[i/2] + pow10[(i+1)/2] - 1;
	}

	ULL r = rev(n);
	ULL ma = d/2, mb = (d+1)/2;

	ULL a = r % pow10[ma];
	ULL b = n % pow10[mb];

	cerr << cost << ", " << a << ", " << b << endl;

	if (b)
		cost += b + (a > 1? a: 0);
	else if (a>1){
		while (b==0) {
			ma --, mb++;
			b = n % pow10[mb];
		}
		a = r % pow10[ma+1] - pow10[ma];
		b = pow10[mb-1];
		if (a > 1) {
			cost += b + (a);
		} else {
			cost += b;
		}

	}
	cerr << cost << ", " << a << ", " << b << endl;

	return cost;
}


int main()
{
	int T, nCase = 1;
	ULL N;
	init();
	cin >> T;
	for (nCase = 1; nCase <= T; nCase ++) {
		cin >> N;
		cerr << "Q: " << N << endl;
		cout << "Case #" << nCase << ": " << solv(N) << endl;
	}

	return 0;
}

