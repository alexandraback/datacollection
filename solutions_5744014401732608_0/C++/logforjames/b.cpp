#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <iostream>
#include <cstdio>

using namespace std;

#define forsn(i,s,n) for (int i = (s);i < (int)(n);i++)
#define forn(i,n) forsn(i,0,n)
#define dforsn(i,s,n) for (int i = (n - 1);i >= (int)(s);i--)
#define dforn(i,n) dforsn(i,0,n)
#define all(v) (v).begin(), (v).end()

typedef long long int tint;
typedef vector<int> vi;
typedef vector<vi> mat;

int main() {
	int T; cin >> T;
	forn(caso, T) {
		tint b, m; cin >> b >> m; m--;
		
		mat res = mat(b, vi(b, 0));
		res[0] = vi(b, 1); res[0][0] = 0;
		
		int current = b - 2;
		tint weight = 1;
		while (m && current > 0) {
			if (weight >= m) {
				res[current][b - 1] = 1;
				m--;
				int cur = b - 2;
				while (m) {
					if (m % 2) {
						res[current][cur] = 1;
					}
					m /= 2;
					cur--;
				}
			} else {
				forsn(j, current + 1, b) res[current][j] = 1;
				
				m -= weight;
				current--;
				weight *= 2;
			}
		}
		cout << "Case #" << caso + 1 << ": ";
		if (m) {
			cout << "IMPOSSIBLE\n";
		} else {
			cout << "POSSIBLE\n";
			forn(i,b) forn(j,b) {
				cout << res[i][j]; 
				if (j == b - 1) cout << '\n';
			}
		}
	}
}
