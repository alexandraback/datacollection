//Seikang

#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <stdlib.h>
#include <assert.h>

#include <vector>
#include <set>
#include <map>
#include <list>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>

#include <cmath>
#include <complex>
#include <algorithm>

#include <ctime>
#define gtime clock()

using namespace std;

#define SZ(cont) (int)(cont.size())
#define ALL(cont) (cont).begin(), (cont).end()
#define DEBUG(x) cerr << ">" << #x << ":" << x << endl

typedef long long int64;
typedef pair<int64, int64> ii;
typedef vector<int64> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<string> vs;

const int64 oo32 = 1ll << 30, oo64 = 1ll << 60;
const double pi = acos(-1.0), eps = 1e-9;
inline bool equal(const double &a, const double &b){return abs(a - b) < eps;}

double compute(double C, double F, double X)
{
	double cps = 2.0;
	double seconds = 0;
	double best = 1000000000.0;
	
	for (int mills = 0; mills < 100000; ++mills)
	{
		double tmp = seconds + (X / cps);
		best = min(tmp, best);

		seconds += C / cps;
		cps += F;
	}

	return best;
}

int main()
{
	//freopen ("b.in", "rt", stdin);
	//freopen ("b.out", "wt", stdout);

	double t, c, f, x;
	cin >> t;
	cout.precision(15);
	for (int i = 1; i <= t; ++i)
	{
		cin >> c >> f >> x;
		cout << "Case #" << i << ": " << compute(c, f, x) << endl;
	}
	return 0;
}
