#include <iostream>
#include <fstream>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;


int main() {
	ios_base::sync_with_stdio(false);
	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int n;
		cin >> n;
		string s;
		cin >> s;

		int people = 0;
		int ans = 0;
		for (int i = 0; i <= n; i++) {
			int cur = s[i] - '0';
			if (i <= people) {
				people += cur;
			}
			else if (cur > 0) {
				ans += i - people;
				people = i + cur;
			}
		}

		cout << "Case #" << test << ": " << ans << endl;
	}



	//system("pause");
	return 0;
}