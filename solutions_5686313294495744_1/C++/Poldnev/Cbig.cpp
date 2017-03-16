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

ifstream in("C-large-1.in");
//ifstream in("input.txt");
ofstream out("output.txt");

bool go(vvint &g, vector<bool> &used, vint &mt, int v) {
    if (used[v]) {
        return false;
    }
    used[v] = true;
    for (int i : g[v]) {
        if (mt[i] == -1 || go(g, used, mt, mt[i])) {
            mt[i] = v;
            return true;
        }
    }
    return false;
}

void solve()
{
    int n;
    in >> n;
    map<string, int> firsts, seconds;
    vpint pairs(n);

    for (pint &p : pairs) {
        string ff, ss;
        in >> ff >> ss;
        if (firsts.count(ff)) {
            p.f = firsts[ff];
        } else {
            int size = firsts.size();
            p.f = firsts[ff] = size;
        }
        if (seconds.count(ss)) {
            p.s = seconds[ss];
        } else {
            int size = seconds.size();
            p.s = seconds[ss] = size;
        }
    }

    int n1 = firsts.size(), n2 = seconds.size();
    vvint g(n1);
    for (const pint &p : pairs) {
        g[p.f].pb(p.s);
    }

    vector<bool> used(n1);
    vector<int> mt(n2, -1);

    for (int v = 0; v < n1; ++v) {
        fill(used.begin(), used.end(), false);
        go(g, used, mt, v);
    }

    int res = n1 + n2;
    for (int i = 0; i < n2; ++i) {
        if (mt[i] != -1) {
            --res;
        }
    }
    out << n - res;
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
