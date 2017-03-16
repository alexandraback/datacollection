#define _CRT_SECURE_NO_DEPRECATE

#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	
	int T;
	cin >> T;
	for (int prob = 1; prob <= T; prob++) {
		int N;
		cin >> N;

		int input[50*100];
		int count[2505] = { 0 };
		int size = (2 * N - 1) * N;
		for (int i = 0; i < size; ++i) {
			cin >> input[i];
			++count[input[i]];
		}
		vector<int> res;
		int resCount = 0;
		for (int i = 1; i <= 2500; ++i) {
			if (count[i] % 2) {
				res.push_back(i);
				++resCount;
			}
		}
		sort(res.begin(), res.end());

		cout << "Case #" << prob << ":";
		for (int i = 0; i < resCount; ++i)
			cout << " " << res[i] << ' ';
		cout << endl;
	}
	return 0;
}
