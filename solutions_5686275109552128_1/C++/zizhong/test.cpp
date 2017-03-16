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
    int n;
    cin >> n;
    vector<int> num(n);
    for(int i = 0; i < n; i ++) {
        cin >> num[i];
    }
    int maxnum = *max_element(num.begin(), num.end());
    int ret = maxnum;
    for(int i = 1; i <= maxnum; i ++) {
        int tmp = i;
        for(int j = 0; j < n; j ++) {
            if (num[j] > i) {
                tmp += num[j] / i + (num[j] % i > 0) - 1;
            }
        }
        ret = min(ret, tmp);
    }
    cout << "Case #" << ncase << ": " << ret << endl;
}

int main() {
    //ios::sync_with_stdio(false);
    //cout << std::fixed << setprecision(16);
#ifdef _zzz_
    freopen("B-large.in", "r", stdin);
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
