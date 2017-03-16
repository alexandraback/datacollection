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

const int max_n = 10000000;

int t;
int cache[max_n];

void solve() {
    LL n;
    cin >> n;
    cout << "Case #" << ++t << ": " << cache[n] << endl;
}

int main() {
    freopen("out.txt", "w", stdout);
    memset(cache, -1, sizeof(cache));
    cache[1] = 1;
    for (LL i = 2; i < max_n; ++i) {
        cache[i] = cache[i - 1] + 1;
        if (i % 10 == 0)
            continue;
        int m;
        char buffer[32];
        sprintf(buffer, "%I64d", i);
        reverse(buffer, buffer + strlen(buffer));
        sscanf(buffer, "%I64d", &m);
        if (m < i)
            cache[i] = min(cache[i], cache[m] + 1);
    }
    int t;
    scanf("%d", &t);
    for (int i = 0; i < t; ++i)
        solve();
    return 0;
}
