#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <list>
#include <memory>
#include <string>
#include <vector>
#include <functional>
#include <climits>
#include <cstring>
#include <cstdio>
using namespace std;

#define PB push_back
#define MP make_pair
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,a,b) for(int i=(a);i<=(b);++i)
#define FORD(i,a,b) for(int i=(a);i>=(b);--i)
#define SIZE(v) (int)(v).size()
#define ALL(v) (v).begin(), (v).end()
typedef long long LL;
#define DBG(x) cout << #x << " = " << x << endl
#define DBGV(v) REP(i, SZ((v))) cout << #v << '[' << i << "] = " << (v)[i] << endl

int a[2510];
int rows[120][60];

vector<int> doit(int N)
{
    memset(a, 0, sizeof(a));
    REP(i, 2 * N - 1) REP(j, N) ++a[rows[i][j]];

    vector<int> res;
    FOR(i, 1, 2500) if (a[i] & 1) res.PB(i);
    sort(ALL(res));
    return res;
}

int main()
{
    int testCount;
    cin >> testCount;
    FOR(zzz, 1, testCount) {
        int N;
        cin >> N;
        REP(i, 2 * N - 1) REP(j, N) cin >> rows[i][j];
        cout << "Case #" << zzz << ":";
        auto v = doit(N);
        REP(i, SIZE(v)) cout << ' ' << v[i];
        cout << '\n';
    }

    return 0;
}
