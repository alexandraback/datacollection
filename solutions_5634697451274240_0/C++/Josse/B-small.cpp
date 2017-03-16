#include <iostream>
#include <cassert>
#include <string>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX_LEN = 10;

int d[1 << MAX_LEN];
unsigned l;

string toString(int n) {
	string ret;
	for (unsigned i = 0; i < l; i++) {
		ret.push_back(n % 2 == 0 ? '+' : '-');
		n /= 2;
	}
	assert(n == 0);
	return ret;
}

int solve() {
	string S;
	cin >> S;
	l = S.size();
	assert(l >= 1 && l <= MAX_LEN);
	memset(d, -1, sizeof d);
	int s = 0;
	for (unsigned i = 0; i < l; i++) {
		s += (1 << i) * (S[i] == '-' ? 1 : 0);
	}
	d[s] = 0;
	queue<int> q;
	q.push(s);
	while (!q.empty() && d[0] == -1) {
		int cur = q.front();
		q.pop();
		int bitmask = (1 << l) - 1;
		for (unsigned i = 0; i < l; i++) {
			bitmask ^= (1 << i);
			int n = cur & bitmask;
			for (unsigned j = 0; j <= i; j++) {
				n |= (1 << j) * ((cur & (1 << (i - j))) == 0 ? 1 : 0);
			}
			//cerr << "  flipping first " << (i + 1) << " pancakes in stack " << toString(cur) << " yields " << toString(n) << endl;
			if (d[n] == -1) {
				d[n] = d[cur] + 1;
				q.push(n);
			}
		}
	}
	return d[0];
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
