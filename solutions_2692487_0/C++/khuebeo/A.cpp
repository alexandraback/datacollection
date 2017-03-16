#include <iostream>
#include <cstring>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
using namespace std;

int a, n;
int s[111];

int process() {
	int res = 1000000000;
	sort(s, s + n);
	for (int fdel = 0; fdel <= n; fdel++) {
		int i = 0;
		int curr = a;
		bool success = true;
		int nadd = 0;
		while (i < fdel) {
			if (curr > s[i]) curr += s[i];
			else {
				if (curr == 1) {
					success = false;
					break;
				}
				while (curr <= s[i]) {
					nadd++;
					curr = curr * 2 - 1;
				}
				curr += s[i];
			}
			i++;
		}
		if (success && n - fdel + nadd < res) {
			res = n - fdel + nadd;
		}

	}
	return res;
}

int main() {
	freopen("A-small-attempt2.in", "r", stdin);
	freopen("A-small-attempt2.out", "w", stdout);
	int ntest;
	cin >> ntest;

	for (int itest = 0; itest < ntest; itest++) {
		cin >> a >> n;
		for (int i = 0; i < n; i++) cin >> s[i];
		cout << "Case #" << itest+1 << ": " << process() << endl;
	}

}
