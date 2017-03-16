//Problem C. Recycled Numbers
#include <algorithm>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <cstring>
#include <climits>
using namespace std;
#define PB push_back
#define MP make_pair
#define REP(i,n) for(i=0;i<(n);++i)
#define FOR(i,l,h) for(i=(l);i<=(h);++i)
#define FORD(i,h,l) for(i=(h);i>=(l);--i)
#define foreach(itr, cont) for (typeof(cont.begin()) itr = cont.begin(); itr != cont.end(); itr++)
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<double> VD;
typedef long long LL;
typedef pair<int,int> PII;

int pow10[10];

inline int rotate(int x, int sz) {
	return x / 10 + (x % 10) * pow10[sz-1];
}
inline int n_digits(int x) {
	int res = 0;
	while (x) {
		res ++;
		x /= 10;
	}
	return res;
}

int main() {
	// init
	for (int i = 0, p10 = 1; i < 10; i ++) {
		pow10[i] = p10;
		p10 *= 10;
	}

	int T, A, B;

	ifstream in("C-small-attempt0.in");
	ofstream out("C-small-attempt0.out");

	in >> T;
	for (int cs = 1; cs <= T; cs ++) {
		out << "Case #" << cs << ": ";

		in >> A >> B;
		int cnt = 0;
		int dB = n_digits(B);
		for (int n = A; n <= B; n ++) {
			int dn = n_digits(n);

			for (int sz = dn; sz <= dB; sz ++) {
				int m = rotate(n, sz);
				while (m != n) {
					//if (m <= B && m > n) cout << n << " " << sz << " " << m << endl;
					if (m <= B && m > n) cnt ++;
					m = rotate(m, sz);
				}
			}
		}
		out << cnt << endl;
	}
	return 0;
}
