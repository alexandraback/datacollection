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

	ifstream fin("B-small-attempt0 (1).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		string c,j;
		int curc, curj;
		fin >> c >> j;
		curc = 0;
		curj = 0;
		REP(i, c.size()) {
			if ((c[i] != '?') && (j[i] != '?')) {
				curc *= 10;
				curc += (c[i] - '0');

				curj *= 10;
				curj += (j[i] - '0');
				continue;
			}

			if (c[i] == '?') {
				if (j[i] == '?') {
					if (curc == curj) {
						c[i] = '0';
						j[i] = '0';
						curc *= 10;
						curj *= 10;
						continue;
					}
					if (curc > curj) {
						c[i] = '0';
						j[i] = '9';
						curc *= 10;
						curj *= 10;
						curj += 9;
						continue;
					}
					if (curc < curj) {
						c[i] = '9';
						j[i] = '0';
						curc *= 10;
						curj *= 10;
						curc += 9;
						continue;
					}
				}
				else {
					if (curc == curj) {
						c[i] = j[i];
						curc *= 10;
						curc += (c[i] - '0');

						curj *= 10;
						curj += (j[i] - '0');
						continue;
					}
					if (curc > curj) {
						c[i] = '0';
						curc *= 10;
						curc += (c[i] - '0');

						curj *= 10;
						curj += (j[i] - '0');
						continue;
					}
					if (curc < curj) {
						c[i] = '9';
						curc *= 10;
						curc += (c[i] - '0');

						curj *= 10;
						curj += (j[i] - '0');
						continue;
					}
				}
			}

			if (curc == curj) {
				j[i] = c[i];
				curc *= 10;
				curc += (c[i] - '0');

				curj *= 10;
				curj += (j[i] - '0');
				continue;
			}
			if (curc > curj) {
				j[i] = '9';
				curc *= 10;
				curc += (c[i] - '0');

				curj *= 10;
				curj += (j[i] - '0');
				continue;
			}
			if (curc < curj) {
				j[i] = '0';
				curc *= 10;
				curc += (c[i] - '0');

				curj *= 10;
				curj += (j[i] - '0');
				continue;
			}
		}



		fout << "Case #" << t + 1 << ": " << c << " " << j << endl;
	}
	fout.close();
	fin.close();
	return 0;
}