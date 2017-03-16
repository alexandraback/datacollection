#include <iostream>
#include <sstream>

#include <vector>
#include <set>
#include <bitset>
#include <map>
#include <string>

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <ctime>

#include <algorithm>
#include <numeric>

#define foreach(i, x) for (__typeof((x).begin()) i = (x).begin(); i != (x).end(); ++i)
#define sqr(x) ((x) * (x))
#define len(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define pbk pop_back
#define mp make_pair
#define fs first
#define sc second
#define endl '\n'
#ifdef CUTEBMAING
#include "cutedebug.h"
#else
#define debug(x) ({})
#endif

using namespace std;

typedef long long int64;
typedef unsigned long long lint;
typedef long double ld;

const int inf = ((1 << 30) - 1);
const int64 linf = ((1ll << 62) - 1);

const char* fin = "input.txt";
const char* fout = "output.txt";

int64 n, x, y;

bool u[30000][10000];
int ans1 = 0, ans2 = 0;

void totalmake(int x);
void make(int x, int y, int p);

void make(int x, int y, int p){
    if (y == 0 || ((y < 2 || u[x][y - 2]) && u[x - 1][y - 1] && u[x + 1][y - 1])){
        u[x][y] = true;
        totalmake(p);
        u[x][y] = false;
        return ;
    }
    if (y >= 2 && !u[x][y - 2])
        return void (make(x, y - 2, p));
    if (!u[x - 1][y - 1])
        make(x - 1, y - 1, p);
    if (!u[x + 1][y - 1])
        make(x + 1, y - 1, p);
}

void totalmake(int p){
    if (p == n){
        ++ans2;
        if (u[x + 10000][y])
            ++ans1;
        return ;
    }
    make(10000, 1000, p + 1);
}

inline ld stupid(){
    memset(u, 0, sizeof(u));
    ans1 = ans2 = 0;
    totalmake(0);
    return 1.0 * ans1 / ans2;
}

ld cnk(int n, int k){
    if (k < 0 || k > n)
        return 0;
    if (k == 0 || k == n)
        return 1;
    return cnk(n - 1, k - 1) * n / k;
}

void run(){
    cout.precision(20);
    cin >> n >> x >> y;
    x = abs(x), y = abs(y);
    int64 size = 1;
    int64 sn = n;
    for (; (size + 1) * size / 2 < n; size += 2);
    if ((size + 1) * size / 2 > n)
        size -= 2;
    if (abs(x) + abs(y) <= size - (size & 1)){
        cout << fixed << 1.0 << endl;
        n = sn;
        assert(abs(stupid() - 1) < 1e-12);
        return ;
    }
    n -= (size + 1) * size / 2;
    size += 2;
    if (abs(x) + abs(y) > size - (size & 1)){
        cout << fixed << 0.0 << endl;
        n = sn;
        assert(abs(stupid()) < 1e-12);
        return ;
    }
    int64 cnt = size - abs(x);
    ld ans = 0, dv = 0;
    for (int64 i = 0; i <= n; i++)
        if (i < size && n - i < size)
            dv += cnk(n, i);
    for (int64 i = cnt; i <= n; i++)
        if (i < size && n - i < size)
            ans += cnk(n, i);
    n = sn;
    ld r1 = stupid();
    debug(mp(ans, dv));
    debug(mp(ans / dv, r1));
    ans = ans / dv;
    assert(abs(ans - r1) < 1e-9);
    cout << fixed << ans + 1e-12 << endl;
}

int main(){
    #if !defined STRESS && defined CUTEBMAING
    assert(freopen(fin, "r", stdin));
    assert(freopen(fout, "w", stdout));
    #endif
    int t; cin >> t;
    for (int i = 0; i < t; i++){
        cout << "Case #" << i + 1 << ": ";
        run();
        debug(mp("Test", i + 1));
    }
    return 0;
}
