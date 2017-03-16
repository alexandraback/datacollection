#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for(__typeof__((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define mp make_pair
#define pb push_back
#define has(c,i) ((c).find(i) != (c).end())
#define DBG(...) ({ if(1) fprintf(stderr, __VA_ARGS__); })
#define DBGDO(X) ({ if(1) cerr << "DBGDO: " << (#X) << " = " << (X) << endl; })

#define _1 0
#define _i 1
#define _j 2
#define _k 3
#define __ 4 // -1
#define _I 5 // -i
#define _J 6 // -j
#define _K 7 // -k

//                                   01234567
static const string internal2orig = "1ijk_IJK";
static char LUT_orig2internal[256] = {0};

static char LUT_calc[8][8] = {
//         1,  i,  j,  k,   _,  I,  J,  K
/* 1 */	{ _1, _i, _j, _k,  __, _I, _J, _K },
/* i */	{ _i, __, _k, _J,  _I, _1, _K, _j },
/* j */	{ _j, _K, __, _i,  _J, _k, _1, _I },
/* k */	{ _k, _j, _I, __,  _K, _J, _i, _1 },

/* _ */	{ __, _I, _J, _K,  _1, _i, _j, _k },
/* I */	{ _I, _1, _K, _j,  _i, __, _k, _J },
/* J */	{ _J, _k, _1, _I,  _j, _K, __, _i },
/* K */	{ _K, _J, _i, _1,  _k, _j, _I, __ },
};

static bool testcase() {
	int L;
	ll X;
	string S, str;
	cin >> L >> X;
	cin >> S;

	for (char &c : S)
		c = LUT_orig2internal[(int)c];

	X = min(X, 32 + X % 32);
	str.reserve(sz(S) * X);
	FOR(i,0,X) str += S;

	int end = sz(str);
	int p = 0;

	int state;

	for (state = _1; p < end && state != _i; ) {
		int nxt = str[p++];
		state = LUT_calc[state][nxt];
	}
	if (p >= end || state != _i) return false;

	for (state = _1; p < end && state != _j; ) {
		int nxt = str[p++];
		state = LUT_calc[state][nxt];
	}
	if (p >= end || state != _j) return false;

	for (state = _1; p < end; ) {
		int nxt = str[p++];
		state = LUT_calc[state][nxt];
	}

	return state == _k;
};

int main() {
	ios::sync_with_stdio(false);

	FOR(p,0,sz(internal2orig)) {
		LUT_orig2internal[ (int)internal2orig[p] ] = char(p);
	}

	int TC;
	cin >> TC;
	FOR(tc, 1, TC+1) {
		printf("Case #%d: %s\n", tc, testcase() ? "YES" : "NO");
	}
}
