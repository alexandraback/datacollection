#include <list>
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

int main()
{
#define SAMPLE_NAME "B"
	if( freopen(SAMPLE_NAME "-large.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-large.out", "wt", stdout);
	} else 	if( freopen(SAMPLE_NAME "-small.in", "rt", stdin) ) {
		freopen(SAMPLE_NAME "-small.out", "wt", stdout);
	} else ( freopen("test.txt", "rt", stdin) );

	int T;
	cin >> T;

	for(int case_num = 1; case_num <= T; ++case_num)
	{
		cerr << case_num << endl;
		int X, Y;
		cin >> X >> Y;
		char ans[501] = {0};
		int a = 0;
		int x = 0, y = 0;

		if(X > 0) {
			while(x < X) {
				ans[a++] = 'E';
				x += a;
			}
		} else {
			while(x > X) {
				ans[a++] = 'W';
				x -= a;
			}
		}
		if(Y > 0) {
			while(y < Y) {
				ans[a++] = 'N';
				y += a;
			}
		} else {
			while(y > Y) {
				ans[a++] = 'S';
				y -= a;
			}
		}

		if(X > 0) {
			while(x != X) {
				ans[a++] = 'E';
				ans[a++] = 'W';
				--x;
			}
		} else {
			while(x != X) {
				ans[a++] = 'W';
				ans[a++] = 'E';
				++x;
			}
		}
		if(Y > 0) {
			while(y != Y) {
				ans[a++] = 'N';
				ans[a++] = 'S';
				--y;
			}
		} else {
			while(y != Y) {
				ans[a++] = 'S';
				ans[a++] = 'N';
				++y;
			}
		}
		ans[a] = '\0';

		cout << "Case #" << case_num << ':' << ' ' << ans << endl;
	}
 	return 0;
}

// EOF
