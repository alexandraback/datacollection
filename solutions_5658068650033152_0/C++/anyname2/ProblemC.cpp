#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

void increase(int* curWidth, int* curHeight, int n, int m) {
	if (*curWidth > *curHeight) {
		if (*curHeight < m) {
			*curHeight += 1;
		} else {
			*curWidth += 1;
		}
	} else {
		*curWidth += 1;
	}
}

int main(void) {
	ios_base::sync_with_stdio(false), cin.tie(0);
	freopen("ProblemC.in", "r", stdin);
	freopen("ProblemC.out", "w", stdout);

	int T;
	cin >> T;
	for (int test = 0; test < T; test++) {
		cout << "Case #" << test + 1 << ": ";
		int n, m, k;
		cin >> n >> m >> k;
		if (k <= 4 || n <= 2 || m <= 2) {
			cout << k;
		} else if (k >= n*m - 4) {
			cout << k + 4 - (n*m) + (2 * (n + m) - 8);
		} else {
			if (n < m) swap(n, m); // n is greater
			int curHeight = 0, curWidth = 0;
			for (int i = 3; i <= m; i++) if (i*i > k) {
				curHeight = i - 1, curWidth = i - 1;
				break;
			}
			k += 4;
			while (k - curWidth*curHeight > 2) {
				increase(&curWidth, &curHeight, n, m);
			}
			cout << k - curWidth*curHeight + (2 * (curHeight + curWidth) - 8);
		}
		cout << "\n";
	}

	cout.flush();
	fclose(stdin);
	fclose(stdout);
	return 0;
}
