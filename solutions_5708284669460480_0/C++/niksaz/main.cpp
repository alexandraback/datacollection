#include <algorithm>
#include <cstdio>
#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <string>
#include <sstream>
#include <queue>
#include <bitset>
#include <fstream>
#include <stack>
#include <deque>
#include <utility>
#include <numeric>

using namespace std;
typedef long long ll;
typedef pair <int, int> pii;

int sum;
int cnt;
int need;
int k;
int l;
int s;
string key;
string tar;

void gen1(int ps, string c) {
    if (ps == s) {
        int cur = 0;
        for (int i = 0; i <= ps - l; i++) {
            if (c.substr(i, l) == tar) {
                cur++;
            }
        }
        need = max(need, cur);
        return;
    }
    for (int i = 0; i < k; i++) {
        gen1(ps + 1, c + key[i]);
    }
}

void gen(int ps, string c) {
    if (ps == s) {
        int cur = 0;
        for (int i = 0; i <= ps - l; i++) {
            if (c.substr(i, l) == tar) {
                cur++;
            }
        }
        cnt++;
        sum += need - cur;
        return;
    }
    for (int i = 0; i < k; i++) {
        gen(ps + 1, c + key[i]);
    }
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cout << setprecision(9) << fixed;
    int tests;
    cin >> tests;
    for (int t = 1; t <= tests; t++) {
        cin >> k >> l >> s;
        cin >> key;
        cin >> tar;
        sum = 0;
        cnt = 0;
        need = 0;
        gen1(0, "");
        gen(0, "");
        double ans = (sum + 0.0) / cnt;
        cout << "Case #" << t << ": " << ans << "\n";
    }
    return 0;
}