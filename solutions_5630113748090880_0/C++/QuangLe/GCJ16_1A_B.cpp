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
#define DEBUGARR(a,n) {cout << #a << " = " ; REP(_,0,n) cout << a[_] << ' '; cout <<endl;}
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
template <typename T> string NumberToString ( T Number ) { stringstream ss; ss << Number; return ss.str();}
int StringToNumber ( const string &Text ) { stringstream ss(Text); int result; return ss >> result ? result : 0; }


typedef pair< int, int > PII;
typedef long long LL;

const int MOD = 1e9+7;
const int SIZE1 = 1e5+10;
const int SIZE2 = 1e6+10;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

int n;
vector<vector<int>> a;
int cnt[3000];

bool mycmp(vector<int>&a, vector<int>&b) {
    for(int i = 0; i < a.size(); ++i)
        if (a[i] < b[i])
            return true;
    return false;
}

void solution() {
    //sort(a.begin(), a.end());
    for(int i = 0; i < 3000; ++i)
        cnt[i] = 0;
    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < a[i].size(); ++j) {
            cnt[a[i][j]]++;
        }
    vector<int> res;
    res.clear();

    for(int i = 0; i < a.size(); ++i)
        for(int j = 0; j < a[i].size(); ++j)
            if (cnt[a[i][j]] % 2 == 1) {
                res.pb(a[i][j]);
                cnt[a[i][j]]++;
            }
    sort(res.begin(), res.end());
    for(int i = 0; i < res.size(); ++i)
        cout << res[i] << " ";
    cout << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nTest;
    scanf("%d\n", &nTest);
    for(int test = 1; test <= nTest; ++test) {
        printf("Case #%d: ", test);
        a.clear();
        RI(n);
        FOR(i, 1, 2*n-1) {
            vector<int> row;
            FOR(j, 1, n) {
                DRI(x);
                row.pb(x);
            }
            a.pb(row);
        }
        solution();
    }
    return 0;
}
