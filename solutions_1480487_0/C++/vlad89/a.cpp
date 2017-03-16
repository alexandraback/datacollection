#include <cstring>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define REP(i,n) FOR(i,0,n)
#define all(a) (a).begin(),(a).end()
#define UN(a) sort(all(a)),(a).resize(unique(all(a))-(a).begin())
#define sz(a) ((int) (a).size())
#define pb push_back
#define CL(a,b) memset ((a), (b), sizeof (a))
#define X first
#define Y second

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

string testname = "A-small-attempt0";

int a[256];
double b[256];

int main () {
    freopen((testname+".in").c_str(), "r", stdin);
    freopen((testname+".out").c_str(), "w", stdout);
    int t;
    cin >> t;
    FOR(test, 1, t+1) {
	int n;
	cin >> n;
	int S = 0;
	REP (i, n) {
	    cin >> a[i];
	    S += a[i];
	}
	REP (i, n) {
	    double b1 = 0, b2 = 1;
	    REP (it, 100) {
		double mid = (b1 + b2) / 2;
		double got = a[i] + mid * S;
		double h = 1-mid;
		REP (j, n) if (j != i) {
		    h -= max(got - a[j], 0.0) / S; 
		}
		if (h < 0) {
		    b2 = mid;
		} else {
		    b1 = mid;
		}
	    }
	    b[i] = (b1+b2)/2;
	}
	printf("Case #%d:", test);
	REP (i, n) {
	    printf(" %.9lf", b[i]*100);
	}
	printf("\n");
    }
    return 0;
}
