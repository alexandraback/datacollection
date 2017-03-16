#include <iostream>
#include <vector>
using namespace std;
int testcases;
int k, c, s;
int ans;
vector<long long> v;

int main() {
	cin >> testcases;
	for (int testcase = 0; testcase < testcases; testcase ++) {
		cin >> k >> c >> s;
		ans = (k - 1) / c + 1;

		v.clear();

		int now = 0;
		for (int i = 0; i < ans; i ++) {
			if (i == ans - 1) {
				now = k - c;
				if (now < 0) now = 0;
			}
			long long index = 0;
			for (int j = 0; j < c; j ++) {
				index = index * k + now;
				now ++;
				if (now >= k) now = k - 1;
			}
			v.push_back(index + 1);
		}

		cout << "Case #" << testcase + 1 << ":";
		if (ans > s) {
			cout << " IMPOSSIBLE";
		} else {
			for (int i = 0; i < v.size(); i ++) {
				cout << " " << v[i];
			}
		}

		cout << endl;
	}
	return 0;
}