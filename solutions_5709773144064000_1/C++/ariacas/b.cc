#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <set>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <numeric>
#include <cmath>
#include <map>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;

int main() {
    int T;
    cin >> T;
    for (int test = 1; test <= T; ++test) {
        printf("Case #%d: ", test);
        double c,f,x;
        scanf("%lf%lf%lf",&c,&f,&x);
        double res = x/2, time = 0;
        for (int i = 0; i <= 10000000; ++i) {
            double speed = 2 + i * f;
            res = min(res, time + x / speed);
            time += c / speed;
        }
        printf("%.8lf\n", res);
    }
    return 0;
}
