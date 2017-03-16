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

struct fc {
    Int num;
    int typ;
    fc(Int num, int typ) : num(num), typ(typ) { }
};

Int calc(deque<fc> &aa, deque<fc> &bb) {
    if(aa.size() == 0 || bb.size() == 0) {
        return 0;
    }
    if(aa.front().num == 0) {
        aa.pop_front();
        return calc(aa, bb);
    }
    if(bb.front().num == 0) {
        bb.pop_front();
        return calc(aa, bb);
    }
    if(aa.front().typ == bb.front().typ) {
        Int c = min(aa.front().num, bb.front().num);
        auto aa_ = new auto(aa), bb_ = new auto(bb);
        aa_->front().num -= c;
        bb_->front().num -= c;
        return c + calc(*aa_, *bb_);
    }
    
    auto a = aa.front();
    auto b = bb.front();
    
    aa.pop_front();
    auto ra = calc(aa, bb);
    aa.push_front(a);

    bb.pop_front();
    auto rb = calc(aa, bb);
    bb.push_front(b);
    
    return max(ra, rb);
}

int main() {
    int t; cin >> t;
    for(int x = 1; x <= t; ++x) {
        int n, m; cin >> n >> m;
        
        deque<fc> aa, bb;
        for(auto i = 0; i < n; ++i) {
            Int num, typ; cin >> num >> typ;
            aa.push_back(fc(num, typ));
        }
        for(auto i = 0; i < m; ++i) {
            Int num, typ; cin >> num >> typ;
            bb.push_back(fc(num, typ));
        }
        
        Int y = calc(aa, bb);
        cout << "Case #" << x <<": " << y << endl;
    }
}
