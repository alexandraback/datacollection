#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

#define clr(x) memset((x), 0, sizeof(x))
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define mp make_pair
#define sz size()
#define For(i, st, en)  for(int i=(st); i<=(int)(en); i++)
#define Forn(i, st, en) for(int i=(st); i<=(int)(en); i++)
#define Ford(i, st, en) for(int i=(st); i>=(int)(en); i--)
#define forn(i, n) for(int i=0; i<(int)(n); i++)
#define ford(i, n) for(int i=(n)-1; i>=0; i--)
#define fori(it, x) for (__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)

template <class _T> inline _T sqr(const _T& x) { return x * x; }
template <class _T> inline string tostr(const _T& a) { ostringstream os(""); os << a; return os.str(); }
template <class _T> inline istream& operator << (istream& is, const _T& a) { is.putback(a); return is; }

typedef long double ld;

// Constants
const ld PI = 3.1415926535897932384626433832795;
const ld EPS = 1e-11;

// Types
typedef signed   long long i64;
typedef unsigned long long u64;
typedef set < int > SI;
typedef vector < ld > VD;
typedef vector < int > VI;
typedef vector < bool > VB;
typedef vector < string > VS;
typedef map < string, int > MSI;
typedef pair < int, int > PII;

#define debug(...)
//#define debug printf

#define MAX 1001

int N;
int a[MAX], b[MAX];
int status[MAX];
int star;
int times;

bool go2() {
    bool go = false;
    for (int i = 0; i < N; ++i) {
        if (status[i] != 2 && star >= b[i]) {
            // go.
            go = true;
            times++;

            if (status[i] == 0) star += 2;
            else star += 1;
            status[i] = 2;

            debug("\n go 2: %d, star: %d", i, star);
        }
    }
    return go;
}

bool go1() {
    int max_star2 = -1;
    int candidate = -1;

    for (int i = 0; i < N; ++i)  {
        if (status[i] == 0 && star >= a[i] && b[i] > max_star2) {
            candidate = i;
            max_star2 = b[i];
        }
    }

    if (candidate != -1) {
        times++;
        star += 1;
        status[candidate] = 1;

        debug("\n go 1: %d, star: %d", candidate, star);

        return true;
    }
    return false;
}

int run() {
    star = 0;
    times = 0;
    fill_n(status, N, 0);

    while (true) {
        if (go2()) continue;
        if (go1()) continue;
        break;
    }

    // check status.
    for (int i = 0; i < N; ++i)
        if (status[i] != 2) return -1;
    return times;
}

int main() {
    //freopen("B-sample.in", "r", stdin);

    int caseN;
    scanf("%d", &caseN);

    for (int cc = 1; cc <= caseN; ++cc) {
        printf("Case #%d: ", cc);

        cin >> N;
        for (int i = 0; i < N; ++i) {
            cin >> a[i] >> b[i];
        }

        int result = run();
        if (result == -1) cout << "Too Bad";
        else cout << result;

        printf("\n");
    }

    return 0;
}

