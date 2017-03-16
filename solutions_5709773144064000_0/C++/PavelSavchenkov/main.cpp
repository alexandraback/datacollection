#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

inline bool eq( double x, double y ) {
	return fabs(x - y) < EPS;
}

inline bool gr( double x, double y ) {
	return x > y && !eq(x, y);
}

double c, f, x;

double solve() {
	double sum = 0;
	double add = 2.0;
	double res = x * 0.5;
	double Time = 0;

	while (!gr(sum, x) && !gr(Time, res)) {
		
		// sum + add * t == x
		double cur_res = ((x - sum) / add) + Time;
		if  (res > cur_res + EPS) {
			res = cur_res;
		}	

		if  (sum >= c) {
			add += f;
			sum -= c;
			continue;
		}

		// sum + add * t == c
		double add_Time = (c - sum) / add;
		sum += add_Time * add - c;
		add += f;
		Time += add_Time;
	}

	return min(res, Time);
}

int main() {
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);

	int t;
	scanf("%d", &t);
	forn(it, t) {
		scanf("%lf%lf%lf", &c, &f, &x);

		printf("Case #%d: %.10lf\n", it + 1, solve());	
	}
		
	return 0;
}
