#include <cassert>
#include <string>
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <sstream>
#include <vector>
#include <map>

#ifndef M_PI
#	define M_PI 3.1415926535
#endif

using namespace std;

#if 0
int calc(int (&mx)[101], int f, int t, int n, int len, int q = 0) {
	if(f >= t) return 0;
	
	int idm = max_element(&mx[f], &mx[t]) - &mx[0];
	if(mx[idm] >= n) {
		//int tt = 1 + t - f - mx[idm]; // (idm - mx[idm] - f) + 1 + (t - idm);
		int x = mx[idm] - n + 1;
		x *= x + 1;
		x /= 2;
		//int tt = 1 + len - n;
		int tt = x * ( (len - idm - 1) + (idm - mx[idm] + 1) - q );
		cout << f << ',' << t ; cout << ',' << tt << endl;
		return tt + calc(mx, idm + 1, t, n, len, 1) + calc(mx, f, idm - mx[idm], n, len, 1);
	}
	return 0;
}
#else
int calc(int (&mx)[101], int, int, int n, int len) {
	int ans = 0;

	for(int b = 0; b <= len - n; ++b) {
		int mxi = 0;
		int mni = *min_element(&mx[b], &mx[b+n-1]);
		for(int e = b + n-1; e < len; ++e) {
			mxi = max(mx[e], mxi);
			mni = min(mx[e], mni);
			if(mxi >= n && (mxi - mni + 1) >= n ) {
				ans += len - e;
				break;
			}
		}
	}
	return ans;
}

#endif

int main()
{
#define SAMPLE_NAME "A"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;
	static bool V[256] = {false};
	V['a'] = V['e'] = V['i'] = V['o'] = V['u'] = true;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		cerr << case_num << endl;

		char name[101];
		bool cons[101];
		int mx[101] = {0};
		int n;
		int ans = 0;
		cin >> name >> n;

		int len = (int)strlen(name);
		for(int i = 0; i < len; ++i) cons[i] = !V[ name[i] ];

		mx[0] = cons[0];
		for(int i = 1; i < len; ++i) {
			mx[i] = cons[i] ? (1 + mx[i-1]) : 0;
		}

		ans = calc(mx, 0, len, n, len);
		cout << "Case #" << case_num << ':' << ' ' << ans << endl;
	}
 	return 0;
}

// EOF
