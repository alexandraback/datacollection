#include <iostream>
#include <set>
#include <vector>
#include <deque>
#include <stack>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <climits>
#include <ctime>
#include <cassert>
#include <bitset>

using namespace std;

int t, n, ans, sum;
string s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n >> s;
		sum = ans = 0;
		for (int i = 0; i < n + 1; i++) {
			if (sum < i) {
				ans += (i - sum);
				sum = i;
			}
			sum += s[i] - '0';
		}
		cout << "Case #" << j + 1 << ": " << ans << endl;
	}

	return 0;
}