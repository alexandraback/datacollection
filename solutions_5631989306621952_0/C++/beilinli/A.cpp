#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <utility>
#include <sstream>
using namespace std;

int main(void) {
	freopen("A-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int T;
	string S;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		cin >> S;
		int n = S.size();
		string ans;

		for (int i = 0; i < n; i++) {
			string A = S[i] + ans;
			string B = ans + S[i];

			if (A.compare(B) > 0)
				ans = A;
			else 
				ans = B;
		}

		cout << "Case #" << t << ": " << ans << '\n';
	}
	return 0;
}
