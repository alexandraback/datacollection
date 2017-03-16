#include <iostream>
#include <cstdio>
#include <fstream>

#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <set>
#include <map>
#include <utility>
#include <string>
#include <cstring>

#include <algorithm>
#include <cmath>
#include <ctime>
#include <cstdlib>
#include <cassert>
#include <memory.h>
using namespace std;

#define fr(i, n) for (int i = 0; i < (int)(n); i++)
#define fb(i, n) for (int i = n - 1; i >= 0; i--)
#define all(a) (a).begin(), (a).end()
#define _(a, b) memset(a, b, sizeof(a))
#define mp make_pair
#define pb push_back
#define sz(v) ((int)(v).size())

typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int, int> pii;

inline int ni() { int a; scanf("%d", &a); return a; }
inline double nf() { double a; scanf("%lf", &a); return a; }
template <class T> void out(T a, T b) { bool first = true; for (T i = a; i != b; i++) { if (!first) printf(" "); first = false; cout << *i; } puts(""); }
template <class T> void outl(T a, T b) { for (T i = a; i != b; i++) cout << *i << "\n"; } 

const int MAX_DIFF = 6;
const int MAX_LENGTH = 60;
const int INF = 2e9;

ifstream data("garbled_email_dictionary.txt");
ifstream fin("input.txt");

int T;
int d[MAX_LENGTH][MAX_DIFF];
vs v;
string s;
int N, val;
vector<int> f, l, c, ct;

void precalc() {
	v.resize(521196);
	fr(i, 521196)
		data >> v[i];
	f.resize(521196);
	l.resize(521196);
	c.resize(521196);
	ct.resize(521196);
	data.close();
}

int solve() {
	fin >> s;
	fr(i, MAX_LENGTH)
		fr(j, MAX_DIFF)
			d[i][j] = INF;
	d[0][5] = 0;
	N = sz(s);
	fr(i, N) {
		f.assign(521196, -1);
		l.assign(521196, -1);
		ct.assign(521196, 0);
		fr(j, 521196) {
			if (N - i < sz(v[j]))
				c[j] = 0;
			else {
				c[j] = 1;
				fr(k, sz(v[j])) {
					if (v[j][k] == s[i + k])
						continue;
					else {
						if (f[j] == -1) {
							f[j] = l[j] = k;
							ct[j]++;
						} else {
							if (k - l[j] < 5) {
								c[j] = 0;
								continue;
							} else {
								l[j] = k;
								ct[j]++;
							}
						}
					}
				}

			}				
		}

		fr(j, MAX_DIFF) {
			if (d[i][j] == INF)
				continue;
			val = d[i][j];			
			fr(k, 521196) {
				if (c[k] && (f[k] == -1 || f[k] + j >= 5)) {
					if (l[k] == -1) {
						d[i + sz(v[k])][min(j + sz(v[k]), 5)] = min(d[i + sz(v[k])][min(j + sz(v[k]), 5)], val);
					} else {
						d[i + sz(v[k])][min(sz(v[k]) - l[k], 5)] = min(d[i + sz(v[k])][min(sz(v[k]) - l[k], 5)], val + ct[k]);
					}
				}
			}
		}		
	}
	int best = 2e9;
	fr(i, MAX_DIFF)
		best = min(best, d[N][i]);
	return best;
}

int main() {	
	freopen("output.txt", "w", stdout);  	

	precalc();

	fin >> T;
	fr(test, T) {
		printf("Case #%d: %d\n", test + 1, solve());
	}
}
        