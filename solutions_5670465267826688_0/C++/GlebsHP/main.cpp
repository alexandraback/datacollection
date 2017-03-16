#pragma comment(linker, "/STACK:1000000000")
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <list>
#include <deque>
#include <queue>
#include <sstream>
#include <iostream>
#include <algorithm>

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second

const double pi = acos(-1.0);

int tc, len;
long long x;

const int mlt[4][4] = {
{0, 1, 2, 3},
{1, 0, 3, 2},
{2, 3, 0, 1},
{3, 2, 1, 0}
};

const int zn[4][4] = {
{1, 1, 1, 1},
{1, -1, 1, -1},
{1, -1, -1, 1},
{1, 1, -1, -1}
};

pair <int, int> mult(const pair <int, int>& a, const pair <int, int>& b) {
	return mp(mlt[a.fs][b.fs], zn[a.fs][b.fs] * a.sc * b.sc);
}

int tonum[256];
string str;

int main() {
	tonum['i'] = 1;
	tonum['j'] = 2;
	tonum['k'] = 3;

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    cin >> tc;
    for (int tnum = 0; tnum < tc; tnum++) {
    	cin >> len >> x;
    	cin >> str;

    	if (x >= 12) {
    		x = (x % 4) + 12;
    	}

    	string res;
    	for (long long i = 0; i < x; i++)
    		res += str;
		
		pair <int, int> cur = mp(0, 1);
		for (int i = 0; i < (int) res.size(); i++)
			cur = mult(cur, mp(tonum[res[i]], 1));

		cout << "Case #" << tnum + 1 << ": ";
		cerr << cur.fs << ' ' << cur.sc << endl;
		if (cur != mp(0, -1)) {
			cout << "NO" << endl;

			continue;
		}

		cur = mp(0, 1);
		int p = 0;
		while (p < (int) res.size() && cur != mp(1, 1)) {
			cur = mult(cur, mp(tonum[res[p]], 1));
			p++;			
		}

		if (p == (int) res.size()) {
			cout << "NO" << endl;

			continue;
		}

		cur = mp(0, 1);
		while (p < (int) res.size() && cur != mp(2, 1)) {
			cur = mult(cur, mp(tonum[res[p]], 1));
			p++;			
		}

		if (p == (int) res.size()) {
			cout << "NO" << endl;

			continue;
		}

		cout << "YES" << endl;
    }

    return 0;
}