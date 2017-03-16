#include <iostream>
#include <sstream>
#include <algorithm>
#include <iterator>
#include <numeric>

#include <cstdio>
#include <cmath>
#include <cctype>
#include <cstring>

#include <string>
#include <vector>
#include <deque>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>

using namespace std;

#define FOREACH(iter, cont) for(__typeof((cont).begin()) iter = (cont).begin(); iter != (cont).end(); iter++)
#define REP(i, end) for(int i = 0; i < (end); i++)
#define CLEAR(arr) memset(arr, 0, sizeof(arr))
#define ALL(cont) (cont).begin(),(cont).end()

const int maxn = 100;
int h[maxn][maxn];
int n, m;

int main() {
    int cases;
    cin >> cases;
    for (int cs = 1; cs <= cases; cs++) {
        cin >> n >> m;
        REP(i, n) REP(j, m)
            cin >> h[i][j];

        bool res = true;
        REP(i, n) REP(j, m) {
            bool ok1 = true;
            REP(k, m)
                ok1 = ok1 && (h[i][k] <= h[i][j]);

            bool ok2 = true;
            REP(k, n)
                ok2 = ok2 && (h[k][j] <= h[i][j]);

            res = res && (ok1 || ok2);
        }

	cout << "Case #" << cs << ": " << (res ? "YES" : "NO") << endl;
    }
}
