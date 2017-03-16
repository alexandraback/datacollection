#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cassert>
#include <boost/range/irange.hpp>
#include <boost/range/algorithm.hpp>
#include <boost/assign.hpp>
using namespace std;
using namespace boost;
using namespace boost::assign;
int dfs(int i, vector<bool> & ok, int c, set<int> & d, int v) {
    if (i == v) return ok[i] ? 0 : 1;
    if (ok[i]) return dfs(i+1, ok, c, d, v);
    int result = v;
    for (int e : d) {
        if (0 <= i-e and not d.count(i-e)) {
            vector<int> diff;
            for (int j : irange(0,v+1)) {
                if (ok[j] and j+i-e < v+1 and not ok[j+i-e]) {
                    diff += j+i-e;
                }
            }
            for (int f : diff) ok[f] = true;
            d += i-e;
            result = min(result, dfs(i+1, ok, c, d, v));
            d.erase(i-e);
            for (int f : diff) ok[f] = false;
        }
    }
    return result + 1;
}
int solve(int c, set<int> d, int v) {
    // assert (c == 1 and 1 <= d.size() and d.size() <= 5 and 1 <= v and v <= 30);
    if (c != 1) return -1;
    vector<bool> ok(v+1);
    ok[0] = true;
    vector<int> diff;
    for (int e : d) {
        for (int i : irange(0,v+1)) {
            if (ok[i] and i+e < v+1 and not ok[i+e]) {
                diff.push_back(i+e);
            }
        }
        for (int f : diff) ok[f] = true;
    }
    d += 0;
    return dfs(1, ok, c, d, v);
}
int main() {
    ios_base::sync_with_stdio(false);
    int t; cin >> t;
    for (int i : irange(0, t)) {
        int c, dl, v; cin >> c >> dl >> v;
        set<int> d; for (int i : irange(0,dl)) { int e; cin >> e; d += e; }
        cout << "Case #" << i+1 << ": " << solve(c,d,v) << endl;
    }
    return 0;
}
