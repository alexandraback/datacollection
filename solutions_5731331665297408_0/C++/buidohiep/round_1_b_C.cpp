#include <vector>
#include <string>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <ctime>
using namespace std;
#define FOR(i,a,b) for(int i=a; i<=b; i++)
#define REP(i,a,b) for(int i=a; i>=b; i--)
#define FORAD(i,u) for(int i=0; i < (int)u.size(),i++)
#define BUG(x) cout << x << endl
#define ll long long
#define fi first
#define sd second
#define pb push_back
#define two(i) 1 << i
#define sz(x) (int)x.size()
#define e 1e-12
#define bit(s,i) ((s >> (i-1)) & 1)
#define Nmax 100100
const double pi = acos(-1);
typedef vector<int> vi ;
typedef pair<int,int> pii ;

int dd[10][10], v[10], n, m, Free[11];
string s[10], res;

bool check(int pos, int x) {
    FOR(i, 1, pos) if (x == v[i]) return false;
    FOR(i, 1, pos) if (dd[v[i]][x] == 1) return true;
    return false;
}


void Try(int pos, int sl, string ss) {
    if (sl == n) {
        if (res == "-1" || res > ss) res = ss;
        return;
    }
    if (pos > 1) Try(pos-1, sl, ss);
    FOR(i, 1, n) if (Free[i] == 0 && (pos == 0 || dd[v[pos]][i])) {
        Free[i] = 1;
        int u = v[pos + 1];
        v[pos + 1] = i;
        Try(pos + 1, sl + 1, ss + s[i]);
        Free[i] = 0;
        v[pos + 1] = u;
    }
}

int main() {
     freopen("C-small-attempt0.in","r",stdin);
     freopen("ans.out","w",stdout);

    int test;
    scanf("%d\n", &test);
    FOR(t, 1, test) {
        scanf("%d%d\n", &n, &m);
        FOR(i, 1, n) getline(cin, s[i]);
        memset(dd, 0, sizeof dd);
        FOR(i, 1, m) {
            int x, y;
            scanf("%d%d\n", &x, &y);
            dd[x][y] = 1;
            dd[y][x] = 1;
        }
        res = "-1";
        memset(Free, 0, sizeof Free);
        Try(0, 0, "");
        cout << "Case #" << t << ": " << res << endl;
    }

     return 0;
}
