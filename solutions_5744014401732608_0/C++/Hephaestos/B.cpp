#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

using ull = unsigned long long;


string SolveB(int B, ull M) {
	ostringstream oss;
	ull x = M;
	ull y = x - 1;
	x = (x >> (B - 2));
	y = (y >> (B - 2));
	if (y > 0) {
		oss << "IMPOSSIBLE";
	}
	else {
		oss << "POSSIBLE" << endl;
		vector<bool> sol(B,false);
		if (x == 1) {
			sol[0] = true;
			--M;
		}
		for (int i = 1;i < B-1;++i) {
			if (M % 2 == 1) {
				sol[i] = true;
			}
			M = M >> 1;
		}
		for (int i = 0;i < B;++i) {
			for (int j = 0;j < B-1;++j) {
				oss << (j > i)? '1' : '0';
			}
			oss << sol[i] << (i != B - 1 ? "\n" : "");
		}
	}
	return oss.str();
}

void main() {

	int T;
	cin >> T;
	for (int i = 0;i < T;++i) {
		int B;
		ull M;
		cin >> B >> M;
		cout << "Case #" << i + 1 << ": " << SolveB(B,M) << endl;
	}
}