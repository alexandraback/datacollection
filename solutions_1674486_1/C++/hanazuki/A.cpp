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

static double const eps = 1e-10;


bool v[1050];
bool dfs(int i, map<int, set<int> > &aa) {
    v[i] = true;
    for(const auto &a: aa[i]) {
        if(v[a]) { return true; }
        if(dfs(a, aa)) return true;
    }
    return false;
}

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n; cin >> n;
        
        auto aa = map<int, set<int> >();
        for(auto i = 0; i < n; ++i) {
            int m; cin >> m;
            for(auto j = 0; j < m; ++j) {
                int p; cin >> p; p -= 1;
                aa[i].insert(p);
            }
        }
        
        bool y = false;
        for(auto i = 0; i < n; ++i) {
            fill(begin(v), end(v), false);
            if(dfs(i, aa)) { y = true; break; }
        }
        string ys= y ? "Yes" : "No";
        
        cout << "Case #" << x <<": " << setprecision(9) << fixed << ys << endl;
    }
}
