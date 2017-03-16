/**
* Change is impossible in this fog of ignorance.
*/
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <climits>
#include <cstdio>
#include <cstring>
#include <cctype>
#include <cassert>
#include <cmath>
using namespace std;

#define trace(x) {cerr << #x << "=" << x <<endl;}
#define trace2(x, y) {cerr << #x << "=" << x << " " << #y << "=" << y <<endl;}
#define track(x) {cerr << #x << ":" << endl; for (int q = 0; q < x.size(); q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackarr(x, n) {cerr << #x << ":" << endl; for (int q = 0; q < n; q++) {cerr << x[q] << " ";} cerr << endl;}
#define trackvv(x) {cerr << #x << ":" << endl; for (int i = 0; i < x.size(); i++) { cerr << "i:" << i << endl; for (int j = 0; j < x[i].size(); j++){cerr << x[i][j] << " ";} cerr << endl;} cerr << endl;}
#define trackcr(x) {cerr << #x << ":" << endl; for (auto i = x.begin(); i != x.end(); i++) {cerr << *i << " ";} cerr << endl;}
template <typename Tk, typename Tv> ostream& operator<<(ostream& os, const pair<Tk, Tv> &p){os << "{" << p.first << ',' << p.second << "}";return os;}

typedef long long ll;

const int MAX = 100005;
const int MOD = 1000000000+7;
const int INF = 1000000000;

void inout() {
    freopen("C-large.in", "r", stdin);
    freopen("C-large.out", "w", stdout);
}


typedef vector<vector<int> > graph;
class SCC {
    static const int MAX = 100005;

    void transpose(vector<vector<int> > &G, vector<vector<int> > &GT)
    {
        GT.resize(G.size());
        for (int i = 0; i < G.size(); i++) {
            for (int j = 0; j < G[i].size(); j++) {
                int v = G[i][j];
                GT[v].push_back(i);
            }
        }
    }

    public:
    //This fucntion can be used for toposort
    void decomposeSCC(graph &G, int u, bool isVisited[], vector<int> &sortedList)
    {
        isVisited[u] = true;
        for (int i = 0; i < G[u].size(); i++) {
            int v = G[u][i];
            if (isVisited[v] == false) {
                decomposeSCC(G, v, isVisited, sortedList);
            }
        }
        sortedList.push_back(u);
    }

    vector<vector<int> > decompose(graph &G)
    {
        vector<vector<int> > SCCList;
        bool isVisited[MAX] = {false};
        vector<int> sortedList;
        for (int i = 0; i < G.size(); i++) {
            if (!isVisited[i]) {
                decomposeSCC(G, i, isVisited, sortedList);
            }
        }
        reverse(sortedList.begin(), sortedList.end());
        vector<vector<int> > GT;
        transpose(G, GT);
        memset(isVisited, 0, sizeof(isVisited));
        for (int i = 0; i < sortedList.size(); i++) {
            int source = sortedList[i];
            if (!isVisited[source]) {
                vector<int> scc;
                decomposeSCC(GT, source, isVisited, scc);
                SCCList.push_back(scc);
            }
        }
        return SCCList;
    }
};


int dfs(vector<vector<int> > &T, int u, int parent) {
    int depth = 0;
    for (int i = 0; i < T[u].size(); i++) {
        int v = T[u][i];
        if (v==parent) continue;
        depth = max(depth, dfs(T, v, u));
    }
    depth++;
    return depth;
}
void doTask() {
    int n;
    cin >> n;
    vector<int> bff(n);
    vector<vector<int> > G(n), T(n);
    for (int u = 0; u < n; u++) {
        int v;
        cin >> v; v--;
        G[u].push_back(v);
        T[v].push_back(u);
        bff[u]=v;
    }
    SCC S;
    vector<vector<int> > scc = S.decompose(G);
    vector<int> two;

    int maxLength = 0;
    for (int i = 0; i < scc.size(); i++) {
        int size = scc[i].size();
        if (size > 2) {
            maxLength = max(maxLength, size);
        } else if (size == 2) {
            two.push_back(scc[i][0]);
            two.push_back(scc[i][1]);
        }
    }

    //track(two);

    vector<int> depth(n);
    for (int i = 0; i < two.size(); i++) {
        int u = two[i], v =  bff[two[i]];
        depth[u] = dfs(T, u, v);
    }

    //track(depth);

    int length = 0;
    vector<bool> mark(n);
    for (int i = 0; i < two.size(); i++) {
        int u = two[i], v =  bff[two[i]];
        if (mark[u] || mark[v]) continue;
        mark[u]=true; mark[v]=true;
        length += depth[u]+depth[v];
    }

    maxLength = max(maxLength, length);

    cout << maxLength << endl;
}

int main() {
    inout();
    int tc;
    scanf("%d", &tc);
    for (int t = 1; t <= tc; t++) {
        printf("Case #%d: ", t);
        doTask();
    }
}
