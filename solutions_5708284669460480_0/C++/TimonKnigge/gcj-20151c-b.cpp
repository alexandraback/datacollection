#include <iostream>
#include <iomanip>
#include <vector>           
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <bitset>
#include <algorithm>
#include <functional>
#include <string>
#include <string.h>  // Include for memset!
#include <complex>
#include <random>
#define _USE_MATH_DEFINES
#include <math.h>

#define INF 2000000000              // 9
#define LLINF 9000000000000000000LL // 18
#define LDINF 1e200

using namespace std;

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<bool> vb;
typedef long long ll;
typedef long double ld;

void output(int t, ld ans) {
	cout << "Case #" << t << ": ";
	printf("%lf", (double)ans);
	cout << endl;		
}

ld attempt(string& K, string& L, string m, int d) {
	if (d == 0) {
		bool ma = true;
		for (int i = 0; i < L.length(); ++i) {
			if (L[i] != m[i + m.length() - L.length()])
				ma = false;
		}
		return (ma ? 1.0 : 0.0);
	}
	else {
		bool ma = true;
		if (m.length() >= L.length()) {
			for (int i = 0; i < L.length(); ++i) {
				if (L[i] != m[i + m.length() - L.length()])
					ma = false;
			}
		}
		else ma = false;

		ld sum = (ma ? 1.0 : 0.0);
		for (int i = 0; i < K.size(); ++i) {
			sum += attempt(K, L, m + K[i], d - 1) / K.size();
		}
		return sum;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int T;
	cin >> T;
	for (int t = 1; t <= T; ++t) {
		int k, l, s;
		cin >> k >> l >> s;
		string K, L;
		cin >> K >> L;

		/*
				K : KEYBOARD
				L : TO-MATCH
				S : MONKEY-STRING
				k l s
				K
				L
		*/

		// max bananas: shortest match
		int m;
		for (m = 1; m < L.size(); ++m) {
			bool match = true;
			for (int i = 0; m + i < L.size(); ++i) {
				if (L[i] != L[m + i]) {
					match = false;
					break;
				}
			}
			if (match) break;
		}
		ld matches = 1 + (s - l) / m;
		ld ans;

		bool MATCH_POS = true;
		for (char c : L) {
			bool THIS_MATCH_POS = false;
			for (char cc : K) {
				if (c == cc) THIS_MATCH_POS = true;
			}
			MATCH_POS = MATCH_POS && THIS_MATCH_POS;
		}
		if (!MATCH_POS) ans = 0.0;
		else ans = matches - attempt(K, L, "", s);

		output(t, ans);
	}

	return 0;
}