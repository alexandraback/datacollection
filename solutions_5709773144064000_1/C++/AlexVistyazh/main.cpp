#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <ctime>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <cmath>

using namespace std;

#define getBit(x,i) ((x&(1<<i))>0)

typedef unsigned long long ull;
typedef long double ld;

template <class T> T sqr(T a) {
    return a * a;
}
template <class T> T nextInt() {
    T x = 0, p = 1;
    char c;
    do {
        c = getchar();
    } while (c <= 32);
    if (c == '-') {
        p = -1;
        c = getchar();
    }
    while (c >= '0' && c <= '9') {
        x = x * 10 + c - '0';
        c = getchar();
    }
    return x * p;
}

double nextDouble() {
    double x;
    scanf("%lf", &x);
    return x;
}

void LLtoStr(char * s, long long x) {
    int slen = 0;
    while (x) {
        s[slen++] = (x % 10) + '0';
        x /= 10;
    }
    if (slen == 0)
        s[slen++] = '0';
    reverse(s, s + slen);
    s[slen] = 0;
}

const int INF = int(1e9);
const long long LINF = (long long)(1e18);
const ld EPS = 1e-9;
const ld PI = 3.1415926535897932384626433832795;

void solve() {
    ld answer = LINF;
    ld C = nextDouble();
    ld F = nextDouble();
    ld X = nextDouble();
    ld speed = 2;
    ld wastedTime = 0;
    for (int i=0;i<=100005;i++) {
        answer = min(answer, wastedTime + X/speed);
        ld deltaT = C/speed;
        wastedTime+=deltaT;
        speed+=F;
    }
    printf("%.9f\n",(double)answer);
}

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T = nextInt<int>();
    for (int i=1;i<=T;i++) {
        printf("Case #%d: ",i);
        solve();
    }
    return 0;
}
