/******************************************************************************\
*                         Author:  Dumbear                                     *
*                         Email:   dumbear[#at]163.com                         *
*                         Website: http://dumbear.com                          *
\******************************************************************************/
#include <algorithm>
#include <bitset>
#include <cctype>
#include <climits>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <typeinfo>
#include <utility>
#include <vector>

using namespace std;

#define output(x) cout << #x << ": " << (x) << endl;

typedef long long LL;
typedef vector<int> VI;
typedef vector<long long> VL;
typedef vector<double> VD;
typedef vector<string> VS;

const int max_m = 1000 + 10;

int t, m;
char shyness[max_m];

int get_min_friends() {
    int res = 0, cnt = 0;
    for (int i = 0; i <= m; ++i) {
        if (shyness[i] == '0')
            continue;
        if (cnt < i) {
            res += i - cnt;
            cnt = i;
        }
        cnt += shyness[i] - '0';
    }
    return res;
}

void solve() {
    scanf("%d%s", &m, shyness);
    printf("Case #%d: %d\n", ++t, get_min_friends());
}

int main() {
    freopen("out.txt", "w", stdout);
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
