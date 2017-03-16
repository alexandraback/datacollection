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
typedef pair< pair<int, int> , int > PIII;
typedef long long LL;

const int MOD = 1e9+7;
const int SIZE1 = 1e5+10;
const int SIZE2 = 1e6+10;
const int DX[4] = {-1, 1, 0, 0};
const int DY[4] = {0, 0, 1, -1};

int n;
int a[1111];

vector<int> x;
int result;
void check() {
    if (result > x.size())
        return;
    if (x.size() <= 2) {
        if (x.size() > result) result = x.size();
        return;
    }
    sort(x.begin(), x.end());
    do {
        bool isResult = true;
        for(int i = 1; i <= x.size()-2; ++i) {
            int pos = x[i];
            int prev = x[i-1];
            int next = x[i+1];
            if (a[pos] != prev && a[pos] != next) {
                isResult = false;
                break;
            }
        }
        int pos = x[0];
        int next = x[1];
        int prev = x[x.size()-1];
        if (a[pos] != prev && a[pos] != next) {
            isResult = false;
        }
        pos = x[x.size()-1];
        prev = x[x.size()-2];
        next = x[0];
        if (a[pos] != prev && a[pos] != next) {
            isResult = false;
        }
        if (isResult) {
            if (x.size() > result) result = x.size();
        }

    } while (next_permutation(x.begin(), x.end()));
}

void attempt(int i) {
    if (i > n) {
        check();
        return;
    }
    FOR(j, 0, 1)
        if (j == 1) {
            x.pb(i);
            attempt(i+1);
            x.pop_back();
        } else {
            attempt(i+1);
        }
}

void solution() {
    memset(a, sizeof(a), 0);
    RI(n);
    FOR(i, 1, n)
        RI(a[i]);
    x.clear();
    result = 0;
    attempt(1);
    cout << result << endl;
}

vector<int> e[1111];
int height[1111];
bool visitedCircle[1111];
bool visited[1111];

PIII findCircleLength(int u) {
    visitedCircle[u] = true;
    for(auto v:e[u]) {
        if (!visitedCircle[v]) {
            height[v] = height[u]+1;
            PIII circle = findCircleLength(v);
            if (circle.nd >= 0)
                return circle;
        } else {
            PIII res;
            res.st.st = v;
            res.st.nd = u;
            res.nd = height[u] - height[v] + 1;
            return res;
        }
    }
    return (mp(mp(0, 0), -1));
}

int findPathFrom(int u) {
    visited[u] = true;
    int res = 1;
    for(auto v:e[u]) {
        if (!visited[v]) {
            res = max(res, 1 + findPathFrom(v));
        }
    }
    //cout << "                     " << u << " " << res << endl;
    return res;
}

void large_solution() {
    memset(a, sizeof(a), 0);
    for(int i = 0; i < 1111; ++i)
        e[i].clear();
    RI(n);
    FOR(i, 1, n) {
        RI(a[i]);
        e[a[i]].pb(i);
    }
    //cerr << endl;
    int result = 0;
    int sum2 = 0;
    FOR(u, 1, n) {
        memset(visitedCircle, false, sizeof(visitedCircle));
        memset(height, 0, sizeof(height));

        PIII circle = findCircleLength(u);
        //cerr << u << " " << circle.nd << " " << circle.st.st << " " << circle.st.nd << endl;
        //FOR(i, 1, n)
        //    cerr << "           " << i << " " << height[i] << endl;

        if (circle.nd < 0) continue;
        if (circle.nd > 2) {
            result = max(result, circle.nd);
        } else {
            int p1 = circle.st.st;
            int p2 = circle.st.nd;
            memset(visited, false, sizeof(visited));
            visited[p1] = true;
            visited[p2] = true;
            int l1 = findPathFrom(p1);
            int l2 = findPathFrom(p2);
            //cout << "          " << l1 << "  " << l2 << endl;
            int length = l1+l2;
            sum2 += length;
            result = max(result, length);
        }
    }
    result = max(result, sum2/2);
    cout << result << endl;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int nTest;
    scanf("%d\n", &nTest);
    for(int test = 1; test <= nTest; ++test) {
        printf("Case #%d: ", test);
        large_solution();
    }
    return 0;
}
