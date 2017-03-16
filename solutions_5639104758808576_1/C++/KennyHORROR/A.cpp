#ifdef DEBUG
//#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <string>
#include <cstring>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <ctime>
#include <cassert>
#include <functional>
#include <complex>

using namespace std;
typedef long double LD;
typedef long long LL;


char str[10005];

void Solve() {
    int q;
    cin >> q >> str;
    int ret = 0;
    int sum = 0;
    for (int i = 0; i < q + 1; ++i) {
        if (sum < i) {
            ++ret;
            ++sum;
        }
        sum += str[i] - '0';
    }
    printf("%d\n", ret);
}

int main() {
    freopen("a.in", "r", stdin);
    freopen("a.out", "w", stdout);
    int T;
    cin >> T;
    for (int i = 0; i < T; ++i) {
        printf("Case #%d: ", i + 1);
        Solve();
    }
    return 0;
}
