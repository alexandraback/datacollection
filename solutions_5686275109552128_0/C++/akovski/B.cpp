#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>

using namespace std;

typedef pair<int, int> PP;
typedef long long LL;
#define pb push_back
#define fr first
#define sc second


int p[5000];
int _main() {
    int n; cin >> n;
    memset(p, 0, sizeof(p));
    for (int i = 0; i < n; i ++) {
        cin >> p[i];
    }
    int cnt = 0, res = 10000;
    for (int i = 1000; i >= 1; i --) {
        int tmp = i;
        for (int j = 0; j < n; j ++) tmp += (p[j] - 1) / i;
        res = min(res, tmp);
    }
    cout << res << endl;
    return 0;
}

int main() {
    #ifdef _TEST_
    freopen("input.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    #endif
    int T;
    cin >> T;
    for (int i = 0; i < T; i ++) {
        cout << "Case #" << i + 1 << ": "; _main();
    }

    return 0;
}

