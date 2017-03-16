#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

const int maxn = 2;

double d;
int n;
double x[maxn], t[maxn];
double a;


int main() {
    int cases;
    cin >> cases;
    cout.precision(9);
    cout << fixed;
    for (int cs = 1; cs <= cases; cs++) {
	cout << "Case #" << cs << ":" << endl;

	int na;
	cin >> d >> n >> na;
	REP(i, n)
	    cin >> t[i] >> x[i];

	for (; na > 0; na--) {
	    cin >> a;

	    double th = sqrt(2*d/a);

	    if (x[0] < d) {
		double vc = (x[1]-x[0]) / (t[1]-t[0]);
		double tc = t[0] + (d-x[0]) / vc;

		cout << max(th, tc);
	    }
	    else {
		cout << th;
	    }
	    cout << endl;
	}


    }
}
