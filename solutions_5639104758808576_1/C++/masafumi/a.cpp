#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <utility>
#include <string>

using namespace std;

int main() {
	int t, a, people, invite, stand;
	string s;

	cin >> t;
	vector<int> ans(t, 0);

	for (int i = 0; i < t; i++) {
		cin >> a >> s;

		stand = 0;
		for (int j = 0; j <= a; j++) {
			people = s[j] - '0';
			if (people == 0) {
				continue;
			}

			if (j > stand) {
				invite = j - stand;
				stand += invite;
				ans[i] += invite;
			}
			stand += people;
		}
	}

	for (int i = 0; i < t; i++) {
		printf("Case #%d: %d\n", i + 1, ans[i]);
	}
	return 0;
}
