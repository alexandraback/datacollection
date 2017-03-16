#include <algorithm>
#include <bitset>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cstdio>
#include <cstdlib>
#include <cctype>
#include <cmath>
#include <ctime>

using namespace std;

#define rep(a, b, e) for(int a = (int) b; a < (int) e; ++a)
#define clr(a, val) memset(a, val, sizeof(a))
#define debug(a) cerr << #a << ": " << a << endl;
#define debugv(b, t) cerr << #b << ":\n"; rep(countvec, 0, t) { cerr << b[countvec] << '\t'; } cerr << endl;
#define debugm(c, t, u) cerr << #c << ":\n"; rep(countmat, 0, t) { rep(countbb, 0, u) { cerr << c[countmat][countbb] << '\t'; } cerr << endl; }
string tos(int a) { ostringstream os(""); os << a; return os.str(); }

int t, a, b, k;

void solve(int tc) {
	cin >> a >> b >> k;
	int cnt = 0;
	rep(i, 0, a) rep(j, 0, b) if((i & j) < k) ++cnt;
	cout << "Case #" << tc << ": " << cnt << endl;
}

int main() {
	#ifndef ONLINE_JUDGE 
		freopen("D:/in.txt","r",stdin); 
		freopen("D:/out.txt","w",stdout); 
		clock_t start = clock(); 
	#endif
	
	cin >> t;
	rep(tc, 1, t + 1)
		solve(tc);
	
	#ifndef ONLINE_JUDGE 
		fprintf(stderr, "\ntime=%.3lfsec\n", 0.001 * (clock() - start)); 
	#endif 
	return 0;
}
