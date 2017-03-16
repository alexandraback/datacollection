/*
 TASK:C
 LANG:C++
 Muhammad Magdi Muhammad
 Email: moh_magdi@acm.org
 */
#include <map>
#include <deque>
#include <queue>
#include <stack>
#include <sstream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <vector>
#include <set>
#include <complex>

#define all(v)          v.begin(),v.end()
#define allr(v)         v.rbegin(),v.rend()
#define rep(i,m)        for(int i=0;i<(int)m;i++)
#define REP(i,k,m)      for(int i=k;i<(int)m;i++)
#define mem(a,b)        memset(a,b,sizeof(a))
#define mp              make_pair
#define pb              push_back
#define OO ((int)1e9)
#define MAX 100000

typedef long long ll;

int diri[] = { -1, 0, 1, 0, -1, 1, 1, -1 };
int dirj[] = { 0, 1, 0, -1, 1, 1, -1, -1 };
int compare(double d1, double d2) {
	if (fabs(d1 - d2) < 1e-9)
		return 0;
	if (d1 < d2)
		return -1;
	return 1;
}
int I, J;
inline bool valid(const int &i, const int &j) {
	if (i < 0 || j < 0 || i >= I || j >= J)
		return false;
	return true;
}

using namespace std;

#define SMALL
//#define LARGE
int T;
int arr[2000000];
int mid = 1000000;

struct testcase {
	int start_d, att_cnt, sw, se, pow, delt_start_d, delta_sw_se, delta_pow;
	bool operator<(const testcase & t) const {
		return start_d < t.start_d;
	}
};

int main() {

	freopen("1.in", "rt", stdin);
#ifdef SMALL
	freopen("C-small-attempt0.in","rt",stdin);
	freopen("C-small.out","wt",stdout);
#endif
#ifdef LARGE
	freopen("C-large.in","rt",stdin);
	freopen("C-large.out","wt",stdout);
#endif
	cin >> T;
	rep(tt,T) {
		printf("Case #%d: ", tt + 1);
		int n;
		cin >> n;
		mem(arr, 0);
		ll ans = 0;

		vector<testcase> tests;
		rep(i,n) {
			testcase r;
			cin >> r.start_d >> r.att_cnt >> r.sw >> r.se >> r.pow
					>> r.delt_start_d >> r.delta_sw_se >> r.delta_pow;
			while (r.att_cnt--) {
				tests.pb(r);
				r.start_d += r.delt_start_d;
				r.sw += r.delta_sw_se, r.se += r.delta_sw_se;
				r.pow += r.delta_pow;
			}
		}
		sort(all(tests));
		vector<pair<int,pair<int, int> > > repare;
		sort(all(repare));
		rep(i,tests.size()) {
			testcase &r = tests[i];
			bool nochange = 0;
			if (i && tests[i - 1].start_d != r.start_d) {
				rep(j,repare.size()) {
					for (int i = repare[j].second.first; i < repare[j].second.second ; i++)
						arr[i + mid] = max(repare[j].first ,arr[i + mid]);
				}
				nochange = 1;
			}

			

			for (int i = r.sw; i < r.se; i++) {
				if (arr[i + mid] < r.pow) {
					ans++;
					break;
				}
			}
			if (!nochange)
				for (int i = r.sw; i < r.se; i++)
					arr[i + mid] = max(r.pow, arr[i + mid]);
			else
				repare.push_back(mp(r.pow,mp(r.sw, r.se))) ;

		}
		cout << ans << endl;
		cerr << tt << endl;
	}
	return 0;
}
//end

