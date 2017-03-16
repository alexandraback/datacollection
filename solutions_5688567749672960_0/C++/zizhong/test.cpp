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

int inv(int x) {
    if (x == 0) return 0;
    string s = "";
    while(x) {
        s += x % 10 + '0';
        x /= 10;
    }
    return atoi(s.c_str());
}

map<int, int> num2step;
void calc() {
    queue<PII> q;
    q.push(PII(1, 1));
    while(q.size()) {
        PII p = q.front();
        int x = p.first;
        int step = p.second;
        if (x > 1000000) continue;
        //cout << x << " " << step << endl;
        q.pop();
        if (num2step.find(x) != num2step.end() &&
            num2step[x] <= step) {
            continue;
        }
        num2step[x] = step;
        if (num2step.size() == 1000000) continue;
        q.push(PII(x + 1, step + 1));
        q.push(PII(inv(x), step + 1));
    }
}
void solve(int ncase) {
    int n;
    cin >> n;
    int ret = num2step[n];
    cout << "Case #" << ncase << ": " << ret << endl;
}
int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    freopen("A-small-attempt1.in", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int T = 1;
    cin >> T;
    calc();
    int ncase = 0;
    while(T --) {
        solve(++ ncase);
    }
}
