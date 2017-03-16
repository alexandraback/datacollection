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

void solve() {
	int d;
	cin >> d;

	int *tab = new int[1001];
	REP(i, 1001) {
		tab[i] = 0;
	}

	REP(i, d) {
		int p;
		cin >> p;
		++tab[p];
	}

	int best = 1000;

	FOR(target, 1, 1000) {
		int result = target;

		FOR(i, target + 1, 1000) {
			result += tab[i] * ((i - 1) / target);
		}

		best = min(best, result);
	}

	cout << best;
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
