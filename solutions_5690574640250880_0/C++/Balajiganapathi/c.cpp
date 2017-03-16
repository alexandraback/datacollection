//Coder: Balajiganapathi
//#define TRACE
#define DEBUG

#include <algorithm>
#include <bitset>
#include <deque>
#include <cassert>
#include <cctype>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <utility>
#include <vector>

using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef vector<string> vs;

// Basic macros
#define st          first
#define se          second
#define all(x)      (x).begin(), (x).end()
#define ini(a, v)   memset(a, v, sizeof(a))
#define re(i,s,n)  	for(int i=s;i<(n);++i)
#define rep(i,s,n)  for(int i=s;i<=(n);++i)
#define fr(i,n)     re(i,0,n)
#define repv(i,f,t) for(int i = f; i >= t; --i)
#define rev(i,f,t)  repv(i,f - 1,t)
#define frv(i,n)    rev(i,n,0)
#define pu          push_back
#define mp          make_pair
#define sz(x)       (int)(x.size())

const int oo = 2000000009;
const double eps = 1e-9;

#ifdef TRACE
    #define trace1(x)                cerr << #x << ": " << x << endl;
    #define trace2(x, y)             cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
    #define trace3(x, y, z)          cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;
    #define trace4(a, b, c, d)       cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << endl;
    #define trace5(a, b, c, d, e)    cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << endl;
    #define trace6(a, b, c, d, e, f) cerr << #a << ": " << a << " | " << #b << ": " << b << " | " << #c << ": " << c << " | " << #d << ": " << d << " | " << #e << ": " << e << " | " << #f << ": " << f << endl;

#else

    #define trace1(x)
    #define trace2(x, y)
    #define trace3(x, y, z)
    #define trace4(a, b, c, d)
    #define trace5(a, b, c, d, e)
    #define trace6(a, b, c, d, e, f)

#endif

const int mx = 55;
char ans[mx][mx];
int R, C, M;
vector<pi> cells[mx];
char tmp[mx][mx];

bool correct();

bool fill(int ci, int cj) {
    fr(i, mx) cells[i].clear();
    for(int i = R - 1; i >= 0; --i) for(int j = C - 1; j >= 0; --j) {
        int d = max(abs(i - ci), abs(j - cj));
        cells[d].pu(mp(i, j));
        ans[i][j] = '.';
    }
    ans[ci][cj] = 'c';

    int idx, dist;
    dist = max(R, C); idx = 0;
    int m = M;

    while(m > 0) {
        if(idx == sz(cells[dist])) {
            idx = 0;
            --dist;
            assert(dist >= 0);
            continue;
        }
        ans[cells[dist][idx].st][cells[dist][idx].se] = '*';
        --m;
        ++idx;
    }
    assert(ans[ci][cj] == 'c');
    //fr(i, sz(cells[1])) if(ans[cells[1][i].st][cells[1][i].se] == '*') return false;
    //return true;
    return correct();
}

void transpose() {
    swap(R, C);
    fr(i, R) fr(j, C) tmp[i][j] = ans[j][i];
    fr(i, R) fr(j, C) ans[i][j] = tmp[i][j];
}

int cnt, vis[mx][mx];

bool valid(int i, int j) {
    if(i < 0 || i >= R || j < 0 || j >= C) return false;
    return true;
}

bool not_zero(int i, int j) {
    if(tmp[i][j] == '*') return true;
    for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) {
        int ni = i + di, nj = j + dj;
        if(valid(ni, nj) && tmp[ni][nj] == '*') return true;
    }

    return false;
}

void dfs(int i, int j) {
    if(!valid(i, j)) return;
    if(vis[i][j]) return;
    vis[i][j] = 1;
    //trace3(i, j, not_zero(i, j));
    assert(tmp[i][j] != '*');
    ++cnt;
    if(not_zero(i, j)) return;


    for(int di = -1; di <= 1; ++di) for(int dj = -1; dj <= 1; ++dj) dfs(i + di, j + dj);
}

bool correct() {
    fr(i, R) fr(j, C) tmp[i][j] = ans[i][j];

    ini(vis, 0);
    cnt = 0;
    fr(i, R) fr(j, C) if(tmp[i][j] == 'c') dfs(i, j);
    trace1(cnt);

    return R * C - cnt == M;
}

bool possible(int i, int cur, int nxt) {
    if(cur < nxt) return false;
    if(i == 0) return true;
    if(i == 1 && nxt > 1 && cur == nxt) return true;
    if(i == 1) return false;
    if(nxt > 1) return true;
    if(nxt == C) return true;

    return false;
}

bool possible1(int i, int cur, int nxt) {
    if(cur < nxt) return false;
    if(R == 1) return true;
    if(i == 0) return nxt == 1;
    return possible(i, cur, nxt);
        
}

void print() {
    fr(i, R) {
        ans[i][C] = 0;
        printf("%s\n", ans[i]);
    }
}

int dp[mx][mx][mx * mx];

int solve(int i, int c, int s) {
    if(s < 0) return 0;
    if(s == 0) return i == R;
    if(i >= R) return 0;
    
    int &ret = dp[i][c][s];
    if(ret != -1) return ret;
    if(s == 0) return ret = 1;
    ret = 0;

    trace4("N", i, c, s);
    if(possible1(i, c, s)) {
        fr(j, s) ans[i][j] = '.';
        trace4("S", i, c, s);
        //print();
        return ret = 1;
    }

    for(int nxt = 1; nxt <= c; ++nxt) {
        if(possible(i, c, nxt) && solve(i + 1, nxt, s - nxt)) {
            trace4(i, c, s, nxt);
            fr(j, nxt) ans[i][j] = '.';
            //print();
            return ret = 1;
        }
    }

    return ret;
}

int main() {
    //freopen("sample.txt", "r", stdin);
    //freopen("time.txt", "r", stdin);
    freopen("C-small-attempt8.in", "r", stdin);
    //freopen("C-large.in", "r", stdin);

    //freopen("output.txt", "w", stdout);
    freopen("small8.txt", "w", stdout);
    //freopen("large.txt", "w", stdout);
    
    int kases, kase;
    scanf("%d", &kases);
    for(kase = 1; kase <= kases; ++kase) {
        printf("Case #%d:\n", kase);
        cerr << "Case #" << kase << endl;
        cin >> R >> C >> M;
        trace3(R, C, M);
        
        bool done = false;
        fr(i, R) ans[i][C] = 0;
        fr(i, R) fr(j, C) ans[i][j] = '*';

        ini(dp, -1);
        if(solve(0, C, R * C - M)) {
            done = true;
            ans[0][0] = 'c';
            print();
        }

        if(!done) {
            swap(R, C);
            fr(i, R) fr(j, C) ans[i][j] = '*';
            ini(dp, -1);
            if(solve(0, C, R * C - M)) {
                done = true;
                transpose();
                ans[0][0] = 'c';
                print();
            }
        }
        if(done) assert(correct());

        if(!done) printf("Impossible\n");
    }
    
	return 0;
}
