#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cctype>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <bitset>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <list>
#include <stack>
#include <sstream>
#include <utility>
#include <numeric>
#include <functional>
using namespace std;
 
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define F(i,a) FOR(i,0,a)
#define ALL(x) x.begin(),x.end()
#define PB push_back
#define X first
#define Y second
#define MS(a, v) memset(a, v, sizeof a)
#define NL printf("\n")
#define SP system("pause")
#define INF 1e9
#define PI acos(-1)
#define EPS 1e-9
#define TR(ar, it) for ( decltype(ar.begin()) it = ar.begin(); it != ar.end(); it++ )
typedef long long LL;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	int cas;
	double t, farm, rate, goal, r, ac;
	cin >> cas;
	F(z, cas) {
		t = -1;
		r = 2;
		ac = 0;
		cin >> farm >> rate >> goal;

		while (true) {
			double tr = goal / r;
			if (t == -1) t = tr;
			else {
				double sol = ac + tr;
				if (sol > t) break;	
				t = min(t, sol);
			}
			ac += farm / r;
			r += rate;
			// printf("%lf\n", ac);
		}

		printf("Case #%d: %.7lf\n", z + 1, t);
	}
	return 0;
}