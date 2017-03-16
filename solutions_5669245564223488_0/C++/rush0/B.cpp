#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#define OUT(x) cerr << #x << ": " << (x) << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define SZ(x) ((int)x.size())
using namespace std;
typedef long long LL;

int T, N;
string car[105];
int ord[105];

bool check() {
	int pos[26];
	memset(pos, 0xFF, sizeof(pos));
	int p = 0;
	REP(i, N) {
		REP(j, SZ(car[ord[i]])) {
			int x = car[ord[i]][j] - 'a';
			if (pos[x] != -1 && p != pos[x] + 1) return false;
			pos[x] = p;
			++p;
		}
	}
	return true;
}

int main() {
	cin >> T;
	REP(tid, T) {
		cin >> N;
		REP(i, N) cin >> car[i];
		map<string, int> st;
		REP(i, N) st[car[i]]++;

		REP(i, N) ord[i] = i;
		LL ans = 0;
		do {
			if (check()) ans = (ans + 1) % 1000000007LL;
		} while (next_permutation(ord, ord + N));

		cout << "Case #" << tid + 1 << ": " << ans << endl;
	}
	return 0;
}