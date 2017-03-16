#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <utility>
#include <set>
#include <map>
#include <numeric>
#include <cstdio>
#include <cstring>
#include <iomanip>

using namespace std;

#define pb push_back
#define f first
#define s second
typedef long long ll;
typedef pair<int, int> pint;
typedef pair<long long, long long> plint;
typedef vector<int> vint;
typedef vector<vector<int>> vvint;
typedef vector<long long> vlint;
typedef vector<vector<long long>> vvlint;
typedef vector<pair<int, int>> vpint;
typedef vector<pair<long long, long long>> vplint;

ifstream in("C-small-attempt0.in");
ofstream out("output.txt");

int n, m;
vector<vector<int>> edges;
vector<int> prior;
vector<bool> used;
vector<int> ans;
vector<int> ans_cur;
int prefix;


void go(int v)
{
    bool new_vertex = !used[v];
    used[v] = true;
    if (new_vertex) {
        //cerr << "new " << v << endl;
        ans_cur.pb(prior[v]);
        if (prefix == int(ans_cur.size() - 1)) {
            prefix += (prior[v] == ans[ans_cur.size() - 1]);
        }
    }

    /*for (int x : ans_cur) {
        cerr << x + 1 << " ";
    }
    cerr << ", current " << v + 1 << ", answer ";
    for (int x : ans) {
        cerr << x + 1 << " ";
    }
    cerr << endl;*/

    int cur_size = ans_cur.size();
    if (prefix < n && cur_size == n) {
        prefix = n;
        ans = ans_cur;
    } else {
        //cerr << __LINE__ << endl;
        for (int w = 0; w < n; ++w) {
            if (edges[w][v] == 2) {
                edges[w][v] = 3;
                go(w);
                edges[w][v] = 2;
            } else if (!used[w] && edges[v][w] && (prefix < cur_size || prior[w] <= ans[cur_size])) {
                edges[v][w] = 2;
                go(w);
                edges[v][w] = 1;
            }
        }

    }


    if (new_vertex) {
        used[v] = false;
        ans_cur.pop_back();
        prefix = min(prefix, int(ans_cur.size()));
        //cerr << "bye " << v << endl;
    }
}


void solve()
{
    in >> n >> m;
    vector<int> code(n);
    edges.resize(n, vector<int>(n, 0));
    prior.resize(n);
    vector<pair<int, int>> code_pairs;
    for (int i = 0; i < n; ++i) {
        in >> code[i];
        code_pairs.emplace_back(code[i], i);
    }
    sort(code_pairs.begin(), code_pairs.end());
    for (int i = 0; i < n; ++i) {
        prior[code_pairs[i].second] = i;
    }

    for (int i = 0; i < m; ++i) {
        int x, y;
        in >> x >> y;
        --x, --y;
        edges[x][y] = edges[y][x] = 1;
    }

    used.resize(n, false);
    //cerr << __LINE__ << endl;
    ans.resize(n, n);
    for (int i = 0; i < n; ++i) {
        //cerr << i << endl;
        prefix = 0;
        if (prior[i] <= ans[0]) {
            go(i);
        }
    }

    for (int prior : ans) {
        out << code_pairs[prior].first;
    }

    edges.clear();
    prior.clear();
    used.clear();
    ans.clear();
    ans_cur.clear();
}

int main()
{
    int cases;
    in >> cases;
    for (int z = 0; z < cases; ++z) {
        out << "Case #" << z + 1 << ": ";
        solve();
        out << endl;
    }

    return 0;
}
