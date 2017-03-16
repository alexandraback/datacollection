#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <string.h>
#include <ctime>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;

#define dbg(x) cout << #x << " = " << (x) << endl
#define dbg2(x,y) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << endl
#define dbg3(x,y,z) cout << #x << " = " << (x) << ", " << #y << " = " << (y) << ", " << #z << " = " << (z) << endl

template<class T> inline T cabs(T x) { return x > 0 ? x : (-x); }
template<class T> inline T gcd(T x, T y) { return (y == 0) ? x : gcd(y, x % y); }

#define out(x) cout << (x) << endl
#define out2(x,y) cout << (x) << " " << (y) << endl
#define out3(x,y,z) cout << (x) << " " << (y) << " " << (z) << endl

const int maxN = 10000 + 100;

#define v1 1
#define vi 2
#define vj 3
#define vk 4
#define _v1 (-1)
#define _vi (-2)
#define _vj (-3)
#define _vk (-4)

int L, X, N;
char str[maxN];
int p[maxN], q[maxN];

int run(int x, int y)
{
    int sgn = 1;
    if( x < 0 ) {
        x = - x;
        sgn = - sgn;
    }
    if( y < 0 ) {
        y = - y;
        sgn = - sgn;
    }
    if( x == v1 ) {
        return sgn * y;
    }
    if( x == vi ) {
        if( y == v1 )
            return sgn * vi;
        if( y == vi )
            return sgn * _v1;
        if( y == vj )
            return sgn * vk;
        return sgn * _vj;
    }
    if( x == vj ) {
        if( y == v1 )
            return sgn * vj;
        if( y == vi )
            return sgn * _vk;
        if( y == vj )
            return sgn * _v1;
        return sgn * vi;
    }
    if( y == v1 )
        return sgn * vk;
    if( y == vi )
        return sgn * vj;
    if( y == vj )
        return sgn * _vi;
    return sgn * _v1;
}

int go(int y, int z)
{
    for(int i = 1; i <= 4; i ++) {
        if( run(y, i) == z ) {
            return i;
        }
        if( run(y, -i) == z ) {
            return -i;
        }
    }
    return 1;
}

int gao()
{
    for(int i = 0; i < N; i ++) {
        if( str[i] == 'i' )
            p[i] = vi;
        else if( str[i] == 'j' )
            p[i] = vj;
        else if( str[i] == 'k' )
            p[i] = vk;
    }
    q[0] = p[0];
    for(int i = 1; i < N; i ++)
        q[i] = run(q[i - 1], p[i]);
    int P = vi;
    int Q = run(vi, vj);
    int R = run(run(vi, vj), vk);
    int np = -1;
    for(int i = 0; i < N; i ++) {
        if( q[i] == P ) {
            np = i;
            break;
        }
    }
    int nq = -1;
    for(int i = N - 1; i >= 0; i --) {
        if( q[i] == Q ) {
            nq = i;
            break;
        }
    }
    if( np != -1 && nq != -1 && np < nq && q[N - 1] == R )
        return 1;
    return 0;
}

int main()
{
    freopen("data.in", "r", stdin);
    freopen("data.out", "w", stdout);
    int nt, idx = 0;
    scanf("%d", &nt);
    for(; nt > 0; nt --) {
        scanf("%d %d", &L, &X);
        scanf("%s", str); N = L * X;
        for(int i = 1; i < X; i ++) {
            for(int j = 0; j < L; j ++) {
                str[i * L + j] = str[j];
            }
        }
        str[N] = 0;
        printf("Case #%d: %s\n", ++idx, gao() ? "YES" : "NO");
    }
    return 0;
}
