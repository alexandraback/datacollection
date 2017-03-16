#include <iostream>
#include <cassert>
using namespace std;

void nxt(int &a) {
	do { ++a; if (__builtin_popcount(a) == 2) return; } while (true);
}

long long num_base(string s, int x, int mod) {
	long long k = 1, ans = 0;
	for (int i = (int)s.length() - 1; i >= 0; --i) {
		ans = (ans + k * (s[i] - '0')) % mod; k = k * x % mod;
	}
	return ans;
}

int main() {
	int T, N, J; cin >> T >> N >> J;
	cout << "Case #1:\n";
	// number of 1 divisible by 6 => 6 digits 1
	// even pos = odd pos 
	int even = 3, odd = 3;
	while (J--) {
		string s = "1"; 
		int _odd = odd, _even = even; nxt(odd); 
		if (odd >= (1 << (N - 2) / 2)) odd = 3, nxt(even);
		for (int i = 1; i < N - 1; ++i) { 
			if (i % 2) s += char('0' + _odd % 2), _odd /= 2; else s += char('0' + _even % 2), _even /= 2; 
		}
		s += "1"; for (int i = N - 1; i >= 0; --i) cout << s[i]; cout << ' ';
		for (int i = 2; i <= 10; ++i) {
			if (i == 6) cout << 7 << ' ', assert(!num_base(s, i, 7));
			else cout << 3 - i % 2 << ' ', assert(!num_base(s, i, 3 - i % 2)); 
		}
		cout << endl;
	}
}