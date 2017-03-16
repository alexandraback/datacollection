#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <set>
#include <vector>
#include <map>
#include <cmath>
#include <algorithm>
#include <memory.h>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <cassert>

using namespace std;

typedef long long LL;
typedef pair<int,int> PII;

#define MP make_pair
#define PB push_back
#define FF first
#define SS second

#define FORN(i, n) for (int i = 0; i <  (int)(n); i++)
#define FOR1(i, n) for (int i = 1; i <= (int)(n); i++)
#define FORD(i, n) for (int i = (int)(n) - 1; i >= 0; i--)
#define FOREACH(i, c) for (typeof((c).begin()) i = (c).begin(); i != (c).end(); i++)

#define MOD 1000000007
#define INF 2000000000

int T, n;

const int MAXH = 2510;
int cnt[MAXH];

int main() {
    scanf("%d", &T);

    for (int tc = 1; tc <= T; tc++) {
        printf("Case #%d: ", tc); scanf("%d", &n);

        memset(cnt, 0, sizeof cnt); int s;

        FORN(i, n * (2 * n - 1)) {
            scanf("%d", &s);
            cnt[s]++;
        }

        vector<int> res;
        FORN(i, MAXH) if (cnt[i] % 2 == 1) res.PB(i);

        FORN(i, res.size()) cout << res[i] << " "; cout << endl;
    }
    
    return 0;
}
