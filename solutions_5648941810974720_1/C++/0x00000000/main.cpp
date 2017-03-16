#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <string>
#include <tuple>
#include <queue>
#include <utility>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <limits>
#include <new>
#include <functional>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main(void) {
	cin.tie(nullptr);
	cin.sync_with_stdio(false);

	int t;
	cin >> t;
	for (int k = 0; k < t; k++) {
		string a;
		cin >> a;
		vector<int> count(10, 0);
		string c = "ZOWHRVXSGN";
		for (auto &x : a) {
			for (int i = 0; i < 10; i++) {
				if (x == c[i]) {
					count[i]++;
					break;
				}
			}
		}
		vector<int> vals(10, 0);
		vals[0] = count[0];
		vals[1] = count[1] - count[2] - count[4] + count[3] - count[8];
		vals[2] = count[2];
		vals[3] = count[3] - count[8];
		vals[4] = count[4] - count[3] + count[8] - count[0];
		vals[5] = count[5] - count[7] + count[6];
		vals[6] = count[6];
		vals[7] = count[7] - count[6];
		vals[8] = count[8];
		vals[9] = (count[9] - count[7] + count[6] - count[1] + count[2] + count[4] - count[3] + count[8]) / 2;
		cout << "Case #" << k + 1 << ": ";
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < vals[i]; j++) {
				cout << i;
			}
		}
		cout << endl;
	}

	return 0;
}