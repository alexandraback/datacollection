#define _CRT_SECURE_NO_WARNINGS
#pragma comment (linker, "/STACK:16777216")
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>
#include <queue>
#include <list>
#include <stack>
#include <string>
#include <fstream>
#include <math.h>
#include <limits>
#include <set>
#include <map>
#include <sstream>
#include <stdio.h>
#include <time.h>
#include <memory.h>
#include <cassert>
#include <complex>
using namespace std;

///////////////// macros and typedefs ///////////////////
#define rep(i, n) for (int i = 0, _n = (n); i < _n; ++i)
#define repd(i, n) for (int i = (n)-1; i >= 0; --i)
#define _fill(a, x) memset((a), (x), sizeof((a)))
#define DEB(k) cerr<<"debug: "#k<<"="<<k<<endl;
#define all(c) (c).begin(), (c).end()
#define mp(a, b) make_pair(a, b)
#define l(c) (int)((c).size())
#define sqr(a) ((a)*(a))
#define inf 0x7f7f7f7f
#define pb push_back
#define ppb pop_back
#define x first
#define y second
typedef long long ll;
typedef vector<int> vi;
typedef vector<double> vd;
typedef pair<int,int> pi;

//#define PROBLEM_NAME "my"
#define PROBLEM_NAME "B-small-attempt0"
#define LIM 500
#define ID LIM+10

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
const char dc[] = {'W', 'S', 'E', 'N'};

int X, Y;
map<pi, string> g;

void init() {
    g.clear();
    g.insert(mp(mp(0, 0), ""));
    queue<int> q;
    q.push(0);
    q.push(0);
    while(!q.empty()) {
        int x = q.front(); q.pop();
        int y = q.front(); q.pop();
        pi pxy = pi(x, y);
        string s = g[pxy];
        int step = l(s)+1;
        rep(i, 4) {
            int x2 = x+dx[i]*step;
            int y2 = y+dy[i]*step;
            pi pxy2 = pi(x2, y2);
            if (x2 >= -LIM && x2 <= LIM && y2 >= -LIM && y2 <= LIM && g.find(pxy2) == g.end()) {
                string s2 = s;
                s2.push_back(dc[i]);
                g.insert(mp(pxy2, s2));
                q.push(x2);
                q.push(y2);
            }
        }
    }
    string s = "";
    int x = 0, y = 0;
    rep(it, 200) {
        if (it % 2 == 0) {
            x -= it+1;
            s.push_back('W');
        } else {
            x += it+1;
            s.push_back('E');
        }
        if (g.find(pi(x, y)) == g.end())
            g.insert(mp(pi(x, y), s));
    }
    s = "";
    x = y = 0;
    rep(it, 200) {
        if (it % 2 == 0) {
            y -= it+1;
            s.push_back('S');
        } else {
            y += it+1;
            s.push_back('N');
        }
        if (g.find(pi(x, y)) == g.end())
            g.insert(mp(pi(x, y), s));
    }
}

void solveCase(int tc) {
    scanf("%d %d\n", &X, &Y);
    printf("Case #%d: %s\n", tc+1, g[pi(X, Y)].c_str());
}

void solution()
{
    int tc;
    scanf("%d\n", &tc);
    init();
//    int err = 0;
//    for (int i = -100; i <= 100; i++)
//        for (int j = -100; j <= 100; j++)
//            if (g.find(pi(i, j)) == g.end()) {
//                err++;
//                cout << i << " " << j << endl;
//            }
//    cout << err << endl;
    rep(i, tc)
        solveCase(i);
}

int main()
{
#ifndef ONLINE_JUDGE
   freopen(PROBLEM_NAME".in", "rt", stdin);
   freopen(PROBLEM_NAME".out", "wt", stdout);
#endif
   solution();
#ifndef ONLINE_JUDGE
   fprintf(stderr, "Time: %.2lf sec\n", (clock()*1./CLOCKS_PER_SEC));
#endif
   return 0;
}
