#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <iostream>
#include <algorithm>
#include <stdint.h>
#include <string>
using namespace std;

int main() {
#ifdef _DEBUG
	FILE* fp;
	freopen_s(&fp, "input.txt", "r", stdin);
#endif

	int T;
	cin >> T;
	for (int t = 1; t <= T; t++) {
		int Smax;
		string S;
		cin >> Smax >> S;

		int result = 0;
		int sum = 0;
		for (int i = 0; i <= Smax; i++) {
			if (S[i] != '0') {
				if (sum < i) {
					result += i - sum;
					sum = i;
				}
				sum += S[i] - '0';
			}
		}
		cout << "Case #" << t << ": " << result << endl;
	}

	return 0;
}
