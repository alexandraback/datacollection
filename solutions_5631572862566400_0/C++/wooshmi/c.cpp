#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

const int kMaxN = 1005;

bool vis[kMaxN];
int next[kMaxN];

vector < int > parents[kMaxN];

int cycle(int start, int node, int length) {
    if (vis[node]) {
        if (node == start)
            return (length - 1);
        else
            return (-1);
    }
    vis[node] = true;
    return cycle(start, next[node], length + 1);
}

int backdfs(int node, int length) {
    if (parents[node].size() == 0)
        return length;
    int ansc = 0;
    for (int j = 0; j < parents[node].size(); ++j) {
        int aux = backdfs(parents[node][j], length + 1);
        if (aux > ansc)
            ansc = aux;
    }
    return ansc;
}

int main() {
    ifstream in;
    in.open("dataset.in");
    ofstream out;
    out.open("dataset.out");

    int T;
    in >> T;

    for (int i = 0; i < T; ++i) {
        int n;
        in >> n;
        for (int j = 1; j <= n; ++j) {
            in >> next[j];
            parents[next[j]].push_back(j);
        }
        int ans = -1;
        for (int start = 1; start <= n; ++start) {
            for (int j = 1; j <= n; ++j)
                vis[j] = false;
            int aux = cycle(start, start, 1);
            if (aux > ans)
                ans = aux;
        }
        int op = 0;
        for (int j = 1; j <= n; ++j)
            vis[j] = false;
        for (int start = 1; start <= n; ++start)
            if (next[next[start]] == start && !vis[start]) {
                vis[start] = vis[next[start]] = true;
                for (int j = 0; j < parents[start].size(); ++j)
                    if (parents[start][j] == next[start]) {
                        parents[start].erase(parents[start].begin() + j);
                        break;
                    }
                for (int j = 0; j < parents[next[start]].size(); ++j)
                    if (parents[next[start]][j] == start) {
                        parents[next[start]].erase(parents[next[start]].begin() + j);
                        break;
                    }
                op += backdfs(start, 0) + backdfs(next[start], 0) + 2;
            }
        if (op > ans)
            ans = op;
        out << "Case #" << (i + 1) << ": " << ans << "\n";
        for (int j = 1; j <= n; ++j)
            parents[j].clear();
    }
    
    in.close();
    out.close();
    return 0;
}
