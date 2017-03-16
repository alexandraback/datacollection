#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef long long ll;
typedef stringstream ss;

#define sz(v)		((int) v.size())
#define fv(v, i)	for (int i = 0; i < sz(v); ++i)
#define fn(n, i)	for (int i = 0; i < n; ++i)

#define FILENAME	"A-large-0"

int main() {
	ifstream in(FILENAME ".in");
	ofstream out(FILENAME ".out");

	int T;
	in >> T;
	for (int test = 1; test <= T; ++test) {
		int n, s[200], x = 0;
		in >> n;
		fn(n, i) {
			in >> s[i];
			x += s[i];
		};

		double l = 0, r = x + x, v, m;
		while(fabs(r-l) > 1e-6) {
			v = 0;
			m = (r + l) / 2;
			fn(n, i) {
				v += max(m - s[i], 0.0);
			}
			if (v > (double) x)
				r = m;
			else
				l = m;
		}

		out << "Case #" << test << ": ";

		fn(n, i) {
			out.precision(6);
			out.setf(ios::fixed);
			out << ( max(l - s[i], 0.0)*100/x ) << ' ';
		}

		out << endl;
	}

	return 0;
}