#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <ctime>

#define inf 0x3f3f3f3f
#define Inf 0x3FFFFFFFFFFFFFFFLL
using namespace std;
typedef long long ll;
int const maxn = 1001000;
double ans[maxn];
int main() {
    freopen("B-small-attempt2.in", "r", stdin); freopen("B-small-ans.txt", "w", stdout);
  //  freopen("B-large.in", "r", stdin);  freopen("B-large-ans.txt", "w", stdout);
	
	
	int T, ca = 1;
	int x, y, n;
	for (scanf("%d", &T); T--; ) {
		scanf("%d %d %d", &n, &x, &y);
		if (x < 0) x = -x;
		if (n == 1) {
			if (x == 0 && y == 0) printf("Case #%d: %.10lf\n", ca++, 1.0);
			else  printf("Case #%d: %.10lf\n", ca++, 0.0);
			continue;
		}
		//cin>>n;
		int l = 0, s = 0, b = 1, d;
		int z = 0;
		int a = (x + y);
		while (s < n) {
			d = n - s;
			s += b;
			l += 2;
			++z;
			b += 4;
		}
		l -= 2;
		
		if ((x + y) / 2 + 1 < z) {
			printf("Case #%d: %.10lf\n", ca++, 1.0);
			continue;
		}
		else if ((x + y) / 2 + 1 > z) {
			printf("Case #%d: %.10lf\n", ca++, 0.0);
			continue;
		}
		double t = 1.0;
		for (int i = 0; i <= l; ++i) ans[i] = 0;
		for (int i = 0; i < d; ++i) {
			if (i < l) {
				for (int j = i; j >= 1; --j) {
					ans[j] = ans[j - 1] * 0.5;
				}
				ans[0] += 0.5 * t; t *= 0.5;
			}
			else if (i < l + l){
				ans[i - l] = 1;
				for (int j = i - l + 1; j < l; ++j) {
					ans[j] = ans[j - 1] * 0.5;
				}
			}
			else ans[l] = 1;
			//for (int j = 0; j <= l; ++j) cout << ans[j] << " "; cout << endl;
		}
		printf("Case #%d: %.10lf\n", ca++, ans[y]);
	}
	return 0;
}


