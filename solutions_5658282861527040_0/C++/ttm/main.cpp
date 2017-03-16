#include <vector>
#include <list>
#include <map>
#include <set>
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

using namespace std;

typedef long long iint;

int main() {
    freopen("in", "r", stdin);
    freopen("out", "w", stdout);
    int cases; cin >> cases;
    for (int cas = 1; cas <= cases; ++cas) {
        cout << "Case #" << cas << ": ";
        iint a, b, k; cin >> a >> b >> k;
        iint n = 0;
        for (iint i = 0; i < a; ++i) {
            for (iint j = 0; j < b; ++j) {
                if ((i & j) < k) n++;
            }
        }
        cout << n << endl;
    }
}
