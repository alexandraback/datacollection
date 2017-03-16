#include <iostream>
#include <map>
#include <set>
#include <vector>

using namespace std;

#define REP(i,n) for(int i=0;i<(int)n;++i)
#define FOR(i,c) for(__typeof((c).begin())i=(c).begin();i!=(c).end();++i)
#define ALL(c) (c).begin(), (c).end()

typedef int Weight;
struct Edge {
    int src, dst;
    Weight weight;
    Edge(int src, int dst, Weight weight) :
        src(src), dst(dst), weight(weight) { }
};
bool operator < (const Edge &e, const Edge &f) {
    return e.weight != f.weight ? e.weight > f.weight : // !!INVERSE!!
        e.src != f.src ? e.src < f.src : e.dst < f.dst;
}
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

typedef vector<Weight> Array;
typedef vector<Array> Matrix;

bool augment(const Graph& g, int u,
    vector<int>& matchTo, vector<bool>& visited) {
  if (u < 0) return true;
  FOR(e, g[u]) if (!visited[e->dst]) {
    visited[e->dst] = true;
    if (augment(g, matchTo[e->dst], matchTo, visited)) {
      matchTo[e->src] = e->dst;
      matchTo[e->dst] = e->src;
      return true;
    }
  }
  return false;
}
int bipartiteMatching(const Graph& g, int L, Edges& matching) {
  const int n = g.size();
  vector<int> matchTo(n, -1);
  int match = 0;
  REP(u, L) {
    vector<bool> visited(n);
    if (augment(g, u, matchTo, visited)) ++match;
  }
  REP(u, L) if (matchTo[u] >= 0) // make explicit matching
    matching.push_back( Edge(u, matchTo[u], 1) );
  return match;
}

int main() {
    int T;
    cin >> T;

    for (int t = 0; t < T; t++) {
        int N;
        cin >> N;

        string a, b;
        map<string, int> f, s;
        vector<pair<int, int>> p;

        for (int i = 0; i < N; i++) {
            cin >> a >> b;

            if (f.find(a) == f.end())
                f[a] = f.size();
            if (s.find(b) == s.end())
                s[b] = s.size();

            p.push_back(pair<int, int>(f[a], s[b]));
        }

        Graph g;
        for (int i = 0; i < f.size() + s.size(); i++)
            g.push_back(Edges());
        
        for (int i = 0; i < p.size(); i++) {
            g[p[i].first].push_back(Edge(p[i].first, p[i].second + f.size(), 1));
            g[p[i].second + f.size()].push_back(Edge(p[i].second + f.size(), p[i].first, 1));
        }

        Edges e;
        bipartiteMatching(g, f.size(), e);

        set<int> ff, ss;

        for (int i = 0; i < e.size(); i++) {
            ff.insert(e[i].src);
            ss.insert(e[i].dst);
        }

        int ans = e.size() + (f.size() - ff.size()) + (s.size() - ss.size());
        cout << "Case #" << t + 1 << ": " << N - ans << endl;
    }
}

