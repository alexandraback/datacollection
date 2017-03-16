// David Wahler <dwahler@gmail.com>
// Google Code Jam submission: 

#include <algorithm>
#include <functional>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

#define D(x) 

struct key {
    int l, r, n;

    key(int l, int r, int n) : l(l), r(r), n(n) {}

    bool operator<(const key& k) const {
        if (l != k.l) return l<k.l;
        if (r != k.r) return r<k.r;
        return n<k.n;
    }
};

double solve(int l, int r, int n, int t, map<key, double>& memo) {
    key k(l, r, n);
    map<key, double>::iterator it = memo.find(k);
    if (it != memo.end()) return it->second;
    D(cerr << "solve(" << l << ", " << r << ", " << n << ", " << t << ")" << endl);

    double result;
    if (l >= t) {
        result = 1.0;
    } else if (n<=0) {
        result = 0.0;
    } else {
        result = 0.5*solve(l+1, r, n-1, t, memo) + 0.5*solve(l, r+1, n-1, t, memo);
    }
    memo[k] = result;
    D(cerr << "solve(" << l << ", " << r << ", " << n << ", " << t << ") = " << result << endl);
    return result;
}


int main() {
    int T;
    cin >> T;
    
    for (int testCase = 1; testCase <= T; testCase++) {
        int N, X, Y;
        cin >> N >> X >> Y;

        double prob;

        int level = 0;
        while (true) {
            int levelCount = 2*level*level + 3*level + 1;
            if (N <= levelCount) {
                int lastLevel = level-1;
                int lastCount = 2*lastLevel*lastLevel + 3*lastLevel + 1;
                int offset = N - lastCount;
                D(cerr << "level=" << level << " lastCount=" << lastCount << " offset=" << offset << endl);

                int tgtLevel = abs(X)+abs(Y)-1;
                if (tgtLevel < level) {
                    prob = 1;
                } else if (tgtLevel > level) {
                    prob = 0;
                } else if (N == levelCount) {
                    prob = 1;
                } else {
                map<key, double> memo;
                   prob = solve(0, 0, offset, Y+1, memo);
                }
                break;
            }
            level++;
        }

                
                
        cout << "Case #" << testCase << ": ";
        cout << prob;
        cout << endl;
    }
}
