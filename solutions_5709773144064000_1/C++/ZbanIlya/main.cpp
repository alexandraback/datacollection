#include <iostream>
#include <string>
#include <map>
#include <math.h>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <set>
#include <queue>
#include <sstream>
#include <deque>
#include <memory.h>
#include <cassert>
#include <ctime>


using namespace std;

#define ll long long
#define y1 _dfdfdfd


const int maxn = 1 << 10;
const int inf = 1000000007;
const int mod = 1000000007;


 
int main() {
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);

    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; test++) {
        cout << "Case #" << test << ": ";
        double c, f, x;
        cin >> c >> f >> x;
        
        double ans = 1e18;
        double cur = 0;
        for (int cnt = 0; cnt <= x; cnt++) {
            double res = cur + x / (2.0 + cnt * f);
            ans = min(ans, res);
            cur += c / (2.0 + cnt * f);
        }
        printf("%.10lf\n", ans);
    }

	return 0;
}
