#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <map>
using namespace std;

string calc(int N, int M, const vector<int> &K) {
	map<int, int> num;

	for (int k : K) {
		if (k % 5 == 0) {
			num[5] = max(num[5], 1);
			k /= 5;
			if (k % 5 == 0) {
				k /= 5;
				num[5] = max(num[5], 2);
				if (k != 1)
					return string("55") + char('0' + k);
			}
			if (k % 3 == 0) {
				k /= 3;
				num[3] = max(num[3], 1);
				if (k != 1)
					return string("53") + char('0' + k);
			}
		}
		if (k % 3 == 0) {
			k /= 3;
			num[3] = max(num[3], 1);
			if (k % 3 == 0) {
				k /= 3;
				num[3] = max(num[3], 2);
				if (k != 1)
					return string("33") + char('0' + k);
			}
		}
		if (num[5] == 2) {
			if (num[3] == 1)
				return "553";
			if (k % 2 == 0)
				return string("55") + char('0' + k);
		}
		if (num[5] == 1) {
			if (num[3] == 2)
				return "533";
		}
	}
	return "222";
}

void solve(istream &in, ostream &out) {
	int T;
	in >> T;

	for (int t = 1; t <= T; ++t) {
		int R, N, M, K;
		in >> R >> N >> M >> K;
		out << "Case #" << t << ":" << endl;
		for (int r = 0; r < R; ++r) {
			vector<int> k(K);
			for (int i = 0; i < K; ++i)
				in >> k[i];
			out << calc(N, M, k) << endl;
		}
	}
}

int main() {
	solve(cin, cout);
	return 0;
}

