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
    vector<int> can(v + 1);
    can[0] = 1;
    for(int i = 0; i < d; i ++) {
        cin >> now[i];
    }
    for(int i = 0; i < d; i ++) {
        for(int j = v; j >= 0; j --) {
            if (can[j] && j + now[i] <= v) {
                can[j + now[i]] = 1;
            }
        }
    }
    int ret = 0;
    for(int k = 1; k <= v; k ++) {
        if (can[k] == 0) {
            ret ++;
            for(int j = v; j >= 0; j --) {
                if (can[j] && j + k <= v) {
                    can[j + k] = 1;
                }
            }
        }
    }
    cout << "Case #" << ncase << ": " << ret << endl;

}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("C-small-attempt0.in", "r", stdin);
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
