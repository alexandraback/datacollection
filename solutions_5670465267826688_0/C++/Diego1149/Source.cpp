#include <algorithm>
#include <bitset>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iomanip>
#include <iostream>
#include <queue>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

#define INF 1000000000
#define FOR(i, a, b) for(int i=int(a); i<int(b); i++)
#define FORC(cont, it) for(typeof((cont).begin()) it = (cont).begin(); it != (cont).end(); it++)
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;

#define maxL 10000

int transitions[4][4] = { {1,2,3,4}, {2,-1,4,-3}, {3,-4,-1,2}, {4,3,-2,-1} }, found[10];

int main() {
	int T, caso=1, v, finV, count;
	ll L, X;
	bool Fi, Fj, Fk;
	string line;
	cin >> T;
	while (T--) {
		cin >> L >> X >> line;
		v = 1;
		count = finV = 0;
		Fi = Fj = Fk = false; 
		memset(found, 0, sizeof(found));
		while (count < X&&!found[v + 4]) {
			found[v + 4] = 1;
			FOR(i, 0, line.length()) {
				int next = 0;
				switch (line[i]) {
				case 'i':
					next = 1;
					break;
				case 'j':
					next = 2;
					break;
				case 'k':
					next = 3;
					break;
				}
				v = (v > 0 ? 1 : -1)*transitions[abs(v) - 1][next];
				if (v == 2) Fi = true;
				if (v == 4 && Fi) Fj = true;
			}
			if (!finV) finV = v;
			count++;
		}
		cout << "Case #" << caso++ << ": ";
		if ((finV == -1 && X & 1LL) || (abs(finV) != 1 && X % 2 == 0 && X % 4)) Fk = true;
		if (Fi&&Fj&&Fk) cout << "YES";
		else cout << "NO";
		cout << endl;
	}
	return 0;
}