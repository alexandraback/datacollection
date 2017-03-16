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

int main() {
	freopen(PATH"B-small-attempt0.in", "r", stdin);
	freopen(PATH"out.txt", "w", stdout);
	int nTests;
	cin >> nTests;
	for (int iTest = 0; iTest < nTests; ++iTest) {
		print("Case #" << iTest + 1 << ": ");

		long double C, F, X;
		cin >> C >> F >> X;
		long double CPS = 2;
		
		long double ANS = X / CPS;
		long double T = 0.0;
		for (int i = 0; ; ++i) {
			ANS = min(ANS, T + X / CPS);
			T += C / CPS;
			CPS += F;
			if (T > ANS) break;
		}
		cout << fixed << setprecision(9) << (double) ANS << endl;
	}
	return 0;
}