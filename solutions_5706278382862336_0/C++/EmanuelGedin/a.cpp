#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long LL;
typedef long double LD;
typedef vector<int> VI;
typedef vector<vector<int> > VII;
#define rep(i, a) for(int i = 0; i < (a); i++)
#define foru(i, s, e) for(int i = (s); i < (e); i++)
#define ford(i, s, e) for(int i = (s); i >= (e); i--)
#define cinNewLine cin.ignore(numeric_limits<streamsize>::max(), '\n');
const double EPS = 1e-9;
const int INF = 2147483647;
const LL LLINF = 9223372036854775807LL;
template <class T> T gcd(T a, T b) { if(a < b) swap(a, b); if(b == 0) return a; return gcd(b, a%b); }
template <class T> T lcm(T a, T b) { return (a*b)/gcd(a, b); }

int main() {
	int T;
	cin >> T;
	foru(t, 1, T+1) {
		LL a, b;
		char tmp;
		cin >> a >> tmp >> b;
		cout << "Case #" << t << ": ";
		LL g = gcd(a, b);
		a /= g;
		b /= g;
		LL div = 2;
		bool done = false;
		foru(i, 1, 41) {
			if(b%div == 0) {
				LL k = b/div;
				if(a%k == 0) {
					a /= k;
					int ans = i+1;
					while(a) {
						a = a >> 1;
						ans--;
					}
					cout << ans << endl;
					done = true;
					break;
				}
			}
			div = div << 1;
		}
		if(!done) cout << "impossible" << endl;
	}
	return 0;
}

