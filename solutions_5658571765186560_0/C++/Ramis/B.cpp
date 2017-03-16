#include <iostream>
#include <fstream>
#include <cstring>
#include <set>
#include <map>
#include <list>
#include <queue>
#include <stack>
#include <bitset>
#define _USE_MATH_DEFINES
#include <math.h>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <assert.h>
using namespace std;

void smain();
int main(){
    ios_base::sync_with_stdio(0);
#ifdef TASK
    //freopen(TASK".in","rt",stdin);
    freopen("/Users/ramis/Downloads/D-small-attempt1.in.txt","rt",stdin);
    freopen("output1.txt","wt",stdout);

    const clock_t start = clock();
#endif
    smain();
#ifdef TASK
    cerr << "\nTotal Execution Time: " << float( clock () - start ) /  CLOCKS_PER_SEC << endl;
#endif
    return 0;
}

#define forn(i,n) for (int i=0;i<n;i++)
#define rforn(i,n) for (int i=n-1;i>=0;i--)
#define fori(i,a) for(auto i=a.begin(); i!=a.end(); ++i)
#define rfori(i,a) for(auto i=a.rbegin(); i!=a.rend(); ++i)
#define int long long
#define LL long long
#define mp(a,b) make_pair(a,b)
#define INF 2000000000//2305843009213693951LL
#define MOD 1000000007
#define EPS 1E-9
#define N 3000
/* --------- END TEMPLATE CODE --------- */

typedef pair<int, int> pt;
#define ff first
#define ss second

int x, r, c;
vector<pt> a[10];

bool mtr[4][4];

inline void rotate(int it) {
    if(it < 0) return;
    int mx = 100, my = 100;
    for(auto &jt : a[it]) {
        int i = jt.ff, j = jt.ss;
        jt.ff = -j, jt.ss = i;
        mx = min(jt.ff, mx), my = min(jt.ss, my);
    }
    for(auto &jt : a[it]) {
        jt.ff -= mx, jt.ss -= my;
    }
}

bool can(int idx, vector<vector<int> > &p) {
    if(x == 1) return true;
    if(r > c) swap(r, c);
    if(x == 4 && r == 3 && c == 4) return true;

    bool res = false;
    forn(rot, 4) {
      forn(i, r) forn(j, c) {
        bool ok = true;
        for(auto jt : a[idx]){
            int nx = i + jt.ff, ny = j + jt.ss;
            if(nx >= r || ny >= c || mtr[nx][ny]) ok = false;
        }
        if(!ok) continue;
        for(auto jt : a[idx]){
            int nx = i + jt.ff, ny = j + jt.ss;
            mtr[nx][ny] = 1;
        }
        for(auto it : p[x-1]) {
            if(can(it, p)) {
                res = true;
                break;
            }
        }

        for(auto jt : a[idx]){
            int nx = i + jt.ff, ny = j + jt.ss;
            mtr[nx][ny] = 0;
        }
        if(res) return true;
      }
      rotate(idx);
    }
    forn(i, r) forn(j, c) if(mtr[i][j] == 0) return false;
    return true;
}

void smain() {
    int T;
    cin >> T;
    a[0].emplace_back(0, 0);
    a[0].emplace_back(0, 1);

    a[1].emplace_back(0, 0);
    a[1].emplace_back(0, 1);
    a[1].emplace_back(0, 2);
    a[2].emplace_back(0, 0);
    a[2].emplace_back(0, 1);
    a[2].emplace_back(1, 0);
    
    
    a[3].emplace_back(0, 0);
    a[3].emplace_back(0, 1);
    a[3].emplace_back(0, 2);
    a[3].emplace_back(0, 3); 
    a[4].emplace_back(0, 0);
    a[4].emplace_back(0, 1);
    a[4].emplace_back(1, 0);
    a[4].emplace_back(1, 1);
    a[5].emplace_back(0, 0);
    a[5].emplace_back(0, 1);
    a[5].emplace_back(1, 0);
    a[5].emplace_back(2, 0);
    a[6].emplace_back(0, 0);
    a[6].emplace_back(0, 1);
    a[6].emplace_back(0, 2);
    a[6].emplace_back(1, 1);
    a[7].emplace_back(0, 0);
    a[7].emplace_back(1, 0);
    a[7].emplace_back(1, 1);
    a[7].emplace_back(2, 1);


    vector<vector<int> > p(4, vector<int>());
    p[0].push_back(-1);
    p[1].push_back(0);
    p[2].push_back(1);
    p[2].push_back(2);

    p[3].push_back(3);
    p[3].push_back(4);
    p[3].push_back(5);
    p[3].push_back(6);
    p[3].push_back(7);

    //for(x=2; x < 5; ++x) for(r=1; r < 5; ++r) for(c=1; c < 5; ++c) { int t = x + r + c;
    for(int t=1; cin >> x >> r >> c; ++t) {
        bool ok = false;
        if(r * c % x) ok = true;
        else for(auto it : p[x-1]){
            memset(mtr, 0, sizeof(mtr));
            if(!can(it, p)) ok = true;//, cout << it << endl;
        }
       
        //cout << x << r << c << endl;
        cout << "Case #" << t << ": " << (!ok ? "GABRIEL" : "RICHARD") << endl;
    }
}
