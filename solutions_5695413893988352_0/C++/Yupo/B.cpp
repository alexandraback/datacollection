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

#define INF (100000000)

ll assign(const string &str, ll digits) {
	ll res = 0;
	stack<int> d;
	REP(i, str.length()) {
		res *= 10;
		if (str[i] == '?') {
			d.push(str.length() - 1 - i);
		}
		else {
			res += str[i] - '0';
		}
	}
	ll v = 1;
	int i = 0;
	while (!d.empty()) {
		while (i < d.top()) {
			v *= 10;
			++i;
		}
		d.pop();
		res += v * (digits % 10);
		digits /= 10;
	}
	return res;
}

void solve_s() {
	string C, J;
	cin >> C >> J;
	ll cq = 1, jq = 1;
	REP(i, C.length()) if (C[i] == '?') cq *= 10;
	REP(i, J.length()) if (J[i] == '?') jq *= 10;
	int resc = -INF, resj = INF;
	REP(c, cq) REP(j, jq) {
		ll cv = assign(C, c);
		ll jv = assign(J, j);
		if (abs(cv - jv) < abs(resc - resj)
			|| (abs(cv - jv) == abs(resc - resj) && (cv < resc
			|| (cv == resc && jv < resj))))
		{
			resc = cv; resj = jv;
		}
	}
	cout << setw(C.length()) << setfill('0') << resc;
	cout << " ";
	cout << setw(J.length()) << setfill('0') << resj;
	cout << endl;
}

int main(int argc, char **argv) {
	int T;
	cin >> T;
	REP(i, T) {
		cout << "Case #" << (i + 1) << ": ";
		solve_s();
	}
	return 0;
}
