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

void solve(int ncase) {
    int c, d, v;
    cin >> c >> d >> v;
    vector<int> now(d);
    for(int i = 0; i < d; i ++) cin >> now[i];
    sort(now.begin(), now.end());
    ll x = 1;
    int ret = 0;
    int idx = 0;
    while(true) {
        //cout << x << " test" << endl;
        if (x > v) break;
        if (idx < now.size() && x >= now[idx]) {
            x += now[idx] * 1LL * c;
            idx ++;
            continue;
        }
        ret ++;
        x += x * c;
    }
    cout << "Case #" << ncase << ": " << ret << endl;

}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("C-large.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    //pre_calc();
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
