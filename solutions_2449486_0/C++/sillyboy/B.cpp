#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <stack>
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
//#include <conio.h>

using namespace std;

#define X first
#define Y second
#define mp make_pair
#define pb push_back
#define sqr(a) ((a)*(a))
#define FR(i,n) for (int i = 0; i < (n); i++)
#define DN(i,a) for(int i = (a)-1; i >= 0; i--)
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define DOWN(i,a,b) for(int i = (a); i >= (b); i--)
#define FORV(i,a) for(typeof(a.begin()) i = a.begin(); i != a.end(); i++)
#define Set(a,c) memset(a, c, sizeof(a))
#define oo 1000000000
#define maxn 105

typedef pair<int, int> PII;
typedef pair<int, PII> PIII;
typedef vector<int> VI;

int r[maxn], c[maxn];
int a[maxn][maxn], m, n;
vector<PIII> V;

string result() {
    V.clear();
    Set(r, -1);
    Set(c, -1);
    FOR(i, 1, m) FOR(j, 1, n) V.pb(mp(a[i][j], mp(i, j)));
    sort(V.rbegin(), V.rend());
    FR(i, V.size()) {
        PIII P = V[i];
        int d = P.X;
        int x = P.Y.X, y = P.Y.Y;
        if (r[x] == -1) r[x] = d;
        if (c[y] == -1) c[y] = d;
        if (min(r[x], c[y]) > d) return "NO";
    }
    return "YES";
}

int main () {
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        cin >> m >> n;
        FOR(i, 1, m) FOR(j, 1, n) cin >> a[i][j];
        string s = result();
        cout << "Case #" << test << ": " << s << endl;
    }
    return 0;
}
