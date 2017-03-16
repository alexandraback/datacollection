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

int n, J;
int ones[2];

int main() {
	int t; cin >> t;
	cin >> n >> J;
	ll b = (1<<(n-1)) + 1;
	cout << "Case #1:" << endl;
	while (J>0) {
		ones[0] = ones[1] = 0;
		for (int i=0; i<n; i++) {
			ones[i%2] += ((b & (1<<i)) != 0);
		}
		if (ones[0]==ones[1]) {
			for (int i=n-1; i>=0; i--) cout << ((b & (1<<i)) != 0) ? 1 : 0;
			FOR (i, 2, 10) cout << " " << (i+1);
			cout << endl;
			J--;
		}
		b += 2;
	}

	return 0;
}
