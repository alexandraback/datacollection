#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <string>
#include <vector>
#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
#include <sstream>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
#define SZ(x) (int)(x.size())
#define F0(i,n) for(int i=0;i<n;i++)
#define F1(i,n) for(int i=1;i<=n;i++)
const int MOD = 1000002013;
const double pi = atan(1.0)*4.0;
const double eps = 1e-8;
ll gcd(ll x, ll y) { return y ? gcd(y, x%y) : x; }
int bc(int n) { return n ? bc((n-1)&n)+1 : 0; }

int i, j, k, m, n, l;
char d[256][256];
int sgn[256][256];

int main() {
	//freopen("x.in", "r", stdin);

	//freopen("C-small-attempt1.in", "r", stdin);
	//freopen("C-small-attempt1.out", "w", stdout);

	freopen("C-large.in", "r", stdin);
	freopen("C-large.out", "w", stdout);

	for (char c : {'1', 'i', 'j', 'k'}) {
		d['1'][c] = d[c]['1'] = c;
	}
	for (char c : {'i', 'j', 'k'}) {
		d[c][c] = '1';
		sgn[c][c] = 1;
	}
	d['i']['j'] = d['j']['i'] = 'k';
	d['i']['k'] = d['k']['i'] = 'j';
	d['j']['k'] = d['k']['j'] = 'i';
	sgn['i']['k'] = sgn['j']['i'] = sgn['k']['j'] = 1;

	int tt, tn; cin >> tn;

	F1(tt,tn) {
		cerr << tt << endl;
		string s;
		ll m;
		cin >> n >> m >> s;
		string ans = "NO";

		char c = '1'; int u = 0; int rep = m % 4;
		F0(i, rep*n) {
			char z = s[i%n];
			u ^= sgn[c][z];
			c = d[c][z];
		}
		if (u == 1 && c == '1') {
			int rep = min(4LL, m);
			int n1 = -1, n2 = -1;
			char c = '1'; int u = 0;
			F0(i, rep*n) {
				char z = s[i%n];
				u ^= sgn[c][z];
				c = d[c][z];
				if (u == 0 && c == 'i') {
					n1 = i + 1;
					break;
				}
			}
			if (n1 != -1) {
				char c = '1'; int u = 0;
				F0(i, rep*n) {
					char z = s[n - i%n - 1];
					u ^= sgn[z][c];
					c = d[z][c];
					if (u == 0 && c == 'k') {
						n2 = i + 1;
						break;
					}
				}
				if (n2 != -1) {
					if (n1 + n2 <= n * m) {
						ans = "YES";
					}
				}
			}
		}
		printf("Case #%d: ", tt);
		cout << ans << endl;
	}
	return 0;
}
