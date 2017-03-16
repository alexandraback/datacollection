#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <cstring>
#include <conio.h>

using namespace std;

#define oo 1000000000
#define X first
#define Y second
#define sqr(a) ((a)*(a))
#define FR(i,n) for (int i = 0; i < (n); i++)
#define DN(i,a) for(int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define MAXN 25
#define pb push_back

typedef pair<int, int> PII;
typedef vector<int> VI;

vector <PII> res;
int a[MAXN], n;

void process() {
    int maxsl = 1 << n - 1;
    res.clear();
    FOR(i, 1, maxsl) {
        int s = 0;
        FOR(j, 1, n) if (i & (1 << (j - 1))) s += a[j];
        res.pb(PII(s, i));
    }
    sort(res.begin(), res.end());
    int li, lj;
    li = -1;
    FOR(i, 1, res.size() - 1) {
        if (res[i].X == res[i - 1].X) {
            li = res[i - 1].Y;
            lj = res[i].Y;
            break;
        }
    }
    if (li == -1) {
        cout << "Impossible" << endl;
        return;
    }
    li = li & (~lj);
    lj = lj & (~li);
    FOR(i, 1, n)
        if (li & (1 << (i - 1))) cout << a[i] << ' ';
    cout << endl;
    FOR(i, 1, n)
        if (lj & (1 << (i - 1))) cout << a[i] << ' ';
    cout << endl;

}

int main () {
    freopen("C-small-attempt0.in", "r", stdin);
    freopen("C.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> n;
        FOR(i, 1, n) cin >> a[i];
        printf("Case #%d:\n", test);
        process();
    }
    return 0;
}
