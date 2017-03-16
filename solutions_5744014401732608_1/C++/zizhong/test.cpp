#include <vector>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <deque>
#include <set>
#ifdef __GXX_EXPERIMENTAL_CXX0X__
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#endif
#include <ctime>
#include <queue>
#include <stack>
#include<iomanip>
#include <sstream>
#include <cmath>
#include <list>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;
void precalc(){};
void solve(int ncase) {
    cout << "Case #" << ncase << ": ";
    ll b, m;
    cin >> b >> m;
    if (m > (1LL << (b - 2))) {
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    cout << "POSSIBLE" << endl;
    vector<vector<int>> f(b+1, vector<int>(b+1, 0));
    for(int i = 1; i < b; i ++) {
        for(int j = i + 1; j < b; j ++) {
            f[i][j] = 1;
        }
    }
    for(int i = b - 1; i >= 2; i --) {
        if (m >= (1LL << (i - 2))) {
            f[i][b] = 1;
            m -= (1LL << (i - 2));
        }
    }
    if (m) f[1][b] = 1;
    for(int i = 1; i <= b; i ++) {
        for(int j = 1; j <= b; j ++) {
            cout << f[i][j];
        }
        cout << endl;
    }
}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    //freopen("A-small-practice.in", "r", stdin);
    //freopen("A-large-practice.in", "r", stdin);
    //freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    //precalc();
    //cin >> T;
    scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
