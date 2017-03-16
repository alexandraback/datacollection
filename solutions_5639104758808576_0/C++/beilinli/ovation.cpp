#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

int main(void) {
	freopen(	"A-small-attempt0.in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int T;
	cin >> T;

	for (int t = 1; t <= T; t++) {
		int smax;
		string s;
		cin >> smax >> s;
		
		int total = 0, add = 0, n = s.size();

		for (int i = 0; i < n; i++) {
			if (total < i) {
				add += (i - total);
				total += (i - total);
			}
			total += (s[i] - '0');
		}

		printf("Case #%d: %d\n", t, add);
	}
	return 0;
}
