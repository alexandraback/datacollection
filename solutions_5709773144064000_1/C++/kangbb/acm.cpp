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

#define MAXN 17
int N;

double C, F, X;

int main() {
	int cases;
	int casenum = 1;
	freopen("input", "r", stdin);
	freopen("output", "w", stdout);

	scanf("%d", &cases);
	while (cases--) {

		//memset(b, 0, sizeof(b));

		scanf("%lf%lf%lf", &C, &F, &X);

		double d = 2;
		double ans = 0;

		while(true) {

			// To reach the X
			double toX = X / d;

			// To reach the C
			if( C / d + X / (d + F) < toX ){
				ans += C / d;
				d += F;
			}
			else {
				ans += toX;
				break;
			}

		}


		printf("Case #%d: %.7lf\n", casenum++, ans);

	}
	return 0;
}
