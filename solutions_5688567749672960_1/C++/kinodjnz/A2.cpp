#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <map>
#include <set>
#include <string.h>

typedef long long ll;
using namespace std;

int digits(ll N) {
	int d = 0;
	while (N > 0) {
		d++;
		N /= 10;
	}
	return d;
}

ll flip(ll x) {
	ll r = 0;
	while (x > 0) {
		r *= 10;
		r += x%10;
		x /= 10;
	}
	return r;
}

ll solve(ll N) {
	ll ans = 0;
	while (N >= 10) {
		int d = digits(N);
		int s = (d+1)/2;
		ll mask = 1;
		for (int i = 0; i < s; i++)
			mask *= 10;
		if (N % mask == 1 && (N / mask != mask / 10 && N / mask != mask / 100)) {
			//printf("N=%lld\n", N);
			N = flip(N);
		} else {
			N--;
		}
		ans++;
	}
	return ans + N;
}

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++) {
		ll N;
		cin >> N;
		ll ans = solve(N);
		cout << "Case #" << i+1 << ": " << ans << endl;
	}
}
