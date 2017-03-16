#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

struct bipartite_graph {
    int A, B;
    vector<vector<int>> adj;

    bipartite_graph(int _A, int _B) {
        A = _A, B = _B;
        adj.resize(A + B);
    }

    void edge(int i, int j) {
        adj[i].push_back(A+j);
        adj[A+j].push_back(i);
    }

    vector<int> visit, match;

    bool augment(int loc, int run) {
        if(visit[loc] == run) return false;
        visit[loc] = run;

        for (int nbr : adj[loc]) {
            if (match[nbr] == -1 || augment(match[nbr], run)) {
                match[loc] = nbr, match[nbr] = loc;
                return true;
            }
        }

        return false;
    }

    int matching() {
        visit = vector<int>(A+B, -1);
        match = vector<int>(A+B, -1);

        int ans = 0;
        for (int i = 0; i < A; i++)
            ans += augment(i, i);
        return ans;
    }
};

int abs(int a, int b) {
    return a > b ? a - b : b - a;
}

int main() {
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        map<string,int> left, right;
        int left_idx = 0, right_idx = 0;
        vector<pair<int,int>> edges;
        while (N--) {
            string a, b;
            cin >> a >> b;
            if (left.count(a) == 0)
                left[a] = left_idx++;
            if (right.count(b) == 0)
                right[b] = right_idx++;
            edges.push_back(make_pair(left[a], right[b]));
        }

        bipartite_graph graph(left.size(), right.size());
        for (auto pair : edges)
            graph.edge(pair.first, pair.second);
        int matching = graph.matching();

        int other = 0;
        for (int i = 0; i < graph.adj.size(); i++) {
            if (graph.match[i] == -1) {
                other++;
                for (int adj : graph.adj[i]) {
                    if (graph.match[adj] == -1) {
                        graph.match[adj] = 0;
                        break;
                    }
                }
            }
        }

        int answer = (edges.size() - matching - other);
        printf("Case #%d: %d\n", t, answer);
    }

    return 0;
}
