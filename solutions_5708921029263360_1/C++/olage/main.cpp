#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <list>
#include <set>
#include <cstdio>
#include <cmath>
#include <iomanip>
#include <deque>
#include <ctime>
#include <cstring>

//#include <bits/stdc++.h>

using namespace std;

#define fr first
#define sd second
#define pb push_back
#define mp make_pair

#define endl '\n'

#define forr(i, n) for(ll (i) = 0LL; (i) < (n); (i)++)
#define mp3(a, b, c) mp(a, mp(b, c))

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;
typedef vector < vector < double > > vvd;
typedef vector < double > vd;
typedef vector < pair < double, double> > vdd;
typedef vector < vector < long long > > vvl;
typedef vector < long long > vl;
typedef vector < pll > vll;

int INT_MAX_VAL = (int)  0x3F3F3F3F;
int INT_MIN_VAL = (int) -0x3F3F3F3F;
ll LONG_MAX_VAL = (ll)   0x3F3F3F3F3F3F3F3F;
ll LONG_MIN_VAL = (ll)  -0x3F3F3F3F3F3F3F3F;

#define MAXN 500006
#define MOD 1000000007

int adj[1000][1000];
int fl[1000][1000];
int used[1000][1000];
int dst[1000];
int graph_size;

bool bfs() {
    int from = 0;
    int to = 1;
    deque<int> q;
    q.push_back(from);
    forr (i, 1000) dst[i] = -1;

    dst[from] = 0;
    while (!q.empty()) {
        int v = q.front();
        q.pop_front();
        for (int w = 0; w < graph_size; ++w) {
            if (dst[w] == -1 && fl[v][w] < adj[v][w]) {
                q.push_back(w);
                dst[w] = dst[v] + 1;
            }
        }
    }
    return dst[to] != -1;
}

int dfs (int v, int flow) {
    if (!flow) return 0;
    if (v == 1) return flow;
    for (int w = 0; w < graph_size; ++w) {
        if (dst[w] != dst[v] + 1) continue;
        int pushed = dfs (w, min(flow, adj[v][w] - fl[v][w]));
        if (pushed) {
            fl[v][w] += pushed;
            fl[w][v] -= pushed;
            return pushed;
        }
    }
    return 0;
}

int find_max_flow()
{
    forr (i, graph_size) forr(j, graph_size) fl[i][j] = 0;
    int flow = 0;
    while (true) {
        if (!bfs())  break;
        int pushed;
        while (true) {
            int pushed = dfs(0, 10000);
            if (!pushed) break;
            flow += pushed;
        }
    }
    return flow;
}

int solve()
{
    int a, b, c, K; cin >> a >> b >> c >> K;

    int left_cnt = b;
    int right_cnt = c;
        graph_size = left_cnt + right_cnt + 2;

    int from = 0;
    int to = 1;
    vector<string> result;
    for (int i = 0; i < graph_size; ++i) for (int j = 0; j < graph_size; ++j) {
        used[i][j] = 0;
        adj[i][j] = 0;
        fl[i][j] = 0;
    }

    for (int first_num = 1; first_num <= a; ++first_num) {
        for (int i = 0; i < left_cnt; ++i) {
            adj[from][i + 2] = K;
        }

        for (int i = 0; i < right_cnt; ++i) {
            adj[i + 2 + left_cnt][to] = K;
        }

        for (int i = 0; i < left_cnt; ++i) {
            for (int j = 0; j < right_cnt; ++j) {
                adj[i + 2][j + 2 + left_cnt] = used[i][j] < K;
            }
        }
/*
        cout << endl;
        for (int i = 0; i < graph_size; ++i) {
            for (int j = 0; j < graph_size; ++j) {
                cout << adj[i][j] << " ";
            }
            cout << endl;
        }
*/
        find_max_flow();

        for (int i = 0; i < left_cnt; ++i) {
            for (int j = 0; j < right_cnt; ++j) {
                if (fl[i + 2][j + 2 + left_cnt] == 1) {
                    ++used[i][j];
                    result.push_back(to_string(first_num) + " " + to_string(i + 1) + " " + to_string(j + 1));
                }
            }
        }
    }
    cout << result.size() << endl;
    for (auto& s : result) {
        cout << s << endl;
    }
}

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    for(int i = 1; i <= t; ++i) {
        cout << "Case #" << i << ": ";
        solve();
    }

    return 0;
}
