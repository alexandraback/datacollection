#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <list>
#include <set>
#include <cstdlib>
#include <vector>
#include <cstdio>
#include <string>
#include <cmath>
#include <algorithm>
#include <stack>
#include <ctime>
#include <queue>
#include <map>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef bool bl;
typedef pair<bl, bl> pbl;
typedef pair<ld, ld> pld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define mp make_pair
#define ft first
#define sd second
#define forn(i, y, x) for(int i = y; i < x; i++)
#define ford(i, y, x) for(int i = y; i >= x; i--)
#define sz(x) (int)x.size()
#define all(x) x.begin(), x.end()
#define error exit(1)
#define DEBUG
const int mod = (int)1e9;
const ll inf = (ll)2e18;
const int base = 1000 * 1000 * 1000;
const int maxn = 2005;
const ld pi = acosl(-1.0);
const ld eps = 1e-9;

int predJ = -1, predP = -1, predS = -1;
int J, P, S;
int j, p, s, k, day;
int JP[11][11], PS[11][11], JS[11][11];

bool sol(int h)
{
	if (h == 3) return true;
	if (h == 0){
		forn(i, 0, j) {
			J = i;
			bool ok = sol(h + 1);
			if (ok){
				predJ = J;
				return true;
			}
		}
		return false;
	}
	if (h == 1){
		forn(i, 0, p) if (JP[J][i] < k){
			P = i;
			bool ok = sol(h + 1);
			if (ok){
				predP = P;
				JP[J][P]++;
				return ok;
			}
		}
		return false;
	}
	if (h == 2){
		forn(i, 0, s) if (PS[P][i] < k && JS[J][i] < k && (predJ != J || predP != P || predS != i)){
			S = i;
			bool ok = sol(h + 1);
			if (ok){
				predS = S;
				PS[P][S]++;
				JS[J][S]++;
				return ok;
			}
		}
		return false;
	}
	return false;
}

void solve()
{
	int t;
	scanf("%d", &t);
	forn(tt, 1, t + 1){
		forn(i, 0, 11) forn(l, 0, 11){
			JP[i][l] = PS[i][l] = JS[i][l] = 0;
			predJ = predP = predS = -1;
		}
		scanf("%d %d %d %d", &j, &p, &s, &k);
		day = 0;
		vector<int> jj, pp, ss;
		while (sol(0)){
			day++;
			jj.push_back(J);
			pp.push_back(P);
			ss.push_back(S);
		}
		printf("Case #%d: %d\n", tt, day);
		forn(i, 0, day) printf("%d %d %d\n", jj[i] + 1, pp[i] + 1, ss[i] + 1);
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("C-small-attempt3.in", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	solve();
	return 0;
}