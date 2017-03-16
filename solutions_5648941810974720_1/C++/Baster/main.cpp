#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <ctime>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <bitset>
#include <stack>
#include <algorithm>
#include <iomanip>

using namespace std;

template<typename X> inline X abs(const X& a) { return a < 0 ? -a : a; }
template<typename X> inline X sqr(const X& a) { return a * a; }

typedef long long li;
typedef long double ld;
typedef pair<int, int> pt;

#define forn(i,n) for (int i = 0; i < int(n); i++)
#define ford(i,n) for (int i = int(n) - 1; i >= 0; i--)
#define fore(i,l,r) for (int i = int(l); i <= int(r); i++)
#define all(a) a.begin(), a.end()
#define sz(a) int(a.size())
#define mp make_pair
#define pb push_back
#define ft first
#define sc second
#define x first
#define y second

const ld EPS = 1e-9;
const int INF = int(1e9);
const li INF64 = li(1e18);

string t;
                          
inline bool read() {         
	cin >> t;
	return true;
}         

string s[] = {"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"};
int w[10][26];
int ans[10];

void solve() {
	memset(ans, 0, sizeof ans);
	memset(w, 0, sizeof w);

	forn (i, 10)
		forn (j, sz(s[i]))
			w[i][s[i][j] - 'A']++;                              
	vector<int> cnt(26, 0);
	vector<int> in(26, 0);
	forn (i, sz(t))
		in[t[i] - 'A']++;
	forn (i, 10)
		forn (j, sz(s[i]))
			cnt[s[i][j] - 'A']++;

	int sum = 10;
	vector<bool> used(10, false);
	while(sum) {
		forn (i, 10) {
			forn (j, sz(s[i]))
				if (cnt[s[i][j] - 'A'] == 1 && !used[i]) {
					cerr << i << endl;
					used[i] = true;
					int cur = INF;
					forn (k, 26)
						if (w[i][k] != 0)
							cur = min(cur, in[k] / w[i][k]);
					sum--;
					ans[i] = cur;
					forn (k, 26) {
						cnt[k] -= w[i][k];
						in[k] -= w[i][k] * cur;
					}	

				}
		}
	}	
	forn (i, 10)
		forn (j, ans[i])
			cout << i;
	cout << endl;
}         

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
   	cerr << setprecision(10) << fixed;
	cout << setprecision(15) << fixed;

	srand(time(NULL));
	
	int t;
	cin >> t;

	forn (i, t) {
	    cout << "Case #" << i + 1 << ": ";
		read();
		solve();
	}
	
#ifdef _DEBUG
	cerr << "TIME: " << clock() << endl;
#endif

	return 0;
}