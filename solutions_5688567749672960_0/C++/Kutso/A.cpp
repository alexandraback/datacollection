#include <iostream>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#include <string>
#include <vector>
#include <cmath>
#include <cstdio>
#include <cstring>

using namespace std;

const long long NMAX = 1000002;

int fix[NMAX];

int reversenum(int x) {
	vector <int> digs;
	while (x) {
		digs.push_back(x % 10);
		x /= 10;
	}

	int ret = 0;
	for (int i = 0; i < digs.size(); i++) {
		ret *= 10;
		ret += digs[i];
	}

	return ret;
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	vector <int> nums();

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		int ans = 0;
		int n;
		cin >> n;

		queue <int> q;
		q.push(0);
		memset(fix, 0, sizeof(fix));

		fix[0] = 1;


		while (!q.empty()) {
			int temp = q.front();
			q.pop(); 
			if (temp == n)
				break;

			temp++;
			if (temp <= n && !fix[temp]) {
				fix[temp] = fix[temp - 1] + 1;
				q.push(temp);
			}

			temp--;
			int x = temp;
			temp = reversenum(temp);
			if (temp <= n && !fix[temp]) {
				fix[temp] = fix[x] + 1;
				q.push(temp);
			}
		}
		
		ans = fix[n] - 1;
		cout << "Case #" << test << ": " << ans << endl;
	}

	return 0;
}