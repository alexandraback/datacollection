#include<cstdio>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<string>
#include<algorithm>
#include<map>
#include<sstream>
#include<cmath>
#include<cctype>
#include<cassert>
#include<cstring>
#include<cstdlib>

using namespace std;

// ------------- PRE-WRITTEN CODES ---------------------------------

// defines and const
#define DEBUG(x) cout<<">> "<<#x<<':'<<(x)<<endl
const int inf = 1000000000;

// input reading
template<class T>
vector<T> takeInput(int n) {
	vector<T> list;
	T a; int i;
	for(i = 0; i < n; i++) { cin >> a; list.push_back(a); }
	return list;
}

// math
long long ncr[305][305] = {0};
void gen_ncr(int n) {
	int i, j;
	for(i = 0; i <= n; i++) ncr[i][0] = 1;
	for(i=1; i<=n; i++) for(j=1;j<=n;j++)  ncr[i][j] = ncr[i-1][j] + ncr[i-1][j-1];
}

double dis(double x1, double y1, double x2, double y2) {
	return sqrt( (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
}

// --------------- END of PRE-WRITTEN CODES --------------------------

int main() {
	int test, cases = 1;
	cin >> test;
	for( cases = 1; cases <= test; cases++) {
		int n, x, y;
		int cx, cy;
		cx = cy = 0;
		cy = -2;
		cin >> n >> x >> y;
		int cnt = 0;
		for(int i = 1; ; i += 4) {
			if( cnt + i > n ) break;
			cnt += i;
			cy += 2;
		}
		if( x < 0 ) x *= -1;
		int xx, yy;
		xx = x; yy = y;

		while( xx != 0 ) xx--, yy++;
		if( yy <= cy ) {
			printf("Case #%d: %.6lf\n", cases, 1.0);
			continue;
		}

		int rem = n - cnt;
		int how = 1;
		xx = x; yy = y;
		while(yy != 0 ) yy--, how++;

		int tot = (1<<rem);
		int res = 0;
		for(int i = 0; i < tot; i++) {
			if( __builtin_popcount(i) >= how ) res++;
		}
		if( x == 0 ) {
			printf("Case #%d: %.6lf\n", cases, 1.0 * 0);
		}
		else
		printf("Case #%d: %.6lf\n", cases, 1.0 * res / tot);


	}
	return 0;
}
