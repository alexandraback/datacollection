#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second

int p[4][4] = {{0, 0, 0, 0},
               {0, 4, 0, 4},
               {0, 4, 4, 0},
               {0, 0, 4, 4}};

int mul(int x, int y) {
    int res = p[x & 3][y & 3] ^ (x & 4) ^ (y & 4);
    res ^= (x & 3) ^ (y & 3);
    return res;
}
bool f(string &s) {
    int n = s.length();
    int cur = 0;
    int l = -1, r = -1;
    for (int i = 0; i < n; i ++) {
        int x = s[i] - 'i' + 1;
        if ((cur = mul(cur, x)) == 1) {
            l = i;
            break;
        }
    }
    cur = 0;
    for (int i = n - 1; i >= 0; i --) {
        int x = s[i] - 'i' + 1;
        if ((cur = mul(x, cur)) == 3) {
            r = i;
            break;
        }
    }
    cur = 0;
    for (int i = 0; i < n; i ++) {
        int x = s[i] - 'i' + 1;
        cur = mul(cur, x);
    }
    return l >= 0 && r >= 0 && l < r && cur == 4;
}

int _main() {
    LL l, x; cin >> l >> x;
    string s; cin >> s;
    string ss = "";
    int t = x; if (x > 8) t = x % 4 + 8;
    for (int i = 0; i < t; i ++) ss += s;
    if (f(ss)) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cout << "Case #" << i + 1 << ": "; _main();
    }

    return 0;
}

