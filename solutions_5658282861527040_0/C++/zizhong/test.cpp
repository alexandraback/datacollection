#include <vector>
#include<cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
using namespace std;
typedef pair<int, int> PII;
typedef long long ll;

void solve(int ncase) {
    ll a, b, k;
    cin >> a >> b >>  k;
    int ans = 0;
    for(int i = 0; i < a; i ++) {
        for(int j = 0; j < b; j ++) {
            if ((i & j) < k) {
                ans ++;
            }
        }
    }
    cout << "Case #" << ncase << ": " << ans << endl;
}
int main() {
    ios::sync_with_stdio(false);
    //cout << setprecision(16) << endl;
#ifdef _zzz_
   freopen("B--small-attempt0.in", "r", stdin);
freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
