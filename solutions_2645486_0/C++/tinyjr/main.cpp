#include <cstdio>
#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;
int T, cas;
long long r, t;
double ans, rr, tt;
int main(){
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	cin >> T;
	for (cas = 1; cas <= T; cas++){
		cin >> r >> t;
		rr = r; tt = t;
		ans = (2 * rr - 1) * (2 * rr - 1) + 8 * tt;
		ans = sqrt(ans);
		ans = ans + 1;
		ans = ans - 2 * r;
		ans = ans / 4;
		ans = floor(ans);
		if (ans < 0) ans = 0;
		printf("Case #%d: %d\n", cas, (int)ans);
	}
}
