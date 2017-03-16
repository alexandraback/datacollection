#include <algorithm>
#include <cmath>
#include <vector>
#include <set>
#include <string>
#include <iostream>
#include <map>
#include <ctime>
#include <iomanip>

using namespace std;

#define PATH "C:\\Users\\ValenKof\\Desktop\\"

#define forn(i, n) for(int i = 0; i < n; ++i)
#define debug(x) cerr << "DEBUG: " << #x << " = " << x << endl

#define print(x) cout << x; // cerr << x; //cout << x;

#define all(x) begin(x), end(x)


int cnt(vector<int>& a, vector<int>& b) {
	int x = 0;
	for (int z : a) {
		if (z > b[x]) x++;
	}
	return x;
}

int main() {
	freopen(PATH"D-small-attempt0.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int nTests;
	cin >> nTests;
	for (int iTest = 0; iTest < nTests; ++iTest) {
		print("Case #" << iTest + 1 << ": ");
		int n;
		cin >> n;
		vector<int> a(n), b(n);
		double x;
		forn (i, n) { cin >> x; a[i] = x * 100000 + 0.5; }
		forn (i, n) { cin >> x; b[i] = x * 100000 + 0.5; }
		sort(a.begin(), a.end());
		sort(b.begin(), b.end());
		cout << cnt(a, b) << ' ' << n - cnt(b, a) << endl;
	}
	return 0;
}