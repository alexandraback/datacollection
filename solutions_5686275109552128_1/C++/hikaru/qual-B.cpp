#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
#include <set>
using namespace std;
vector<int> P;

int main(int argc, char* argv[])
{
	if (argc > 1) {
		FILE* fp;
		freopen_s(&fp, argv[1], "r", stdin);
	}

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int D;
		cin >> D;
		P.clear();
		for (int i = 0; i < D; i++) {
			int n;
			cin >> n;
			P.push_back(n);
		}

		
		int m = *max_element(P.begin(), P.end());
		int result = m;
		while (--m > 1) {
			int sum = m;
			for (int v : P) {
				if (v > m) {
					sum += (v + m - 1) / m - 1;
					if (sum >= result) break;
				}
			}
			if (sum < result) result = sum;
		}
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
