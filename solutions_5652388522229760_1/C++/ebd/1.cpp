#include <iostream>
#include <cassert>
using namespace std;

int f(int n) {
	if(n == 0) return -1;
	int mask = (1 << 10) - 1;
	int ml = 0;
	while(mask) {
		int t = n * ++ml;
		while(t) {
			mask &= ~(1 << (t%10));
			t /= 10;
		}
	}
	return n * ml;
}

int main() {
	int T, N, res;
	cin >> T;
	for(int cs = 1; cs <= T; ++cs) {
		cin >> N;
		cout << "Case #" << cs << ": ";
		res = f(N);
		if(res < 0) cout << "INSOMNIA";
		else cout << res;
		cout << endl;
	}
	return 0;
}