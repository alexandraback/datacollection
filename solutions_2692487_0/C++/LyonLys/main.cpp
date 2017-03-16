/***************** Written By Lyon, From SCAU, Beta 1.4.0 **************/
/**************** headers && constants && definitions ****************/
#pragma comment(linker, "/STACK:102400000,102400000")

#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <ctime>
#include <stack>
#include <set>
#include <map>

using namespace std;

#define PB push_back
#define FI first
#define SE second
#define MPR make_pair
#define REP(i, n) for (int i = 0; i < (n); i++)
#define REP_1(i, n) for (int i = 1; i <= (n); i++)
#define INC(i, a, b) for (int i = (a); i <= (b); i++)
#define DEC(i, a, b) for (int i = (a); i >= (b); i--)
#define _clr(x) memset(x, 0, sizeof(x))
#define _rst(x) memset(x, -1, sizeof(x))
#define SZ(x) ((int) x.size())
#define PRIQ priority_queue
#define MSET multiset
#define ITOR iterator
#define RITOR reverse_iterator
#define ALL(x) (x).begin(), (x).end()

typedef long long LL;
typedef unsigned long long ULL;
typedef pair<int, int> PII;
typedef pair<LL, int> PLI;
typedef pair<double, double> PDBDB;
typedef pair<double, int> PDBI;
typedef pair<int, double> PIDB;
typedef vector<PIDB> VPIDB;
typedef vector<PDBDB> VPDBDB;
typedef vector<PDBI> VPDBI;
typedef pair<PII, int> PIII;
typedef pair<PII, string> PIIS;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<PII> VPII;
typedef vector<PIII> VPIII;
typedef vector<double> VDBL;
typedef vector<string> VSTR;
typedef vector<VSTR> VVSTR;
typedef vector<VI> VVI;
typedef vector<char> VCH;
typedef vector<VCH> VVCH;
typedef vector<bool> VBL;
typedef long double LDB;

const int N = 5e4;
const int M = 5e5 + 100;
const int LEN = 105;
const int hashMod = 1e6 + 5;
const int inf = 0x55555555;
const double eps = 1e-8;
const LDB leps = 1e-10;
const LL linf = 0x5555555555555555ll;
const double finf = 1e50;
const double pi = acos(-1.0);
const int mod = 1e9 + 7;

template <class T> inline T sqr(T x) {
    return x * x;
}
/*********************************************************************/

int rec[111];

int work(int a, int n) {
    if (a == 1) return n;
    int ret = n, i = 0, add = 0;
    sort(rec, rec + n);
    while (i < n) {
        while (a <= rec[i]) {
            a += a - 1;
            add++;
        }
        a += rec[i];
        ret = min(ret, add + n - i - 1);
        i++;
    }
    return ret;
}

int main() {
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    int T, n, a;
    cin >> T;
    REP_1(cas, T) {
        cin >> a >> n;
        REP(i, n) cin >> rec[i];
        cout << "Case #" << cas << ": " << work(a, n) << endl;
    }
    return 0;
}


