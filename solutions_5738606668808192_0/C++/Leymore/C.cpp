#include <bits/stdc++.h>

using namespace std;

const int N = 16;
const int J = 50;

typedef long long ll;

unsigned is_prime(ll x) {
	ll m = sqrt(sqrt(sqrt(x)));
	for(unsigned p = 2; p <= m; p ++)
		if(x % p == 0) return p;
	return 0;
}

unsigned Check(unsigned i, ll b) {
	ll x = 0, a = 1;
	while(i) {
		x = x + (i%2)*a;
		a *= b;
		i /= 2;
	}
	return is_prime(x);
}

void print(unsigned i) {
	if(!i) return;
	print(i / 2);
	printf("%d", i % 2);
}

bool check(unsigned i) {
	bool ok = 1;
	unsigned p[11];
	for(int b = 2; b <= 10 && ok; b ++) {
		p[b] = Check(i, b);
		if(!p[b]) ok = 0;
	}
	if(ok) {
		print(i);
		for(int b = 2; b <= 10; b ++)
			printf(" %u", p[b]);
		printf("\n");
	}
	return ok;
}

int main() {
//	freopen("C.in", "r", stdin);
	freopen("C.out", "w", stdout);
	printf("Case #1:\n");
	for(unsigned i = (1 << (N-1)) + 1, c = 0; c < J; i += 2) {
		if(check(i)) c ++;
	}
	
	return 0;
}
