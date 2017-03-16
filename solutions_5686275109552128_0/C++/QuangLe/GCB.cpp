/*
ID: iamquan2
PROG: test
LANG: C++
*/

// Author: QCC
#include <bits/stdc++.h>

using namespace std;

//Loop
#define FOR(i,a,b) for( int i=(a),_b=(b);i<=_b;i++)
#define REP(i,a,b) for( int i=(a),_b=(b);i<_b;++i)
#define DOW(i,b,a) for( int i=(b),_a=(a);i>=_a;i--)
#define FOREACH(it,c) for (__typeof((c).begin()) it=(c).begin(); it!=(c).end(); it++)
//Debugging
#define DEBUG(x) { cout << #x << " = " << x << endl; }
#define DEBUGARR(a,n) {cout << #a << " = " ; FOR(_,1,n) cout << a[_] << ' '; cout <<endl;}
#define CHECK printf("OK\n");
//Read and init
#define RI(X) scanf("%d", &(X))
#define RII(X, Y) scanf("%d%d", &(X), &(Y))
#define RIII(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define DRI(X) int (X); scanf("%d", &X)
#define DRII(X, Y) int X, Y; scanf("%d%d", &X, &Y)
#define DRIII(X, Y, Z) int X, Y, Z; scanf("%d%d%d", &X, &Y, &Z)
#define RC(X) scanf("%c", &(X))
#define DRC(X) char (X); scanf("%c", &X)
#define FILL(a, b) memset((a), (b), sizeof((a)))
//Shorten keyword
#define pb push_back
#define mp make_pair
#define st first
#define nd second

int gcd(int a, int b) { int r; while (b != 0) { r = a % b; a = b; b = r; } return a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
int getBit(int s, int i) { return (s >> i) & 1; }
int onBit(int s, int i) { return s | (int(1) << i); }
int offBit(int s, int i) { return s & (~(int(1) << i)); }
int cntBit(int s) { return __builtin_popcount(s); }
int sqr(int x) {return x*x; };


typedef pair< int, int > PII;
typedef long long LL;

const int MOD = 1e9+7;
const int SIZE = 1e6+10;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

const int MAXD = 1000;
int d;
int p[MAXD*100];
int cnt[MAXD*100];

int cal(int k) {
    int res = 0;
    DOW(i, MAXD, k+1) {
        /*if (cnt[i] == 0) continue;
        res += cnt[i];
        if (i%2 == 0) cnt[i/2] += 2*cnt[i];
        else {
            cnt[i/2] += cnt[i];
            cnt[i/2 + 1] += cnt[i];
        }*/
        res += cnt[i] * (i/k);
        if (i%k == 0) res -= cnt[i];
    }
    return res;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    //init F array
    int nTest;
    RI(nTest);
    FOR(test, 1, nTest) {
        memset(cnt, 0, sizeof(cnt));
        RI(d);
        FOR(i, 1, d) {
            RI(p[i]);
            cnt[p[i]]++;
        }
        int res = MAXD + 1000;
        FOR(time, 1, MAXD)
            res = min(res, time + cal(time));
        printf("Case #%d: %d\n", test, res);
    }
    return 0;
}
