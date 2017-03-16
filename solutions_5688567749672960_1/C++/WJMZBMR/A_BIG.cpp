#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <sstream>
using namespace std;

typedef long long int64;

int64 rev(int64 u) {
	ostringstream oss;
	oss << u;
	string U = oss.str();
	reverse(U.begin(), U.end());
	return atoll(U.c_str());
}

int main() {
	int T;
	cin >> T;
	for (int nc = 1; nc <= T; ++nc) {
		int64 x, d = 0;
		cin >> x;
		while (x != 0) {
			if (x % 10 == 0)
				--x, ++d;
			if (x < 10) {
				d += x;
				break;
			}
			ostringstream oss;
			oss << x;
			string U = oss.str();
			int len = U.size() / 2;
			int64 pw = 1;
			for (int j = 0; j < len; ++j) {
				pw *= 10;
			}
			int64 to = x - (x % pw) + 1;
			d += x - to;
			x = to;
			if (rev(x) < x)
				x = rev(x), ++d;
			pw = 1;
			for (int j = 0; j < U.size() - 1; ++j) {
				pw *= 10;
			}
			d += x - pw;
			x = pw;
			--x, ++d;
		}
		printf("Case #%d: %lld\n", nc, d);
	}
}
