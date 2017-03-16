#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <string>
#include <climits>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <ctime>
#include <iostream>
#include <sstream>
#include <cctype>

#define PI 3.14159265358979
#define EPS 1e-9

using namespace std;

#define REP(i, n) for (int i=0; i<n; i++)
#define FOR(i, m, n) for (int i=m; i<=n; i++)
#define ABS(a) (((a)>0)?(a):(-(a)))
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int,int> ii;

ll k, c, s;
ll powerk[111];

void solve() {
	cin >> k >> c >> s;
	if (s*c < k) {
		cout << "IMPOSSIBLE" << endl;
		return ;
	}
	powerk[0] = 1;
	FOR (i, 1, c-1) powerk[i] = k*powerk[i-1];
	int i = 0;
	while (i<k) {
		ll index = 0;
		for (int j=c-1; j>=0 && i<k; j--, i++) index += i * powerk[j];
		cout << (index + 1) << " ";
	}
	cout << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
