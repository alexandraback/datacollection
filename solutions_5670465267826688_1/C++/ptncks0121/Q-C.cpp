#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <memory.h> 
#include <math.h> 
#include <assert.h> 
#include <stack> 
#include <queue> 
#include <map> 
#include <set> 
#include <algorithm> 
#include <string> 
#include <functional> 
#include <vector> 
#include <deque> 
#include <utility> 
#include <bitset> 
#include <limits.h>  
#include <unordered_map>

using namespace std;
typedef long long ll;
typedef unsigned long long llu;
typedef double lf;
typedef unsigned int uint;
typedef long double llf;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
#define memset0(x) memset(x, 0, sizeof (x));
int TC, TCC;

unordered_map<int, int> mult[256 * 256];
struct Q {
	int c;
	Q(int c = '1') : c(c) { }
	Q(char c) : c(c) { }
	Q operator* (Q t) { return Q(mult[c][t.c]); }
	Q operator*= (Q t) { c = mult[c][t.c]; return *this; }
	bool operator!= (Q t) { return c != t.c; }
	bool operator== (Q t) { return c == t.c; }
};

void init() {
}

int L; ll X;
char S[10500];


void solve() {
	scanf("%d%I64d%s", &L, &X, S);

	bool ans = true;

	Q v, m;
	for (int i = 0; i < L; i++) m *= S[i];
	for (ll r = 0; r < X % 4; r++) v *= m;
	if (v != '-1') ans = false;

	if(ans) {
		Q pref; ll fastest = L * X + 10;
		for (int i = 0; i < L; i++) {
			pref *= S[i];
			Q t = pref;
			for (int j = 0; j < 8 && j < X; j++) {
				if (t == 'i') fastest = min(fastest, (ll)j * L + i);
				t *= m;
			}
		}

		Q suff; ll latest = -1;
		for (int i = L - 1; i >= 0; i--) {
			suff *= S[i];
			Q t = suff;
			for (int j = 0; j < 8 && j < X; j++) {
				if (t == 'k') latest = max(latest, L * (X - 1) + i - (ll)j * L);
				t *= m;
			}
		}

		ans = (fastest < latest);
	}

	printf("Case #%d: %s\n", TCC, ans ? "YES" : "NO");
}

int main() {
	freopen("C-large.in", "r", stdin);
	freopen("output.txt", "w", stdout);


	mult['1']['1'] = '1';
	mult['1']['i'] = 'i';
	mult['1']['j'] = 'j';
	mult['1']['k'] = 'k';
	mult['1']['-1'] = '-1';
	mult['1']['-i'] = '-i';
	mult['1']['-j'] = '-j';
	mult['1']['-k'] = '-k';
	mult['-1']['1'] = '-1';
	mult['-1']['i'] = '-i';
	mult['-1']['j'] = '-j';
	mult['-1']['k'] = '-k';
	mult['-1']['-1'] = '1';
	mult['-1']['-i'] = 'i';
	mult['-1']['-j'] = 'j';
	mult['-1']['-k'] = 'k';

	mult['i']['1'] = 'i';
	mult['i']['i'] = '-1';
	mult['i']['j'] = 'k';
	mult['i']['k'] = '-j';
	mult['i']['-1'] = '-i';
	mult['i']['-i'] = '1';
	mult['i']['-j'] = '-k';
	mult['i']['-k'] = 'j';
	mult['-i']['1'] = '-i';
	mult['-i']['i'] = '1';
	mult['-i']['j'] = '-k';
	mult['-i']['k'] = 'j';
	mult['-i']['-1'] = 'i';
	mult['-i']['-i'] = '-1';
	mult['-i']['-j'] = 'k';
	mult['-i']['-k'] = '-j';

	mult['j']['1'] = 'j';
	mult['j']['i'] = '-k';
	mult['j']['j'] = '-1';
	mult['j']['k'] = 'i';
	mult['j']['-1'] = '-j';
	mult['j']['-i'] = 'k';
	mult['j']['-j'] = '1';
	mult['j']['-k'] = '-i';
	mult['-j']['1'] = '-j';
	mult['-j']['i'] = 'k';
	mult['-j']['j'] = '1';
	mult['-j']['k'] = '-i';
	mult['-j']['-1'] = 'j';
	mult['-j']['-i'] = '-k';
	mult['-j']['-j'] = '-1';
	mult['-j']['-k'] = 'i';

	mult['k']['1'] = 'k';
	mult['k']['i'] = 'j';
	mult['k']['j'] = '-i';
	mult['k']['k'] = '-1';
	mult['k']['-1'] = '-k';
	mult['k']['-i'] = '-j';
	mult['k']['-j'] = 'i';
	mult['k']['-k'] = '1';
	mult['-k']['1'] = '-k';
	mult['-k']['i'] = '-j';
	mult['-k']['j'] = 'i';
	mult['-k']['k'] = '1';
	mult['-k']['-1'] = 'k';
	mult['-k']['-i'] = 'j';
	mult['-k']['-j'] = '-i';
	mult['-k']['-k'] = '-1';

	scanf("%d", &TC);
	while (++TCC <= TC) {
		init();
		solve();
	}
	return 0;
}