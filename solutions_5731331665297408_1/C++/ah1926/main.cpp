#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cassert>

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <set>

using namespace std;

typedef long long int64;

const int NIL = -1;

vector< vector<int> > G;
vector< vector<bool> > Adjacent;
int V, E;
vector<string> Codes;
vector< pair<int, int> > Edges;
string Answer;

void NormalizeGraph() {
    vector<int> order = vector<int>(V);
    for (int x = 0; x < V; ++x)
        order[x] = x;
    sort(order.begin(), order.end(), [](const int x, const int y) -> bool {
        return Codes[x] < Codes[y];
    });
    vector<int> newIndex = vector<int>(V);
    for (int x = 0; x < V; ++x)
        newIndex[order[x]] = x;
    for (int i = 0; i < E; ++i) {
        Edges[i].first = newIndex[Edges[i].first];
        Edges[i].second = newIndex[Edges[i].second];
        int x = Edges[i].first, y = Edges[i].second;
        G[x].push_back(y);
        G[y].push_back(x);
        Adjacent[x][y] = Adjacent[y][x] = true;
    }
    sort(Codes.begin(), Codes.end());
}

void DFS(const int x, vector<bool> &used) {
    used[x] = true;
    for (const auto &y: G[x])
        if (!used[y])
            DFS(y, used);
}

bool Connected(const vector<int> &sources, vector<bool> used) {
    for (const auto &x: sources)
        DFS(x, used);
    for (int x = 0; x < V; ++x)
        if (!used[x])
            return false;
    return true;
}

void Solve() {
    NormalizeGraph();
    Answer = Codes[0];
    vector<int> lastPath = vector<int>(1, 0);
    vector<bool> used = vector<bool>(V, false);
    used[0] = true;
    for (int i = 1; i < V; ++i) {
        for (int x = 0; x < V; ++x) {
            if (used[x])
                continue;
            vector<int> newLastPath = lastPath;
            for (; !newLastPath.empty() && !Adjacent[newLastPath.back()][x]; newLastPath.pop_back());
            if (newLastPath.empty())
                continue;
            used[x] = true;
            newLastPath.push_back(x);
            if (Connected(newLastPath, used)) {
                lastPath = newLastPath;
                Answer += Codes[x];
                break;
            } else {
                used[x] = false;
                continue;
            }
        }
    }
}

int main() {
    assert(freopen("input.txt", "r", stdin));
    assert(freopen("output.txt", "w", stdout));
    int testCount;
    cin >> testCount;
    for (int test = 1; test <= testCount; ++test) {
        cin >> V >> E;
        G = vector< vector<int> >(V, vector<int>());
        Adjacent = vector< vector<bool> >(V, vector<bool>(V, false));
        Codes = vector<string>(V, "");
        for (int x = 0; x < V; ++x)
            cin >> Codes[x];
        Edges = vector< pair<int, int> >(E, pair<int, int>());
        for (int e = 0; e < E; ++e) {
            int x, y;
            cin >> x >> y;
            Edges[e] = make_pair(--x, --y);
        }
        Solve();
        cout << "Case #" << test << ": " << Answer << "\n";
    }
    return 0;
}
