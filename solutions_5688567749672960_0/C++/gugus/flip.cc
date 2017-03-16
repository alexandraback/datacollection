#include <pe.h>

vector<ll> mem(1000001);

ll reverse(ll N) {
	ll r = 0;
	while (N!=0) {
		r = 10*r + (N%10);
		N = N/10;
	}
	return r;
}


int main() {
	for (ll i = 0; i < 1000001; ++i) {
		mem[i] = 1e8;
	}
	mem[1] = 1;
	for (ll i = 2; i < 1000001; ++i) {
		if (i%10==0) {
			mem[i] = mem[i-1]+1;
		}
		else {
			mem[i] = 1+min(mem[i-1], mem[reverse(i)]);
		}
	}
	ll T;
	cin >> T;
	ll N;
	for (ll i = 0; i < T; ++i) {
		cin >> N;
		printf("Case #%Ld: %Ld\n", i+1, mem[N]);
	}
	return 0;
}

