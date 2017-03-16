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

const string GAB = "GABRIEL";
const string RICH = "RICHARD";

void solve() {
	int x, r, c;
	cin >> x >> r >> c;

	if ((r * c) % x) {
		cout << RICH;
		return;
	}

	switch(x) {
		case 1:
			cout << GAB;
			return;
		case 2:
			cout << GAB;
			return;
		case 3:
			if (min(r, c) == 1) {
				cout << RICH;
			} else {
				cout << GAB;
			}
			return;
		case 4:
			if (min(r, c) >= 3 && (r == 4 || c == 4)) {
				cout << GAB;
			} else {
				cout << RICH;
			}
			return;
	}
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
