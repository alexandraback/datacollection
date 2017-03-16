#pragma comment(linker, "/STACK:6400000000000")

#define _USE_MATH_DEFINES

#include <iostream>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <cassert>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <cmath>
#include <algorithm>
#include <sstream>
#include <stack>
#include <cstring>
#include <iomanip>
#include <ctime>
#include <stack>
#include <bitset>
using namespace std;

typedef long long ll;
typedef long double ld;

const ld EPS = 1e-12;
const int INF = (int)(2e9 + 0.5);
const int MAXN = 1000005;

int t, n, dp[MAXN];

int main() {
    freopen("INPUT.TXT", "r", stdin);
    freopen("OUTPUT.TXT", "w", stdout);
    for(int i = 0; i < MAXN; dp[i] = INF, ++i);
    dp[1] = 1;
    for(int i = 2; i < MAXN; ++i) {
        dp[i] = min(dp[i], dp[i - 1] + 1);
        vector<int> c;
        int next = 0;
        int bufi = i;
        while(bufi) {
            c.push_back(bufi % 10);
            bufi /= 10;
        }
        for(int j = 0; j < (int)c.size(); ++j) {
            next *= 10;
            next += c[j];
        }
        if(next >= 1 && next < MAXN && next >= i) {
            dp[next] = min(dp[next], dp[i] + 1);
        }
    }
    cin >> t;
    for(int q = 1; q <= t; ++q) {
        cin >> n;
        cout << "Case #" << q << ": " << dp[n] << endl;
    }
    return 0;
}
