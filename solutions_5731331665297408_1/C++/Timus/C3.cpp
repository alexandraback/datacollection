#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

vector<string> names;
vector<vector<int> > g;
vector<int> used, used2;

int n, test_n;

bool cmp(int x, int y) {
    return names[x] < names[y];
}

string ans;

class cmp2 {
public:
    bool operator() (const int &a, const int &b) const {
        return names[a] < names[b];
    }
};

set<int, cmp2> z;

void dfs2(int v) {
    used2[v] = 1;

    for (int i = 0; i < g[v].size(); ++i)
        if (used2[g[v][i]] == 0)
            dfs2(g[v][i]);
}

bool can_reach_all(vector<int> st, int v) {
    int pos = st.size() - 1;
    while (pos >= 0 && find(g[st[pos]].begin(), g[st[pos]].end(), v) == g[st[pos]].end()) {
//        if (test_n == 56)
//            cerr << "!!!!!!" << st[0] << endl;
        --pos;
    }
//    if (test_n == 56)
//        cerr << v << " " << pos << " " << st.size() << endl;
    if (pos < 0)
        return false;


    used2.clear();
    used2.resize(n);
    for (int i = 0; i < n; ++i)
        used2[i] = used[i];
    for (int i = 0; i <= pos; ++i)
        used2[st[i]] = 0;
//    for (int i = pos + 1; i < st.size(); ++i)
//        used2[st[i]] = 2;
    dfs2(v);
//    cerr << "v" << v << endl;

    for (int i = 0; i < n; ++i)
        if (used2[i] == 0)
            return false;
    return true;
}

void dfs(int v, vector<int> & st) {
//    cerr << st.size() << endl;
    for (int i = 0; i < g[v].size(); ++i)
        if (used[g[v][i]] == 0)
            z.insert(g[v][i]);
//    cerr << v << endl;
    used[v] = 1;
    ans += names[v];
/*    for (int i = 0; i < g[v].size(); ++i)
        if (!used[g[v][i]])
            dfs(g[v][i]);*/
    for (set<int>::iterator it = z.begin(); it != z.end(); ++it) {
        if (can_reach_all(st, *it)) {
            int pos = st.size() - 1;
//            if (test_n == 56)
//                cerr << "####" << st[pos] <<endl;
            while (pos >= 0 && find(g[st[pos]].begin(), g[st[pos]].end(), *it) == g[st[pos]].end()) {
                --pos;
                st.pop_back();
//                if (test_n == 56)
//                    cerr << st.size() << "@" << pos << endl;
            }
            z.erase(*it);
            st.push_back(*it);
            dfs(*it, st);
            break;
        }
    }
}

int main() {
    int tests;
    cin >> tests;
    for (int test = 1; test <= tests; ++test) {
        cerr << test << endl;
        test_n = test;
        names.clear();
        g.clear();
        int m;
        cin >> n >> m;
        cerr << n << " " << m << endl;
        names.resize(n);
        g.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> names[i];
        for (int i = 0; i < m; ++i) {
            int v, u;
            cin >> v >> u;
            --v, --u;
            g[v].push_back(u);
            g[u].push_back(v);
        }
        for (int i = 0; i < n; ++i)
            sort(g[i].begin(), g[i].end(), cmp);

        int mini = 0;
        for (int i = 1; i < n; ++i)
            if (names[mini] > names[i])
                mini = i;
        vector<int> st;
        st.push_back(mini);
        used.clear();
        used.resize(n);
        z.clear();
        ans = "";
        dfs(mini, st);

/*        if (test != 56)
            continue;
        cerr << n << " " << m << endl;
        for (int i = 0; i < n; ++i)
            cerr << names[i] << endl;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < g[i].size(); ++j)
                cerr << g[i][j] << " ";
            cerr << endl;
        }*/
        printf("Case #%d: %s\n", test, ans.c_str());
    }
}
