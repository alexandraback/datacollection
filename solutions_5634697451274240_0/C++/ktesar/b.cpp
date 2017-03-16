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

void solve() {
	string s;
	cin >> s;
	int res = 0;
	char last = s[0];
	FOR (i, 1, s.size()-1) {
		if (s[i]!=last) res++;
		last = s[i];
	}
	if (last=='-') res++;
	cout << res << endl;
}

int main() {
	int t; scanf("%d", &t);
	REP(i, t) {
		printf("Case #%d: ", i+1);
		solve();
	}
	return 0;
}
