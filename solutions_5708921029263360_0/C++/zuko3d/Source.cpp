#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cctype>
#include <string>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i, a, b) for (int i(a), _b(b); i <= _b; ++i)
#define REP(i, n) for (int i(0), _n(n); i < _n; ++i)

int main(void) {
	int T;

	ifstream fin("B-large (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		long long b, m;
		fin >> b >> m;

		if ((double)m > pow(2.0, (double)b - 2)) {
			fout << "Case #" << t + 1 << ": IMPOSSIBLE\n";
		}
		else {
			fout << "Case #" << t + 1 << ": POSSIBLE\n";
			
			fout << 0;
			REP(i, b - 1) fout << 1;
			fout << endl;
			m--;

			FOR(i, 1, b - 1) {
				REP(q, i + 1) {
					fout << 0;
				}
				REP(q, b - i - 2) {
					fout << 1;
				}
				if(i < b - 1) fout << m % 2;
				m /= 2;
				fout << endl;
			}
		}
	}
	fout.close();
	fin.close();
	return 0;
}