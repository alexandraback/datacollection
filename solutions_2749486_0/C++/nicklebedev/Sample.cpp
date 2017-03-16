#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

#define ll long long

int main() {
	freopen("B-small-attempt0.in", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests, x, y;
	scanf("%d", &tests);

	char str[10000];

	for (int t = 1; t <= tests; t++) {
		scanf("%d %d", &x, &y);

		int cx = 0, cy = 0;
		int curr = 1;
		int ind = 0;
		
		while (cx != x) {
			cx += curr;

			if (curr > 0) {
				curr++;
				str[ind++] = 'E';
			}
			else {
				curr--;
				str[ind++] = 'W';
			}

			curr *= -1;
		}

		curr = (y > 0 ? (abs(curr) * -1) : abs(curr));

		while (cy != y) {
			cy += curr;

			if (curr > 0) {
				curr++;
				str[ind++] = 'N';
			}
			else {
				curr--;
				str[ind++] = 'S';
			}

			curr *= -1;
		}

		str[ind] = 0;

		printf("Case #%d: %s\n", t, str);
	}
	
	return 0;
}
