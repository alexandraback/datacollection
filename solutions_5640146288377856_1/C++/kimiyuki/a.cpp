#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
using namespace std;
using namespace boost;
int solve(int r, int c, int w) {
    int result = 0;
    result += (r - 1) * (c / w);
    result += (c - 1) / w + w;
    return result;
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for (int i : irange(0, t)) {
        int r, c, w; cin >> r >> c >> w;
        cout << "Case #" << i+1 << ": " << solve(r,c,w) << endl;
    }
    return 0;
}
