#include <algorithm>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <sstream>
#include <vector>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORVEC(it,v) for (auto it=(v).begin(); it != (v).end(); ++it)
#define NUL(arr) memset(arr, 0, sizeof(arr));
#define SORT(x) sort((x).begin(), (x).end());

int solve()
{
	string pan;
	cin >> pan;
	int bad(0), good(0);
	for (size_t i=0; i<pan.size(); ++i) {
		if (pan[i] == '+') {
			bad = good + 1;
		} else {
			good = bad + 1;
		}
	}
	return good;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		cout << solve();
		cout << "\n";
	}
	
	return 0;
}
