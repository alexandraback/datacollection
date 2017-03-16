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
#define MAX 2600
int napp[MAX];

int main()
{
	int T;
	cin >> T;
	int N;
	int temp;
	for (int ind = 0; ind < T; ind++) {
		cin >> N;
		for (int i = 0; i < 2510; i++)
			napp[i] = 0;
		for (int i = 1; i < 2 * N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> temp;
				napp[temp]++;
			}
		}
		cout << "Case #" << ind + 1 << ":";
		for (int i = 0; i < 2510; i++) {
			if (napp[i] % 2 == 1)
				cout << " " << i;
		}
		cout << endl;
	}
	return 0;
}


