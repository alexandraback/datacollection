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

string s[1005][2];
bool used[1005];

int main()
{
#ifdef _DEBUG
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
#else
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
#endif
	int T;
	cin >> T;
	REPE(TT,1,T) {
		if (TT > 1) {
			cout << "\n";
		}
		cout << "Case #" << TT << ": ";
		cerr << TT << "\n";
		memset(used, false, sizeof(used));

		int n;
		cin >> n;
		VI res(n);
		FOR(i,n) {
			cin >> s[i][0] >> s[i][1];
		}
		int wh = n - 1;
		FOR(i,n) {
			bool x = false;
			bool y = false;
			FOR(j,n) {
				if (x && y) {
					break;
				}
				if (used[j] || i == j) {
					continue;
				}
				if (s[i][0] == s[j][0]) {
					x = true;
				}
				if (s[i][1] == s[j][1]) {
					y = true;
				}
			}
			if (x && y) {
				res[wh--] = i;
				used[i] = true;
			}
		}
		FOR(i,n) {
			if (!used[i]) {
				res[wh--] = i;
			}
		}
		/*FOR(i,n) {
			cout << s[res[i]][0] << " " << s[res[i]][1] << "\n";
		}*/
		int out = 0;
		FOR(i,n) {
			bool x = false;
			bool y = false;
			FOR(j,i) {
				if (x && y) {
					break;
				}
				if (s[res[i]][0] == s[res[j]][0]) {
					x = true;
				}
				if (s[res[i]][1] == s[res[j]][1]) {
					y = true;
				}
			}
			if (x && y) {
				++out;
			}
		}
		cout << out;
	}
    return 0;
}