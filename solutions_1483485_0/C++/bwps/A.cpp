#include <list>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <cfloat>
#include <numeric>

using namespace std;

const int oo = 0x3f3f3f3f;
const double eps = 1e-9;

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

#define sz(c) int((c).size())
#define all(c) (c).begin(), (c).end()
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORD(i,a,b) for (int i = int(b)-1; i >= (a); i--)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)

string sample_in[3]  = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
					    "rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
					    "de kr kd eoya kw aej tysr re ujdr lkgc jv"};
string sample_out[3] = {"our language is impossible to understand",
						"there are twenty six factorial possibilities",
						"so it is okay if you want to just give up"};

int T, perm[26];
string G;

int main() {
	memset(perm, -1, sizeof(perm));
	FOR(i, 0, 3) FOR(j, 0, sz(sample_in[i])) {
		char c1 = sample_in[i][j], c2 = sample_out[i][j];
		if (c1 == ' ') continue;
		perm[c1-'a'] = c2-'a';
	}
	perm['z'-'a'] = 'q'-'a';
	perm['q'-'a'] = 'z'-'a';
	cin >> T;
	getline(cin, G);
	FOR(cs, 1, T+1) {
		getline(cin, G);
		while (G[sz(G)-1] != ' ' && !isalpha(G[sz(G)-1])) G = G.substr(0, sz(G)-1);
		FOR(i, 0, sz(G)) if (G[i] != ' ') G[i] = perm[G[i]-'a'] + 'a';
		cout << "Case #" << cs << ": " << G << endl;
	}
	return 0;
}
