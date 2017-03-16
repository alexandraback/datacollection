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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);

	ifstream cin("input.txt");
	ofstream cout("output.txt");

	int tests;
	cin >> tests;
	for (int test = 1; test <= tests; test++) {
		int d;
		cin >> d;
		vector<int> p(d);
		for (int i = 0; i < d; i++) {
			cin >> p[i];
		}
		sort(p.begin(), p.end());

		int ans = p.back();
		for (int i = 1; i <= 1000; i++) {
			int curAns = i;
			for (int j = 0; j < d; j++) {
				curAns += (p[j] + i - 1) / i - 1;
			}
			ans = min(ans, curAns);
		}

		cout << "Case #" << test << ": " << ans << endl;
	}

	//system("pause");
	return 0;
}