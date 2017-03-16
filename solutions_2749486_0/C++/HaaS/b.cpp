#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <vector>
#include <cmath>
#include <set>
#include <map>

using namespace std;

#define int long long
#define double long double

#define ff first
#define ss second
#define mp make_pair
#define sqr(x) ((x)*(x))

typedef long long ll;
typedef pair <int, int> pie;

const int maxN = 8000 * 1000 + 10;

int d[maxN];

/*void precalc() {
	memset (d, -1, sizeof d);
	for 
}*/

string solve() {
	int x, y; cin >> x >> y;
	string res = "";
	for (int i = 0; i < abs (x); i++)
		res += (x < 0 ? "EW" : "WE");
	for (int j = 0; j < abs (y); j++)
		res += (y < 0 ? "NS" : "SN");
	return res;	
}

main() {
	ios::sync_with_stdio (false);
	
	//precalc();

	int tests; cin >> tests;
	for (int o = 1; o <= tests; o++) {
		string ans = solve();
		cout << "Case #" << o << ": " << ans << endl;
	}

	return 0;
}
