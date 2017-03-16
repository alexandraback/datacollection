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

int *fpref(const string &s)
{
	int n = s.size();
	int *p = new int[n];
	p[0] = 0;
	FOR(i, 1, n - 1)
	{
		p[i] = p[i - 1];
		while(p[i] && s[p[i]] != s[i]) p[i] = p[p[i] - 1];
		if(s[p[i]] == s[i]) ++p[i];
	}
	return p;
}

long double threshold = 1e-9;

int k, len, s;
string keyboard;
string target;

int prefix;
int *pref;

char letters[26];

ld expected;

ld *transfer;

void compute(ld prob, int result, int chars, int pr) {
	// if (target == "B") {
	// 	cerr << "compute " << target[pr] << " " << (double) prob << " " << result << " " << chars << " " << pr << endl;
	// }

	if (pr == len) {
		++result;
		pr = prefix;
	}

	if ((chars == s) || (prob < threshold)) {
		expected += result * prob;
		return;
	}

	bool used[26];
	for (int i = 0; i < 26; ++i) {
		used[i] = false;
	}

	ld probNothing = transfer[pr];

	compute(prob * transfer[pr], result, chars + 1, pr + 1);
	used[target[pr] - 'A'] = true;

	if (pr > 0) {
		while (pref[pr - 1]) {
			pr = pref[pr - 1];
			if (!used[target[pr] - 'A']) {
				used[target[pr] - 'A'] = true;
				probNothing += transfer[pr];
				compute(prob * transfer[pr], result, chars + 1, pr + 1);
			}
		}
	}

	// if (!used[target[0] - 'A']) {
		compute(prob * (1 - probNothing), result, chars + 1, 0);
	// }
}

void solve() {
	expected = 0;

	cin >> k >> len >> s;
	cin >> keyboard;
	cin >> target;

	pref = fpref(target);
	prefix = pref[len - 1];

	int count = s / len;
	if (prefix != 0) {
		if (s >= len) {
			count = 1 + (s - len) / (len - prefix);
		} else {
			count = 0;
		}
	}

	for (int i = 0; i < 26; ++i) {
		letters[i] = 0;
	}

	for (int i = 0; i < (int) keyboard.length(); ++i) {
		++letters[keyboard[i] - 'A'];
	}

	for (int i = 0; i < (int) len; ++i) {
		if (letters[target[i] - 'A'] == 0) {
			cout << 0 << "\n";
			return;
		}
	}

	if (len > s) {
		cout << 0 << "\n";
		return;
	}

	transfer = new ld[len];
	for (int i = 0; i < len; ++i) {
		transfer[i] = letters[target[i] - 'A'];
		transfer[i] /= k;
	}

	compute(1, 0, 0, 0);

	cout << fixed << setprecision(7) << (double) (count - expected) << "\n";
}

int main() {
	ios_base::sync_with_stdio(0);

	int numberOfTests;
	cin >> numberOfTests;

	for (int test = 1; test <= numberOfTests; ++test) {
		cout << "Case #" << test << ": ";
		solve();
	}

	return 0;
}
