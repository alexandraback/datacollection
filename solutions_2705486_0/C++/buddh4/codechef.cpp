#define _CRT_SECURE_NO_WARNINGS
#include <numeric>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <bitset>
#include <vector>
#include <map>
#include <queue>
#include <deque>
#include <set>
#include <math.h>
#include <assert.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream> 
#include <stack>

#pragma comment(linker, "/STACK:256000000")
using namespace std;
typedef long long ll;
template<typename T> int size(T &a) {return (int)a.size();}
template<typename T> T sqr(T a)  { return a * a; }

#define fi first
#define se second
#define VAR(a,b) __typeof(b) a=(b)
#define FOR(it,c) for(VAR(it,(c).begin());it!=(c).end();++it)
#define REP(i,a,b) for(int i=(a);i<(b); ++i)
#define REPD(i,a,b)for(int i=(b)-1;i>=a;--i)
#define _(a,b) memset((a), (b), sizeof(a))
#define all(a) a.begin(), a.end()
#define mp make_pair
#define pb push_back
#define ve vector

#define ndbg(x) cout << #x << " = " << x << " ";
#define nldbg(x) cout << #x << " = " << x << endl;


const int MAX_STATE = int(1.2e6);
int mv[MAX_STATE][26];
bool final[MAX_STATE];
int lastFreeState = 1;

void addString(string s) {
	int currentState = 0;
	REP(i, 0, size(s)) {
		if(mv[currentState][s[i] - 'a'] == 0) {
			mv[currentState][s[i] - 'a'] = lastFreeState++;
		}
		currentState = mv[currentState][s[i] - 'a'];
	}
	final[currentState] = true;
}

char buffer[1000];

void init() {
	FILE * fdict = fopen("dict.txt", "r");
	
	while(fgets(buffer, 1000, fdict) != NULL) {
		int last = strlen(buffer);
		last--;
		while(buffer[last] == '\n' || buffer[last] == ' ') buffer[last--] = 0;

		string str = string(buffer);
		assert(size(str) >= 1);
		assert(size(str) <= 10);

		REP(i, 0, size(str)) assert( str[i] >= 'a' && str[i] <= 'z' );

		addString(str);
	}

	fclose(fdict);
}

const int MAXN = 4010;

string s;
int dp[MAXN][MAXN];

void update(int & a, int b) {
	if(b == -1) return;
	if(a == -1 || a > b) a = b;
}

void go(int pos, int state, int last, int errors) {
	
	if(final[state]) {
//		cerr << "UPD " << pos << " " << last << endl;
		update(dp[pos][last], errors);
	}

	if(pos == size(s)) return;

	// correct move
	if(mv[state][s[pos] - 'a'] != 0) {
		go(pos + 1, mv[state][s[pos] - 'a'], last, errors);
	}

	// incorrect move
	if(last == 0 || pos + 1 - last >= 5)
	REP(ch, 0, 26) {
		if(s[pos] - 'a' != ch && mv[state][ch] != 0) {
			go(pos + 1, mv[state][ch], pos + 1, errors + 1);
		}
	}
}

int solve() {
	cin >> s;

	_(dp, -1);

	dp[0][0] = 0;

	REP(start, 0, size(s)) {
		REP(last, 0, start + 1) {
			if(dp[start][last] == -1) continue;

			go(start, 0, last, dp[start][last]);
		}
	}

	int ans = -1;
	REP(last, 0, size(s) + 1) {
		update(ans, dp[size(s)][last]);
	}

	return ans;
}

int main() {
#ifdef shindo
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	init();

	int tests;
	cin >> tests;

//	nldbg(tests);

	REP(t, 0, tests) {             
		int ans = solve();
		printf("Case #%d: %d\n", t + 1, ans);
	}
		
#ifdef shindo
//	printf("---------------\n\n%lf\n", clock() * 1e-3);
#endif

	return 0;
}           