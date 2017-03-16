#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
double C, F, X;


void solve()
{
	scanf("%lf %lf %lf", &C, &F, &X);
	// double eps = 0.000001;
	// double prev = 0.0;
	// double ans = X / 2.0;
	// double minans = ans;
	// int cnt = 0;
	// while (fabs(ans - prev) > eps) {
	// 	double v = 2.0;
	// 	prev = ans;
	// 	ans = 0.0;
	// 	for (int i = 0; i < cnt; ++i) {
	// 		ans += C / v;
	// 		v += F;
	// 	}
	// 	ans += X / v;
	// 	++cnt;
	// 	printf("%d %lf\n", cnt, ans);
	// 	minans = min(ans, minans);
	// }
	int cnt = 0;
	while (true) {
		if (X / (2.0 + cnt * F) < C / (2.0 + cnt * F) + X / (2.0 + (cnt+1) * F)) {
			break;
		}
		//printf("%d\n", cnt);
		++cnt;
	}
	double ans = 0.0;
	double v = 2.0;
	for (int i = 0; i < cnt; ++i) {
		ans += C / v;
		v += F;
	}
	ans += X / v;

	printf("%.7lf", ans);
    return;
}

int main()
{
    int nCases = 0;
    scanf("%d", &nCases);
    for (int i = 1; i <= nCases; ++i) {
        cout << "Case #" << i << ": ";
        solve();
        cout << endl;
    }
}
