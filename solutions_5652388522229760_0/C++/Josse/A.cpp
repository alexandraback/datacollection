#include <iostream>
#include <cstdio>
#include <cassert>
#include <string>
#include <cstring>

using namespace std;

string toString(long long K) {
	char tmp[30];
	sprintf(tmp, "%lld", K);
	return string(tmp);
}

int sees(long long K) {
	char tmp[30];
	sprintf(tmp, "%lld", K);
	unsigned l = strlen(tmp);
	int ret = 0;
	for (unsigned i = 0; i < l; i++) {
		ret |= (1 << (tmp[i] - '0'));
	}
	return ret;
}

string solve() {
	long long N;
	cin >> N;
	assert(N >= 0 && N <= 1000000);
	if (N == 0) return "INSOMNIA";
	int seen = sees(N);
	long long K = N;
	while (seen != 1023) {
		K += N;
		assert(K <= 1000000000000000000ll);
		seen |= sees(K);
	}
	return toString(K);
}

int main() {
	int T;
	cin >> T;
	assert(T >= 1 && T <= 100);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ": " << solve() << endl;
	}
	return 0;
}
