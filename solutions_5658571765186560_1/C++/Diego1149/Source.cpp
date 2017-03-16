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

int main() {
	int T, caso=1, X, R, C;
	bool possible;
	cin >> T;
	while (T--) {
		cin >> X >> R >> C;
		if (R > C) swap(R, C);
		possible = true;
		if (R*C%X || X >= 7 || X > C) possible = false;
		if (X <= 4 && X >= R + 2) possible = false;
		if (X == 5) {
			if (R <= 2) possible = false;
			if (R == 3 && C < 10) possible = false;
		}
		if (X == 6) {
			if (R <= 3) possible = false;
		}
		cout << "Case #" << caso++ << ": ";
		if (possible) cout << "GABRIEL";
		else cout << "RICHARD";
		cout << endl;
	}
	return 0;
}
