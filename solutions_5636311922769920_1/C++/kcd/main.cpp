#include <iostream>
#include <cstdio>
#include <sstream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#include <cmath>
#include <ctime>
#include <utility>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <ctime>



using namespace std;

typedef long long LL;
template<class T> inline T Abs(const T& x) { return x < 0 ? -x : x; }
template<class T> inline T Sqr(const T& x) { return x * x; }


void Solution() {
    LL k, c, s;
    cin >> k >> c >> s;
    vector<LL> p(c + 1, 1);
    for (LL i = 1; i <= c; ++i) {
        p[i] = p[i - 1] * k;
    }
    vector<LL> ans;
    int got = 0;
    while (got < k) {
        LL ind = 0;
        for (LL i = 0; i < min(c, k - got); ++i) {
            ind += p[c - 1 - i] * (got + i);
        }
        got += min(c, k - got);
        ans.push_back(ind + 1);
    }
    if (ans.size() > s) {
        cout << "IMPOSSIBLE" << endl;
    } else {
        for (size_t i = 0; i < ans.size(); ++i) {
            cout << ans[i] << " ";
        }
        cout << endl;
    }
}

int main() {
    int t;
    cin >> t;
    for (int i = 0; i < t; ++i) {
        cout << "Case #" << i + 1 << ": ";
        Solution();
    }

    return 0;
}


