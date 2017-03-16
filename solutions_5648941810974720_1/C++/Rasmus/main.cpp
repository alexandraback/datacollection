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

vector<string> z;

void go() {
	z.pb("ZERO");
	z.pb("ONE");
	z.pb("TWO");
	z.pb("THREE");
	z.pb("FOUR");
	z.pb("FIVE");
	z.pb("SIX");
	z.pb("SEVEN");
	z.pb("EIGHT");
	z.pb("NINE");
}

string c = "ZWGXUFTIS";
int n[] = {0,2,8,6,4,5,3,9,7};

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	go();
	int T;
	cin >> T;
	REPE(TT,1,T) {
		if (TT > 1) {
			cout << "\n";
		}
		cout << "Case #" << TT << ": ";
		cerr << TT << "\n";

		VI a(26);
		string s;
		cin >> s;
		FOR(i,s.size()) {
			int v = s[i] - 'A';
			a[v]++;
		}
		VI res(10);
		FOR(i,9) {
			int ind = n[i];
			int v = a[c[i] - 'A'];
			res[n[i]] += v;
			FOR(j,z[ind].size()) {
				int now = z[ind][j] - 'A';
				a[now] -= v;
				if (a[now] < 0) {
					throw 1;
				}
			}
		}
		int v = a['O' - 'A'];
		res[1] += v;
		a['O' - 'A'] -= v;
		a['N' - 'A'] -= v;
		a['E' - 'A'] -= v;
		FOR(i,26) {
			if (a[i] != 0) {
				throw 1;
			}
		}
		FOR(i,10) {
			FOR(j,res[i]) {
				cout << i;
			}
		}
	}
    return 0;
}