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

const int MAXN = 10000 + 100;

const int q[5][5] = {
                        {0, 0, 0, 0, 0},
                        {0, 1, 2, 3, 4},
                        {0, 2, -1, 4, -3},
                        {0, 3, -4, -1, 2},
                        {0, 4, 3, -2, -1}
                    };

int a[5][5];
map<char, int> m;
//1 = 1
//i = 2
//j = 3
//k = 4
LL l, x, n;
string s, ss;
vector<int> pi, pk;
//int f[MAXN][MAXN];
int f[MAXN * 5];

int multiple(int x, int y) {
    if (x < 0) return -multiple(-x, y);
    if (y < 0) return -multiple(x, -y);
    return q[x][y];
}

int power(LL n, LL k) {
    if (k == 1) return n;
    int tmp = power(n, k/2);
    tmp = multiple(tmp, tmp);
    if (k % 2 == 0)
        return tmp;
    else
        return multiple(tmp, n);
}

int main() {
    freopen("input2.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nTest;
    RI(nTest);
    m['i'] = 2;
    m['j'] = 3;
    m['k'] = 4;
    FOR(test, 1, nTest) {
        scanf("%d %d\n", &l, &x);
        LL n = min(l*5, l*x-1);
        getline(cin, s);
        memset(f, 0, sizeof(f));
        f[0] = m[s[0]];
        FOR(i, 1, n)
            f[i] = multiple(f[i-1], m[s[i%l]]);
        bool res = false;
        int posI = -1;
        int posK = -1;
        FOR(i, 0, n)
            if (f[i] == 2) {
                posI = i;
                break;
            }
        FOR(k, posI + 1, n)
            if (f[k] == 4) {
                posK = k;
                break;
            }
        int fAll = power(f[l-1], x);
        if (posI >= 0 && posK >= 0 && posI < posK && fAll == -1) res = true;
        printf("Case #%d: ", test);
        if (res) printf("YES\n");
        else printf("NO\n");
    }
    return 0;

}


    //Khao sat
        /*ss = "";
        FOR(i, 1, x)
            ss = ss + s;
        FOR(i, 0, n) {
            f[i][i] = m[ss[i]];
            FOR(j, i+1, n)
                f[i][j] = multiple(f[i][j-1], m[ss[j]]);
        }
        FOR(i, 0, n) {
            cout << i << "     ";
            FOR(j, 0, n)
                cout << f[i][j] << " ";
            cout << endl;
        }
        bool res = false;
        bool res2 = false;
        FOR(i, 0, n)
            if (f[i][n] == 4) {
                res2 = true;
                break;
            }
        if (!res2) {
            res = false;
        } else {
            FOR(i, 0, n)
                if (f[0][i] == 2) {
                    if (res) break;
                    FOR(j, i+1, n)
                        if (f[i+1][j] == 3 && f[j+1][n] == 4) {
                            res = true;
                            break;
                        }
                }
        }*/
