#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <sstream>
#include <string>
#include <bitset>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>
#include <algorithm>
#include <complex>
#include <functional>
#include <limits>
#include <memory>
#include <numeric>
#include <utility>
#include <iomanip>

using namespace std;
typedef long long Int;


double ff(vector<double> const &ps, int const a, int const b) {
    double result = 1 + b + 1;
    double p = 1;
    for(int i = 0; i <= a; ++i) {
        int n = a - i;
        result = min(result, p * (n + n + b - a + 1) + (1 - p) * (n + n + b - a + 1 + b + 1));
        if(i != a) p *= ps[i];
    }
    return result;
}

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int a, b; cin >> a >> b;
        
        auto ps = vector<double>(a);
        for(int i = 0; i < a; ++i) {
            cin >> ps[i];
        }
        
        double y = ff(ps, a, b);
        cout << "Case #" << x <<": " << setprecision(10) << y << endl;
    }
}
