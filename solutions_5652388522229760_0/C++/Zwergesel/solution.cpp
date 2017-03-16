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

void get_digits(int c, bool* digits)
{
	while (c) {
		digits[c%10] = true;
		c /= 10;
	}
}

void solve()
{
	int n;
	cin >> n;
	if (n == 0) {
		cout << "INSOMNIA";
		return;
	}
	bool digits[10];
	NUL(digits);
	int c = n;
	bool stop = false;
	do {
		get_digits(c, digits);
		stop = true;
		FOR(i,10) if (!digits[i]) { stop = false; break; }
		c += n;
	} while (!stop);
	c -= n;
	cout << c;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);

	int t;
	cin >> t;
	for (int i=1; i<=t; ++i) {
		cout << "Case #" << i << ": ";
		solve();
		cout << "\n";
	}
	
	return 0;
}
