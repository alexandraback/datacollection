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
typedef pair<int, int> PII;
typedef pair<int, double> PID;
typedef pair<string, int> PSI;
typedef pair<string, string> PSS;
typedef pair<PII, int> PIP;

void solve(int ncase) {
    int flag = 1;
    int x, r, c;
    cin >> x >> r >> c;
    if (r > c) swap(r, c);
    if (r * c % x != 0) {
        flag = 1;
    } else if (x == 1 || x == 2) {
        flag = 2;
    } else if (x == 3) {
        if (r < 3 && c < 3 || r < 2 || c < 2) flag = 1;
        else flag = 2;
    } else if (x == 4) {
        if (r < 2 || c < 4 || (r == 2 && c == 4)) flag = 1;
        else flag = 2;
    } else if (x == 5) {
        if (r < 3 || c < 5) flag = 1;
        else flag = 2;
    } else if (x == 6) {
        if (r <= 3 || c < 6) flag = 1;
        else flag = 2;
    } else if (x >= 7) {
        flag = 1;
    }
    cout << "Case #" << ncase << ": " << (flag == 1 ? "RICHARD" : "GABRIEL") << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    //freopen("in.txt", "r", stdin);
    freopen("D-small-attempt0.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    //init();
    int T = 1;
    cin >> T;
    //scanf("%d", &T);
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
