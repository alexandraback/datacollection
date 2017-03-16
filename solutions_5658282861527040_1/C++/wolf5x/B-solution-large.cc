#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;

#define PB push_back
#define MP(x,y) make_pair((x),(y))
#define FI(x) ((x).first)
#define SE(x) ((x).second)
#define SZ(x) ((x).size())
#define LEN(x) ((x).length())

#define REP(i,n) for(long long i=0;i<(n);++i)
#define FOR(i,l,h) for(long long i=(l);i<(h);++i)
#define FORD(i,h,l) for(long long i=(h)-1;i>=(l);--i)
#define FORIT(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define FORRIT(i,c) for(typeof((c).rbegin()) i=(c).rbegin(); i!=(c).rend(); ++i)

#define CLR(x) memset((x),0,sizeof(x))
#define SET(x,y) memset((x),(y),sizeof(x))

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

const int L = 60;
long long msk[L];
int T, A, B, K;
long long dp[L][2][2][2]; 

void init() {
	msk[0] = -1LL;
	FOR(i, 1, L)
		msk[i] = msk[i-1] << 1;
}

int btest(long long x, int b) {
	if (b<0) return 0;
	return ((1LL<<b)&x) != 0 ? 1 : 0;
}

long long getdp(int b, int x, int y, int z) {
	if (b < 0) return 1;
	long long &r = dp[b][x][y][z];
	if (r >= 0) return r;
	r = 0;
	int ux = x ? btest(A, b) : 1;
	int uy = y ? btest(B, b) : 1;
	int uz = z ? btest(K, b) : 1;
	REP(i, ux+1) REP(j, uy+1) REP(k, uz+1) {
		if ((i&j) != k) continue;
		int ex = (x && i==ux), ey = (y && j==uy), ez = (z && k==uz);
		r += getdp(b-1, ex, ey, ez);
	}
	return r;
}

int main() {
	init();
	cin >> T;
	FOR(_, 1, T+1) {
		cin >> A >> B >> K;
		A--, B--, K--;
		SET(dp, -1);
		cout << "Case #" << _ << ": " << getdp(L-1, 1, 1, 1) << endl;
	}
	return 0;
}

