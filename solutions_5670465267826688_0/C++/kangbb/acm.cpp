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
#include <deque>
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

#define bit(i) ((ull)1 << i)
//-----------------------------------------------------------

#define MAXP 1010
int X, R, C;

void solve()
{
	if (X >= 7 || ((R * C) % X) != 0 || (X > R && X > C)) {
		printf("RICHARD\n");
		return;
	}
	if (X <= 2) {
		printf("GABRIEL\n");
		return;
	}
	if (X == 3) {
		if (R <= 1 || C <= 1) {
			printf("RICHARD\n");
		}
		else {
			printf("GABRIEL\n");
		}
		return;
	}
	if (X == 4) {
		if (R <= 2 || C <= 2) {
			printf("RICHARD\n");
		}
		else {
			printf("GABRIEL\n");
		}
		return;
	}

	if (X == 5) {
		if (R <= 2 || C <= 2) {
			printf("RICHARD\n");
		}
		else {
			printf("GABRIEL\n");
		}
		return;
	}

	if (X == 6) {
		if (R <= 3 || C <= 3) {
			printf("RICHARD\n");
		}
		else {
			printf("GABRIEL\n");
		}
		return;
	}
	fflush(stdout);
}

int main() {
	int cases;
	int caseid = 1;

	freopen("input", "r", stdin);
	freopen("output", "w", stdout);
	scanf("%d", &cases);
	while(cases--) {
		printf("Case #%d: ", caseid++);
		scanf("%d%d%d", &X, &R, &C);
		solve();
	}
	return 0;
}

