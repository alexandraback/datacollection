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
#define maxn 1000

typedef pair<int, int> PII;
typedef vector<int> VI;

VI a[30];
int dd[(1<< 21) + 10];
int d[maxn], n;
int type[maxn];

void process() {
    queue<int> Q;
    Set(dd, -1);
    Q.push(1);
    while (!Q.empty()) {
        int P = Q.front();Q.pop();
        Set(d, 0);
        FOR(i, 0, n) if ((P >> i)&1) {
            FR(j, a[i].size()) d[a[i][j]]++;
            d[type[i]]--;
        }
        FOR(i, 1, n) if ((((P>>i)&1) == 0) && d[type[i]]) {
            //cout << i << endl;
            int nP = P + (1 << i);
            if (dd[nP] == -1) {
                dd[nP] = i;
                Q.push(nP);
            }
        }
    }
    int final = (1 << (n + 1)) - 1;
    if (dd[final] == -1) cout << "IMPOSSIBLE";
    else {
        VI res;
        while (final != 1) {
            res.pb(dd[final]);
            final -= 1 << dd[final];
        }
        DN(i, res.size()) cout << res[i] << ' ';
    }
    cout << endl;
}

int main () {
    freopen("D.in", "r", stdin);
    freopen("D.out", "w", stdout);
    int ntest;
    cin >> ntest;
    FOR(test, 1, ntest) {
        int K;
        cin >> K >> n;
        FOR(i, 0, n) a[i].clear();
        FOR(i, 1, K) {
            int u;
            cin >> u;
            a[0].pb(u);
        }
        FOR(i, 1, n) {
            int d;
            cin >> type[i] >> d;
            FOR(j, 1, d) {
                int u;
                cin >> u;
                a[i].pb(u);
            }
        }
        cout << "Case #" << test << ": ";
        process();
    }
    return 0;
}
