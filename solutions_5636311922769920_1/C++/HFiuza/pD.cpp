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


int main()
{
	int T;
	long long K, C, S;
	long long cur, pot;
	cin >> T;
	for (int ind = 0; ind < T; ind++) {
		//cout << endl;
		cin >> K >> C >> S;
		cout << "Case #" << ind + 1 << ":";
		//cout <<" (K, C, S) = " <<"("<<K<<", "<<C<<", "<<S<<") ";
		if (S*C < K) {
			cout << " IMPOSSIBLE" << endl;
			continue;
		}
		long long i=0;
		long long KC = 1;
		for (int j = 1; j < C; j++)
			KC *= K;
		//cout << "KC = " << KC << endl;
		while (true) {
			cur = 1;
			pot = KC;
			long long j;
			for (j = 0; j <C && i+j<K; j++) {
				cur += (j+i)*pot;
				pot /= K;
			}
			cout << " " << cur;
			if (i + j >= K)
				break;
			i += C;
		}
		cout << endl;
	}
	return 0;
}


