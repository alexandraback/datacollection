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
int countin(string& a, string& b) {
    int ret = 0;
    for(int s = 0; s < a.size(); s ++) {
        if (a.substr(s, b.size()) == b) {
            ret ++;
        }
    }
    return ret;
}
void solve(int ncase) {
    int boardlen, wordlen, monkeylen;
    cin >> boardlen >> wordlen >> monkeylen;
    string board, target;
    cin >> board >> target;
    int num = 1;
    for(int i = 0; i < monkeylen; i ++) {
        num *= boardlen;
    }
    int maxb = 0, sumb = 0;
    for(int k = 0; k < num; k ++) {
        int x = k;
        string monkey;
        for(int i = 0; i < monkeylen; i ++) {
            monkey.push_back(board[x % boardlen]);
            x /= boardlen;
        }
        int tmp = countin(monkey, target);
        sumb += tmp;
        maxb = max(maxb, tmp);
    }
    //cout << maxb << " " << sumb << endl;
    double ret = (maxb * 1.0 * num - sumb) / num;
    cout << "Case #" << ncase << ": " << std::fixed << setprecision(16) << ret << endl;

}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("B-small-attempt0.in", "r", stdin);
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
