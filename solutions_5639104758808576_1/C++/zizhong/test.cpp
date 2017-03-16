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
    int smax;
    cin >> smax;
    string s;
    cin >> s;
    int ret = 0;
    int sum = 0;
    for(int i = 0; i <= smax; i ++) {
        if (sum < i) {
            ret += i - sum;
            sum = i;
        }
        sum += s[i] - '0';
    }
    cout << "Case #" << ncase << ": " << ret << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    freopen("A-large.in", "r", stdin);
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
