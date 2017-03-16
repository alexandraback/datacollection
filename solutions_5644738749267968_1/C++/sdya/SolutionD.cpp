#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <bitset>
#include <queue>
#include <cstring>
#include <string>
#include <cmath>
#include <ctime>
#pragma comment (linker, "/STACK:256000000")

using namespace std;

const int maxN = 1100;
double a[maxN], b[maxN];
int n;

int calcWarGame() {
	vector < bool > used(n, false);
	int scoreA = 0;
	for (int i = 0; i < n; ++i) {
		bool beaten = false;
		for (int j = 0; j < n; ++j) {
			if (!used[j] && b[j] > a[i]) {
				beaten = true;
				used[j] = true;
				break;
			}
		}
		if (!beaten) {
			++scoreA;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					used[j] = true;
					break;
				}
			}
		}
	}

	used.assign(n, false);
	int scoreB = 0;
	for (int i = n - 1; i >= 0; --i) {
		bool beaten = false;
		for (int j = 0; j < n; ++j) {
			if (!used[j] && b[j] > a[i]) {
				beaten = true;
				used[j] = true;
				break;
			}
		}
		if (!beaten) {
			++scoreB;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					used[j] = true;
					break;
				}
			}
		}
	}
	return max(scoreA, scoreB);
}

int calcDWarGame() {
	reverse(a, a + n);
	if (fabs(b[n - 1] - 1.0) < 1e-9) {
		--n;
	}
	reverse(a, a + n);
	int res = 0;

	for (int x = 0; x <= n; ++x) {
		vector < bool > used(n, false);
		int current = 0;
		for (int i = 0; i < x; ++i) {
			bool beaten = false;
			for (int j = n - 1; j >= 0; --j) {
				if (b[j] > a[i] && !used[j]) {
					used[j] = true;
					beaten = true;
					break;
				}
			}
			if (!beaten) {
				++current;
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		for (int i = n - 1; i >= x; --i) {
			int index = -1;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					index = j;
					break;
				}
			}

			if (a[i] > b[index]) {
				++current;
				used[index] = true;
			} else {
				for (int j = n - 1; j >= 0; --j) {
					if (!used[j] && b[j] > a[i]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		res = max(res, current);
	}

	for (int x = 0; x <= n; ++x) {
		vector < bool > used(n, false);
		int current = 0;
		for (int i = 0; i < x; ++i) {
			bool beaten = false;
			for (int j = n - 1; j >= 0; --j) {
				if (b[j] > a[i] && !used[j]) {
					used[j] = true;
					beaten = true;
					break;
				}
			}
			if (!beaten) {
				++current;
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		for (int i = x; i < n; ++i) {
			int index = -1;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					index = j;
					break;
				}
			}

			if (a[i] > b[index]) {
				++current;
				used[index] = true;
			} else {
				for (int j = n - 1; j >= 0; --j) {
					if (!used[j] && b[j] > a[i]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		res = max(res, current);
	}

	for (int x = 0; x <= n; ++x) {
		vector < bool > used(n, false);
		int current = 0;
		for (int i = x; i < n; ++i) {
			int index = -1;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					index = j;
					break;
				}
			}

			if (a[i] > b[index]) {
				++current;
				used[index] = true;
			} else {
				for (int j = n - 1; j >= 0; --j) {
					if (!used[j] && b[j] > a[i]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < x; ++i) {
			bool beaten = false;
			for (int j = n - 1; j >= 0; --j) {
				if (b[j] > a[i] && !used[j]) {
					used[j] = true;
					beaten = true;
					break;
				}
			}
			if (!beaten) {
				++current;
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		res = max(res, current);
	}

	for (int x = 0; x <= n; ++x) {
		vector < bool > used(n, false);
		int current = 0;
		for (int i = n - 1; i >= x; --i) {
			int index = -1;
			for (int j = 0; j < n; ++j) {
				if (!used[j]) {
					index = j;
					break;
				}
			}

			if (a[i] > b[index]) {
				++current;
				used[index] = true;
			} else {
				for (int j = n - 1; j >= 0; --j) {
					if (!used[j] && b[j] > a[i]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		for (int i = 0; i < x; ++i) {
			bool beaten = false;
			for (int j = n - 1; j >= 0; --j) {
				if (b[j] > a[i] && !used[j]) {
					used[j] = true;
					beaten = true;
					break;
				}
			}
			if (!beaten) {
				++current;
				for (int j = 0; j < n; ++j) {
					if (!used[j]) {
						used[j] = true;
						break;
					}
				}
			}
		}

		res = max(res, current);
	}
	return res;
}

void solve(int test) {
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &a[i]);
	}
	for (int i = 0; i < n; ++i) {
		scanf("%lf", &b[i]);
	}
	sort(a, a + n);
	sort(b, b + n);

	int warGame = calcWarGame();
	int dwarGame = calcDWarGame();

	printf("Case #%d: %d %d\n", test, dwarGame, warGame);
}

int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

	int tests;
	scanf("%d", &tests);
	for (int i = 0; i < tests; ++i) {
		solve(i + 1);
		cerr << (i + 1) << endl;
	}
	cerr << "Time: " << clock() << endl;
	return 0;
}