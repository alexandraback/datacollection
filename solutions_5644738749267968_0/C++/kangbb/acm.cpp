#include <cstdio>
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <ctime>
#include <cstring>

using namespace std;
//-----------------------------------------------------------
#define forn(i, n) for(int i = 0; i < (int)(n); i++)
#define ford(i, n) for(int i = (int)(n) - 1; i >= 0; i--)
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define last(a) int(a.size() - 1)
#define all(a) a.begin(), a.end()
#define seta(a,x) memset (a, x, sizeof (a))
#define I (int)
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef long double ldb;

const long double eps = 1e-9;
const int inf = (1 << 30) - 1;
const ull inf64 = ((ull) 1 << 62) - 1;
const long double pi = 3.1415926535897932384626433832795;
//-----------------------------------------------------------

#define MAXN 1010
int N;
double a[MAXN];
double b[MAXN];

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		memset(b, 0, sizeof(b));

		scanf("%d", &N);
		forn(i, N) 	scanf("%lf", &a[i]);
		forn(i, N) 	scanf("%lf", &b[i]);

		sort(a, a + N);
		sort(b, b + N);

		//forn(i, N) printf("%.3lf ", a[i]); printf("\n");
		//forn(i, N) printf("%.3lf ", b[i]); printf("\n");

		int sol1 = 0;
		int sol2 = 0;

		int xa = 0;
		int xb = 0;

		xa = N - 1;
		xb = N - 1;
		while(xa >= 0 && xb >= 0 ) {
			if(a[xa] > b[xb]) {
				sol1++;
				xa--;
				xb--;
			} else {
				xb--;
			}
		}

		xa = 0;
		xb = 0;
		while(xa < N && xb < N ) {
			if(a[xa] > b[xb]) {
				xb++;
				sol2++;
				continue;
			}
			else {
				xa++;
				xb++;
			}
		}



		printf("Case #%d: %d %d\n", casenum++, sol1, sol2);

	}
	return 0;
}
