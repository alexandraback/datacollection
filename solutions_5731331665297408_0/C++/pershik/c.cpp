#include <iostream>
#include <stdio.h>
#include <string>
#include <string.h>
#include <math.h>
#include <vector>
#include <stdlib.h>
#include <stack>
#include <map>
#include <set>
#include <algorithm>
#include <cassert>
#include <ctime>
#include <queue>
#include <deque>
#include <memory.h>
#include <complex>
#include <numeric>

#define mp make_pair
#define pb push_back
#define fi first
#define se second

#define INF (1000000000)
#define LINF (1000000000000000000ll)
#define EPS (1e-9)

#define MOD 1000000007

#define NAME "test"
#ifndef NAME
    #error Write problem name!
#endif

using namespace std;

typedef long long li;
typedef unsigned long long uli;

li gcd(li x, li y){
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

li lcm(li x, li y){
    return x / gcd(x, y) * y;
}

li binpow(li a, li p){
    if (!p)
        return 1;
    li g = binpow(a, p >> 1);
    if (p % 2 == 0)
        return (g * g) % MOD;
    else
        return (((g * g) % MOD) * a) % MOD;
}

li rev(li n){
    return binpow(n, (li)MOD - 2LL);
}

void solve(int test_number);

int main() {
#ifdef _GEANY
    assert(freopen(NAME ".in", "r", stdin));
    assert(freopen(NAME ".out", "w", stdout));
#endif
    cout.setf(ios::fixed);
    cout.precision(20);
    cerr.setf(ios::fixed);
    cerr.precision(3);
    int n = 1;
    cin >> n;
    for (int i = 0; i < n; ++i)
        solve(i + 1);
}

int n, m;
vector<int> g[100];
string s[100];
string x[100];
int ind[100];
bool used[100];
priority_queue<pair<int, pair<int, int> > > q;
bool good[100];
bool used2[100];
vector<int> res;
vector<int> st;
int a[100][100];

bool cmp(int a, int b) {
    return ind[a] < ind[b];
}

void init() {
    for (int i = 0; i < 100; i++)
        g[i].clear();
    while (!q.empty())
        q.pop();
    memset(used, 0, sizeof(used));
    memset(good, 0, sizeof(good));
    res.clear();
    memset(a, 0, sizeof(a));
    st.clear();
}

void dfs2(int v) {
    used2[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++) {
        int to = g[v][i];
        if (!used[to] && !used2[to])
            dfs2(to);
    }
}

void dfs(int start) {
    st.push_back(start);
    for (int i = 0; i < n; i++) {
        if (st.size() == 0)
            return;
        int v = st[st.size() - 1];
        //cout << v << endl;
        //cout << "Stack: ";
        //for (int j = 0; j < (int)st.size(); j++)
            //cout << st[j] << ' ';
        //cout << endl;
        res.push_back(v);
        used[v] = true;
        for (int i = 0; i < (int)g[v].size(); i++) {
            int to = g[v][i];
            if (!used[to])
                good[to] = true;
        }
        vector<int> tos;
        for (int i = 0; i < n; i++)
            if (good[i] && !used[i])
                tos.push_back(i);
        
        sort(tos.begin(), tos.end(), cmp);
        for (int i = 0; i < (int)tos.size(); i++) {
            int from = -1, pos = -1;
            for (int j = (int)st.size() - 1; j >= 0; j--) {
                if (a[st[j]][tos[i]]) {
                    from = st[j];
                    pos = j;
                    break;
                }
            }
            memset(used2, 0, sizeof(used2));
            for (int j = 0; j <= pos; j++)
                dfs2(st[j]);

            bool flag = false;
            for (int j = 0; j < n; j++)
                if (!used[j] && !used2[j]) {
                    flag = true;
                    break;
                }
            if (flag) {
                continue;
            }
            
            while (st[st.size() - 1] != from)
                st.pop_back();
            st.push_back(tos[i]);
            memset(good, 0, sizeof(good));
            for (int j = 0; j < (int)st.size(); j++) {
                int v = st[j];
                for (int k = 0; k < (int)g[v].size(); k++) {
                    int to = g[v][k];
                    if (!used[to])
                        good[to] = true;
                }
            }
            break;
        }
    }
}

void solve(int test_number) {
    init();
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> s[i];
        x[i] = s[i];
    }
    sort(x, x + n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (s[i] == x[j])
                ind[i] = j;
    for (int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        u--, v--;
        a[u][v] = a[v][u] = 1;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    int start = -1;
    for (int i = 0; i < n; i++)
        if (ind[i] == 0)
            start = i;

    dfs(start);

    string ans = "";
    for (int i = 0; i < (int)res.size(); i++)
        ans += s[res[i]];
    cout << "Case #" << test_number << ": " << ans << endl;;
}

