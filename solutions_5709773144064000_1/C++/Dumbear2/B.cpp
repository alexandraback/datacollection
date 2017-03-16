/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

int t;

void solve() {
    double C, F, X;
    scanf("%lf%lf%lf", &C, &F, &X);
    double rate = 2.0, cost = 0.0;
    int cnt = 0;
    double res = X / rate;
    for (int i = 0; ; ++i) {
        cost += C / rate;
        rate += F;
        double tmp = cost + X / rate;
        if (tmp < res) {
            res = tmp;
        } else {
            break;
        }
    }
    printf("Case #%d: %.12f\n", ++t, res);
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
