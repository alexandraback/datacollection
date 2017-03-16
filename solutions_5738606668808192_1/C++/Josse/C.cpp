#include <iostream>
#include <cassert>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

const long long MAX_LEN = 1000000000000000000ll;

long long N, J;

string toString(long long K) {
	string ret;
	while (K) {
		ret.push_back('0' + (K & 1));
		K >>= 1;
	}
	if (ret.empty()) ret.push_back('0');
	reverse(ret.begin(), ret.end());
	assert((int) ret.size() == N);
	assert(ret[0] == '1');
	assert(ret[N - 1] == '1');
	return ret;
}

long long toBase(const string& s, long long base) {
	long long ret = 0;
	long long pow = 1;
	for (string::const_reverse_iterator it = s.rbegin(); it != s.rend(); it++) {
		ret += pow * (*it - '0');
		pow *= base;
		assert(pow >= 1 && pow <= MAX_LEN);
		assert(ret >= 0 && ret < pow);
	}
	return ret;
}

void solve() {
	cin >> N >> J;
	assert(N >= 4 && N <= 32);
	assert(N % 2 == 0); // solutions do exist if N is odd, but those will not be constructed by this program
	assert(J >= 1 && J <= (1ll << ((N / 2) - 2))); // more solutions exist (for larger J), but those will not be constructed by this program
	set<long long> solutions;
	for (long long i = 0; i < J; i++) {
		long long a = 1ll << ((N / 2) - 1);
		long long b = i << 1;
		long long c = 1;
		assert((a & b) == 0);
		assert((a & c) == 0);
		assert((b & c) == 0);
		long long x = a | b | c;
		long long y = x << (N / 2);
		assert((x & y) == 0);
		long long z = x | y;
		assert(z < (1ll << N));
		assert(solutions.insert(z).second);
	}
	assert((int) solutions.size() == J);
	for (set<long long>::iterator it = solutions.begin(); it != solutions.end(); it++) {
		string cur = toString(*it);
		cout << cur;
		assert((int) cur.size() == N);
		for (int i = 0; i < N / 2; i++) {
			assert(cur[i] == cur[i + N / 2]);
		}
		cur.resize(N / 2);
		for (int b = 2; b <= 10; b++) {
			cout << " " << toBase(cur, b);
		}
		cout << endl;
	}
}

int main() {
	int T;
	cin >> T;
	assert(T == 1);
	for (int i = 1; i <= T; i++) {
		cout << "Case #" << i << ":" << endl;
		solve();
	}
	return 0;
}
