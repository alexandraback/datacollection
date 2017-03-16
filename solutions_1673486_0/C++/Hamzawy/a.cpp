/*
 * a.cpp
 *
 *  Created on: Apr 28, 2012
 *      Author: AhmedHamza
 */

#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <cstring>
#include <vector>
#include <set>
#include <complex>

#ifdef _MSC_VER
#include<hash_set>
#include<hash_map>
using namespace stdext;
#else
#if __GNUC__ >2
#include<ext/hash_set>
#include<ext/hash_map>
using namespace __gnu_cxx;
#else
#include<hash_set>
#include<hash_map>
#endif
#endif

using namespace std;

#define pb push_back
#define all(v) v.begin(),v.end()
#define sz size()
#define rep(i,m) for(__typeof(m) i=0;i<m;i++)
#define mem(a,b) memset(a,b,sizeof(a))
#define mp make_pair
typedef stringstream ss;
typedef pair<int, int> pii;
typedef vector<pii> vpii;
typedef vector<string> vs;
typedef vector<int> vi;
typedef vector<vector<int> > vii;
typedef long long ll;
typedef long double ld;

ld p[100000];
int a, b;

#define SMALL_INPUT

int main() {
#ifdef SMALL_INPUT
	freopen("a-small-attempt0.in", "rt", stdin);
	freopen("a-small.out", "wt", stdout);
#endif
#ifdef LARGE_INPUT
	freopen("a-large.in", "rt", stdin);
	freopen("a-large.out", "wt", stdout);
#endif
	int tc;
	cin >> tc;
	rep(T,tc) {
		cin >> a >> b;

		ld tp = 1.0;

		rep(i,a)
			cin >> p[i], tp *= p[i];

		ld ans = 2.0 + b;

		for (int i = 0; i <= a; ++i) {
			int ca = (b - a + 1 + 2 * i), cb = (2 * b - a + 3 + i);
			cb = ca + b + 1;
			ld cur = tp * ca + (1 - tp) * cb;
			//       0.36*
//			cout << tp << " " << ca << " " << (1 - tp) << " " << cb << " "
//					<< cur << endl;
			ans = min(ans, cur);
			if (i != a)
				tp /= p[a - i - 1];
		}

		//cout << "Case #" << T + 1 << ": " << ans << endl;
		printf("Case #%d: %.6lf\n", T + 1, (double) ans);
	}
	return 0;
}

