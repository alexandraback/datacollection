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

int t, n, ans, tans, x;
string s;

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	cin >> t;
	for (int j = 0; j < t; j++) {
		cin >> n;
		vector<int> v;
		for (int i = 0; i < n; i++) {
			cin >> x;
			v.push_back(x);
		}
		tans = 1000000007;
		for (int i = 1; i <= 1000; i++) {
			ans = i;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] > i) {
					ans += (v[j] - i) / i;
					if ((v[j] - i) % i)
						ans++;
				}
			}
			tans = min(ans, tans);
		}
		cout << "Case #" << j + 1 << ": " << tans << endl;
	}

	return 0;
}