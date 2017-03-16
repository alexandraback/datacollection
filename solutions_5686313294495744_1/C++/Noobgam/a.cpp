#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <vector>
#include <unordered_map>

using namespace std;

const int N = 1e4;
vector <string> l, r;
vector <int> g[N];
int paired[N];
bool used[N];

bool try_kuhn(int v)
{
    if (used[v])  return false;
    used[v] = true;
    for (size_t i = 0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (paired[to] == -1 || try_kuhn(paired[to])) 
        {
            paired[to] = v;
            return true;
        }
    }
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    for (int test = 0; test < t; ++test)
    {
        //answer for graph is:
        int n;
        cin >> n;
        vector <pair <string, string> > v;
        l.clear();
        r.clear();
        for (int j = 0; j < n; ++j)
        {
            string a, b;
            cin >> a >> b;
            v.push_back({ a, b });
            l.push_back(a);
            r.push_back(b);
        }
        sort(l.begin(), l.end());
        sort(r.begin(), r.end());
        l.resize(unique(l.begin(), l.end()) - l.begin());
        r.resize(unique(r.begin(), r.end()) - r.begin());
        for (int i = 0; i < l.size(); ++i)
            g[i].clear();
        for (int i = 0; i < r.size(); ++i)
            paired[i] = -1;
        for (auto x : v)
        {
            int idl = lower_bound(l.begin(), l.end(), x.first) - l.begin();
            int idr = lower_bound(r.begin(), r.end(), x.second) - r.begin();
            g[idl].push_back(idr);
        }
        //V + E - matching
        vector<char> used1(l.size(), false);
        for (int i = 0; i < l.size(); ++i)
            for (size_t j = 0; j < g[i].size(); ++j)
                if (paired[g[i][j]] == -1) {
                    paired[g[i][j]] = i;
                    used1[i] = true;
                    break;
                }
        for (int i = 0; i < l.size(); ++i) 
        {
            if (used1[i])  continue;
            memset(used, 0, sizeof(used));
            try_kuhn(i);
        }

        int matching = 0;
        for (int i = 0; i < r.size(); ++i)
            if (paired[i] != -1)
                ++matching;
        matching = (int)(l.size() + r.size()) - matching;
        cout << "Case #" << test + 1 << ": ";
        cout << n - matching << endl;
    }
    return 0;
}