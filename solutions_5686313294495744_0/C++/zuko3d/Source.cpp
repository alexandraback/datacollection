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

	ifstream fin("C-small-attempt0 (2).in");
	ofstream fout("out.txt");
	fin >> T;
	REP(t, T) {
		int n;
		int ret;
		ret = 0;
		fin >> n;

		map<string, int> frst, scnd;
		map<string, list<string>> neibf, neibs;
		string f, s;

		REP(i, n) {
			fin >> f >> s;
			if (frst.find(f) == frst.end()) {
				frst[f] = 1;
			}
			else {
				frst[f]++;
			}

			if (scnd.find(s) == scnd.end()) {
				scnd[s] = 1;
			}
			else {
				scnd[s]++;
			}

			if (neibf.find(f) == neibf.end()) {
				neibf[f] = list<string>();
			}
			neibf[f].push_back(s);

			if (neibs.find(s) == neibs.end()) {
				neibs[s] = list<string>();
			}
			neibs[s].push_back(f);
		}

		map<string, int>::iterator it;
		list<string>::iterator itn;
		it = frst.begin();
		while (it != frst.end()) {
			if (it->second == 1) {
				it++;
				continue;
			}

			unsigned int killable = 0;
			itn = neibf[it->first].begin();
			while (itn != neibf[it->first].end()) {
				if (scnd[*itn] > 1) killable++;
				itn++;
			}
			ret += min(killable, neibf[it->first].size() - 1);

			it++;
		}

		it = scnd.begin();
		while (it != scnd.end()) {
			if (it->second == 1) {
				it++;
				continue;
			}

			unsigned int killable = 0;
			itn = neibs[it->first].begin();
			while (itn != neibs[it->first].end()) {
				if (frst[*itn] > 1) killable++;
				itn++;
			}
			ret += min(killable, neibs[it->first].size() - 1);

			it++;
		}

		fout << "Case #" << t + 1 << ": " << ret/2 << endl;
	}
	fout.close();
	fin.close();
	return 0;
}