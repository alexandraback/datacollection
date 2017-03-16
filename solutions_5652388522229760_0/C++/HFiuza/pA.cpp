#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <functional>
using namespace std;

#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a - b) < 1e-9; }

const int INF = 1 << 29;
typedef long long ll;

inline int two(int n) { return 1 << n; }
inline int test(int n, int b) { return (n >> b) & 1; }
inline void set_bit(int & n, int b) { n |= two(b); }
inline void unset_bit(int & n, int b) { n &= ~two(b); }
inline int last_bit(int n) { return n & (-n); }
inline int ones(int n) { int res = 0; while (n && ++res) n -= n&(-n); return res; }

template<class T> void chmax(T & a, const T & b) { a = max(a, b); }
template<class T> void chmin(T & a, const T & b) { a = min(a, b); }
/////////////////////////////////////////////////////////////////////

//string s = to_string(n);
//int n = stoi(s);

int main()
{
	int T, N;
	int curN;
	string curS;
	bool appeared[12];
	cin >> T;
	for (int ind = 0; ind < T; ind++) {
		cin >> N;
		if (N == 0) {
			cout << "Case #" << ind + 1 << ": INSOMNIA" << endl;
			continue;
		}
		curN = N;
		curS = to_string(N);
		for (int dig = 0; dig < 10; dig++)
			appeared[dig] = false;
		int n_appearances = 0;
		do {
			for (int i = 0; i < curS.length(); i++) {
				if (!appeared[curS[i] - '0']) {
					appeared[curS[i] - '0'] = true;
					n_appearances++;
				}
			}
			if (n_appearances >= 10)
				break;
			curN += N;
			curS = to_string(curN);
		} while (true);
		cout << "Case #" << ind + 1 << ": ";
		cout << curN << endl;
	}
	return 0;
}


