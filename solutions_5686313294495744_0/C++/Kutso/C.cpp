#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <map>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <cstdio>

using namespace std;

const int NMAX = 100100;

int main() {

	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int t;
	cin >> t;
	for (int test = 1; test <= t; test++) {
		printf("Case #%d: ", test);
		int n;
		cin >> n;
		vector <string> s1(n);
		vector <string> s2(n);
		for (int i = 0; i < n; i++) {
			cin >> s1[i] >> s2[i];
		}

		int ans = -1;
		for (int i = 0; i < (1 << n); i++) {
			int bitcount = 0;
			bool flag = true;
			for (int k = 0; k < n; k++) {
				if ((1 << k) & i)
					continue;
				bitcount++;
				bool valid = false;
				for (int j = 0; j < n; j++)
					if ((1 << j) & i) {
						if (s1[j] == s1[k]) {
							valid = true;
							break;
						}
					}
				if (!valid) {
					flag = false;
					break;
				}
				valid = false;
				for (int j = 0; j < n; j++)
					if ((1 << j) & i) {
						if (s2[j] == s2[k]) {
							valid = true;
							break;
						}
					}
				if (!valid) {
					flag = false;
					break;
				}
			}
			if (flag && (ans == -1 || bitcount > ans))
				ans = bitcount;
		}

		printf("%d\n", ans);
	}


	return 0;
}