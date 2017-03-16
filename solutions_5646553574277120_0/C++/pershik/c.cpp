#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <ctime>
#include <cassert>
#include <memory.h>

#include <iostream>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <list>

#define NAME "test-small"

#define EPS (1e-9)
#define INF ((int)(1e+9))
#define LINF ((long long)(1e+18))

#define ve vector<int>
#define pb push_back

#define pii pair<int, int>
#define mp make_pair
#define fi first
#define se second
#define fs first
#define sc second

using namespace std;

typedef long long li;
typedef long long ll;
typedef long long lint;

void solve(int test_number);

int main() {
#ifdef _GEANY
    freopen(NAME ".in", "r", stdin);
    freopen(NAME ".out", "w", stdout);
#else
#endif
    cout.setf(ios::fixed);
    cout.precision(9);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; i++) {
        solve(i + 1);
    }
    return 0;
}

const int MAXN = 1010;

li cnt, n, m;
li a[MAXN];

void solve(int test_number) {
    cerr << test_number << endl;
    cin >> cnt >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int res = 0;
    while (true) {
        li need = 1;
        //for (int i = 0; i < n; i++)
            //cerr << a[i] << ' ';
        //cerr << endl;
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (a[i] <= need) {
                need = need + cnt * a[i];
                if (need > m) {
                    cout << "Case #" << test_number << ": " << res << endl;
                    return;
                }
            } else {
                flag = true;
                a[n++] = need;
                sort(a, a + n);
                res++;
                break;
            }
        }
        if (!flag) {
            a[n++] = need;
            sort(a, a + n);
            res++;
        }
    }
}

