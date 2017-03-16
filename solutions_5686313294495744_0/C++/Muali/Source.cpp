#include <algorithm>
#include <iostream>
#include <string>
#include <fstream>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cstring>
#include <functional>

using namespace std;

using ll = long long;

ifstream in;
ofstream out;


void solve()
{
    map<string, int> f_idx;
    map<string, int> s_idx;

    auto get_f_idx = [&](string s)
    {
        int nxt = f_idx.size();
        if (!f_idx.count(s))
            f_idx[s] = nxt;
        return f_idx[s];
    };

    auto get_s_idx = [&](string s)
    {
        int nxt = s_idx.size();
        if (!s_idx.count(s))
            s_idx[s] = nxt;
        return s_idx[s];
    };

    vector<vector<int>> g;

    int n;
    in >> n;
    vector<pair<string, string>> ts;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        in >> a >> b;
        ts.emplace_back(a, b);
        get_f_idx(a);
        get_s_idx(b);
    }

    g.resize(f_idx.size() + s_idx.size());
    for (int i = 0; i < n; ++i)
    {
        string a = ts[i].first;
        string b = ts[i].second;
        int a_idx = get_f_idx(a);
        int b_idx = get_s_idx(b);
        g[a_idx].push_back(b_idx);
    }

    vector<int> mt;
    vector<char> used;

    function<bool(int)> try_kuhn = [&](int v) {
	    if (used[v])  return false;
	    used[v] = true;
	    for (size_t i=0; i<g[v].size(); ++i) {
		    int to = g[v][i];
		    if (mt[to] == -1 || try_kuhn (mt[to])) {
			    mt[to] = v;
			    return true;
		    }
	    }
	    return false;
    };

    int cnt = 0;
    mt.assign(s_idx.size(), -1);
    for (int v = 0; v < f_idx.size(); ++v)
    {
        used.assign(f_idx.size(), false);
        if (try_kuhn(v))
            ++cnt;
    }

    out << n - (cnt + f_idx.size() - cnt + s_idx.size() - cnt);
}

int main(int argc, char const *argv[])
{
    in = ifstream(argv[1]);
    out = ofstream(argv[2]);
    //in = ifstream("in.txt");
    //out = ofstream("out.txt");
    int n;
    in >> n;
    for (int i = 0; i < n; ++i)
    {
        out << "Case #" << i + 1 << ": ";
        solve();
        out << endl;
    }
}