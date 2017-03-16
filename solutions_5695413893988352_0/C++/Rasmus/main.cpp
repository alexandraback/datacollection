#include <algorithm>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <iostream>
#include <fstream>
#include <cmath>
#include <math.h>
#include <iomanip>
#include <stdlib.h>
#include <stdio.h>
#include <bitset>
#include <iterator>

using namespace std;

#define FOR(i,n) for (int i=0; i<n; ++i)
#define FORE(i,n) for (int i=0; i<=n; ++i)
#define REP(i,a,b) for (int i=a; i<b; ++i)
#define REPE(i,a,b) for (int i=a; i<=b; ++i)
#define mp make_pair
#define pb push_back

typedef long double dbl;
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef long long int LL;
typedef vector<int> VI;
typedef vector<bool> VB;
typedef vector<VI> VVI;
const dbl pi = 3.14159265358979323846;
const int inf = (int) 1e9;
const dbl eps = 1e-9;

string go(int v, int n) {
	string res = "";
	while(v) {
		res = (char)(v % 10 + '0') + res;
		v /= 10;
	}
	while(res.size() < n) {
		res = "0" + res;
	}
	return res;
}

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	REPE(TT,1,T) {
		if (TT > 1) {
			cout << "\n";
		}
		cout << "Case #" << TT << ": ";
		cerr << TT << "\n";
		string x,y;
		cin >> x >> y;
		int n = x.size();
		int to = 1;
		FOR(i,n) {
			to *= 10;
		}
		int res = inf;
		int l = 0;
		int r = 0;

		FOR(i,to) {
			string a = go(i,n);
			FOR(j,to) {
				string b = go(j,n);
				bool ok = true;
				FOR(k,n) {
					if (x[k] != '?' && x[k] != a[k]) {
						ok = false;
						break;
					}
					if (y[k] != '?' && y[k] != b[k]) {
						ok = false;
						break;
					}
				}
				if (!ok) {
					continue;
				}
				int now = abs(i - j);
				if (res > now) {
					res = now;
					l = i;
					r = j;
				}
				if (res == now) {
					if (i < l) {
						l = i;
						r = j;
					}
					if (i == l && j < r) {
						l = i;
						r = j;
					}
				}
			}
		}
		cout << go(l, n) << " " << go(r, n);
	}
    return 0;
}