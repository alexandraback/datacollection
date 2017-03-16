#define DEBUG 0

#include <algorithm>
#include <bitset>
#include <climits>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;

typedef unsigned long long int uLint;
typedef long long int Lint;
typedef short int sint;
typedef long double ld;
typedef pair<int,int> PII;
typedef pair<PII,int> PPI;
typedef vector<int> VI;
typedef vector<ld> VD;
typedef vector<string> VS;
typedef vector<PII> VPII;
typedef vector<VI> VVI;
typedef queue<int> QI;
typedef queue<PII> QPII;

const int PRIME = 1000 * 1000 * 1000 + 7;
const int MULTIPLIER = 523;
const int INFI = (1 << 30) - 1;
const ld INF = 2 * 1e9 + 1;
const ld EPS = 1e-9;
const ld PI = M_PI;
const int DIM = 2;

#define X coord[0]
#define Y coord[1]

#define VAR(v, n) __typeof(n) v = (n)
#define REP(a, b) for(int a = 0;a < (b);++a)
#define FOR(a, b, c) for(int a = (b);a <= (c);++a)
#define FORD(a, b, c) for(int a = (b);a >= (c);--a)
#define FOREACH(it, s) for(VAR(it, (s).begin());it != (s).end();++it)
#define SIZE(x) (int)(x).size()
#define PB push_back
#define PF push_front
#define MP make_pair
#define NEWLINE cout << "\n";

int tab[][5] = {{0, 0, 0, 0, 0}, {0, 1, 2, 3, 4}, {0, 2, -1, 4, -3}, {0, 3, -4, -1, 2}, {0, 4, 3, -2, -1}};

int multiply(int left, int right) {
	int sign = (left * right < 0 ? -1 : 1);
	return sign * tab[abs(left)][abs(right)];
}

int findRightFactor(int left, int result) {
	FOR(i, 1, 4) {
		int product = multiply(left, i);
		if (product == result) {
			return i;
		} else if (product == -result) {
			return -i;
		}
	}

	throw 0;
}

int findLeftFactor(int right, int result) {
	FOR(i, 1, 4) {
		int product = multiply(i, right);
		if (product == result) {
			return i;
		} else if (product == -result) {
			return -i;
		}
	}

	throw 0;
}

int convert(char x) {
	return x - 'g';
}

void solve() {
	int len;
	Lint x;
	cin >> len >> x;

	string input;
	cin >> input;

	int *text = new int[len];
	REP(i, len) {
		text[i] = convert(input[i]);
	}

	int *forward = new int[len + 1];
	int *backward = new int[len + 1];

	forward[0] = backward[0] = 1;

	REP(i, len) {
		forward[i + 1] = multiply(forward[i], text[i]);
		backward[i + 1] = multiply(text[len - i - 1], backward[i]);
	}

	int block = forward[len];

	int blocksFactor[4];
	blocksFactor[0] = 1;
	FOR(i, 1, 3) {
		blocksFactor[i] = multiply(blocksFactor[i - 1], block);
	}

	int forwardPart[4];
	int backwardPart[4];

	REP(i, 4) {
		forwardPart[i] = findRightFactor(blocksFactor[i], convert('i'));
		backwardPart[i] = findLeftFactor(blocksFactor[i], convert('k'));
	}

	int firstPos[4];
	int lastPos[4];

	REP(i, 4) {
		firstPos[i] = lastPos[i] = -1;

		int pos = 0;
		while (firstPos[i] == -1 && pos < len) {
			if (forwardPart[i] == forward[pos + 1]) {
				firstPos[i] = pos;
			}
			++pos;
		}

		pos = len - 1;
		while (lastPos[i] == -1 && pos >= 0) {
			if (backwardPart[i] == backward[len - pos]) {
				lastPos[i] = pos;
			}
			--pos;
		}
	}

	REP(i, 4) REP(j, 4) {
		if (i + j < x) {
			int middle = 1;

			Lint b = x - i - j - 2;
			if (b > 0) {
				middle = blocksFactor[b % 4];
			}

			if (forwardPart[i] != 1 && firstPos[i] == -1) {
				continue;
			}
			if (backwardPart[j] != 1 && lastPos[j] == -1) {
				continue;
			}

			int left = block;
			int right = block;

			if (forwardPart[i] != 1) {
				left = backward[len - firstPos[i] - 1];
			}
			if (backwardPart[j] != 1) {
				right = forward[lastPos[j]];
			}

			if (b == -1) {
				if (firstPos[i] >= lastPos[j]) {
					continue;
				}

				FOR(k, firstPos[i] + 1, lastPos[j] - 1) {
					middle = multiply(middle, text[k]);
				}

				if (middle == 3) {
					cout << "YES";
					return;
				} else {
					continue;
				}
			}

			int jPart = multiply(multiply(left, middle), right);
			if (jPart == 3) {
				cout << "YES";
				return;
			}
		}
	}

	cout << "NO";
	return;
}

int main() {
	ios_base::sync_with_stdio(0);

	int numberOfTests;
	cin >> numberOfTests;

	for (int test = 1; test <= numberOfTests; ++test) {
		cout << "Case #" << test << ": ";
		solve();
		cout << "\n";
	}

	return 0;
}
