#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <string>
#include <cstring>
#include <ctime>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
static const double PI2 = 8.0 * atan(1.0);

#define REP(i,n)	for(int i=0;i<(int)n;++i)
#define ALL(c)		(c).begin(),(c).end()
#define CLEAR(v)	memset(v,0,sizeof(v))
#define MP(a,b)		make_pair((a),(b))
#define ABS(a)		((a)>0?(a):-(a))
#define FOR(i,s,n)	for(int i=s;i<(int)n;++i)

int cnt[256];

int count(char c, const string &str) {
	int res = 0;
	while (cnt[c] > 0) {
		++res;
		REP(i, str.length()) --cnt[str[i]];
	}
	return res;
}

void solve() {
	CLEAR(cnt);
	string S;
	cin >> S;
	REP(i, S.length()) ++cnt[S[i]];
	int res[10]; CLEAR(res);
	res[0] = count('Z', "ZERO");
	res[2] = count('W', "TWO");
	res[6] = count('X', "SIX");
	res[7] = count('S', "SEVEN");
	res[8] = count('G', "EIGHT");
	res[3] = count('T', "THREE");
	res[4] = count('R', "FOUR");
	res[5] = count('F', "FIVE");
	res[1] = count('O', "ONE");
	res[9] = count('I', "NINE");
	REP(i, 10) REP(j, res[i]) cout << i;
	cout << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	REP(i, T) {
		cout << "Case #" << (i + 1) << ": ";
		solve();
	}
	return 0;
}
