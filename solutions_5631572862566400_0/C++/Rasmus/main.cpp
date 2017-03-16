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

const int N = 15;
int a[N];
int n;
int res = 1;
int c[N];

int check(VI &b) {
	for(int i = n; i > res; --i) {
		FORE(k,n - i) {
			c[0] = b[i - 1 + k];
			c[i + 1] = b[k];
			FOR(j,i) {
				c[j + 1] = b[j + k];
			}
			bool check = true;
			REPE(j,1,i) {
				if (a[c[j]] != c[j - 1] && a[c[j]] != c[j + 1]) {
					check = false;
					break;
				}
			}
			if (check) {
				return i;
			}
		}
	}
	return -1;
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

		cin >> n;
		FOR(i,n) {
			int x;
			scanf("%d", &x);
			--x;
			a[i] = x;
		}

		res = 1;
		for(int i = n; i >= n; --i) {
			VI b(i);
			FOR(j,i) {
				b[j] = j;
			}
			do {
				int now = check(b);
				if (now != -1) {
					res = max(res, now);
				}
			} while(next_permutation(b.begin(), b.end()));
		}
		cout << res;
	}
    return 0;
}