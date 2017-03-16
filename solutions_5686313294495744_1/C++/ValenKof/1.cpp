#include <algorithm>
#include <cmath>
#include <bitset>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <queue>

using namespace std;

#define all(x) x.begin(), x.end()
#define forn(i, n) for(int i = 0; i < (n); ++i)
#define debug(x) std::cerr << "DEBUG: " << #x << " = " << (x) << std::endl
#define mp make_pair
#define pb push_back
#define PATH "C:\\Users\\Valentin\\Desktop\\"

template<class T> inline int sz(const T& x)
{ return (int) x.size(); }

template<class X, class Y> inline void mx(X& x, Y&& y)
{ if (x < y) x = std::forward<Y>(y); }

template<class X, class Y> inline void mn(X& x, Y&& y)
{ if (y < x) x = std::forward<Y>(y); }

// SOLUTION BEGINS HERE


template<typename TCap, typename TCost, typename TCapLarge = TCap, typename TCostLarge = TCost>
struct Graph
{
    typedef function<TCost(int, int, int)> CostFunction;

    // nodes
    vector<int> head;
    vector<int> from;
    vector<int> q;
    vector<char> used;
    vector<TCost> dist;

    // edges
    vector<int> dest;
    vector<int> next;
    vector<TCap> cap;
    vector<TCost> cost;

    int n, s, t, mask;

    CostFunction simple;

    Graph(int n, int capacity)
        : head(n, -1)
        , from(n)
        , used(n)
        , dist(n)
        , n(n)
        , s(n - 2)
        , t(n - 1)
        , simple([&](int arc, int u, int v) { return cost[arc]; })
    {
        dest.reserve(capacity);
        next.reserve(capacity);
        cap.reserve(capacity);
        cost.reserve(capacity);
        int mask = 1;
        while (mask <= n) {
            mask <<= 1;
        }
        mask--;
        this->mask = mask;
        q.resize(mask + 1);
    }

    inline void addArc(int u, int v, TCap cap, TCost cost)
    {
        this->dest.pb(v);
        this->next.pb(head[u]);
        this->cap.pb(cap);
        this->cost.pb(cost);
        head[u] = sz(dest) - 1;
    }

    inline void addEdge(int u, int v, TCap cap, TCost cost)
    {
        addArc(u, v, cap, cost);
        addArc(v, u, 0, -cost);
    }

    inline bool bf(vector<TCost>& dist, CostFunction cost)
    {
        fill(all(dist), numeric_limits<TCost>::max());
        fill(all(used), false);
        fill(all(from), -1);
        int qh = 0, qt = 0;

        dist[s] = 0;
        used[s] = true;
        q[qt] = s; qt = (qt + 1) & mask;
        while (qh != qt) {
            int u = q[qh]; qh = (qh + 1) & mask;
            TCost du = dist[u];
            used[u] = false;
            for (int arc = head[u]; arc != -1; arc = next[arc]) {
                int v = dest[arc];
                TCost dv = du + cost(arc, u, v);
                if (cap[arc] > 0 && dv < dist[v]) {
                    dist[v] = dv;
                    from[v] = arc;
                    if (!used[v]) {
                        q[qt] = v; qt = (qt + 1) & mask;
                        used[v] = true;
                    }
                }
            }
        }
        return dist[t] < numeric_limits<TCost>::max();
    }

    inline pair<TCapLarge, TCostLarge> maxPath(
        TCapLarge minCap = numeric_limits<TCapLarge>::max())
    {
        TCostLarge sumCost = 0;
        for (int v = t; v != s; v = dest[from[v] ^ 1]) {
            // debug(v);
            mn(minCap, cap[from[v]]);
            sumCost += cost[from[v]];
        }
        for (int v = t; v != s; v = dest[from[v] ^ 1]) {
            cap[from[v]] -= minCap;
            cap[from[v] ^ 1] += minCap;
        }
        return mp(minCap, sumCost * minCap);
    }

    pair<TCapLarge, TCostLarge> mcmf()
    {
        pair<TCapLarge, TCostLarge> result = mp(0, 0);
        // Case 1: only bf
        while (bf(dist, simple)) {
            auto path = maxPath();
            if (path.second >= 0) {
              break;
            }
            result.first += path.first;
            result.second += path.second;
        }

        return result;
    }
};

int dp_bit[1 << 16];

vector<pair<string, string>> input() {
  int n;
  cin >> n;
  vector<pair<string, string>> topics(n);
  forn (i, n) {
    cin >> topics[i].first >> topics[i].second;
  }
  return topics;
}

int solve_dp(vector<pair<string, string>> input) {
  dp_bit[0] = 0;
  for (int i = 1; i < (1 << 16); ++i) {
    dp_bit[i] = dp_bit[i >> 1] + (i & 1);
  }

  map<string, int> first, second;
  auto add = [](map<string, int>& idx, string s) {
    auto it = idx.find(s);
    if (it != idx.end()) {
      return it->second;
    }
    int id = idx.size();
    idx[s] = id;
    return id;
  };
  int n = input.size();
  vector<pair<int, int>> topics(n);
  forn (i, n) {
    string a = input[i].first;
    string b = input[i].second;
    topics[i] = {1 << add(first, a), 1 << add(second, b)};
  }
  int need_first = (1 << first.size()) - 1;
  int need_second = (1 << second.size()) - 1;
  vector<pair<int, int>> dp(1 << n);
  dp[0] = {0, 0};
  int ans = n;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < (1 << i); ++j) {
      dp[j | (1 << i)].first = dp[j].first | topics[i].first;
      dp[j | (1 << i)].second = dp[j].second | topics[i].second;
    }
  }
  forn (i, (1 << n)) {
    if (dp[i] == pair<int, int>{need_first, need_second}) {
      mn(ans, dp_bit[i]);
    }
  }
  return n - ans;
}

int solve_flow(vector<pair<string, string>> input) {
  map<string, int> first, second;
  auto add = [](map<string, int>& idx, string s) {
    auto it = idx.find(s);
    if (it != idx.end()) {
      return it->second;
    }
    int id = idx.size();
    idx[s] = id;
    return id;
  };
  int n = input.size();
  vector<pair<int, int>> idx(n);
  forn (i, n) {
    idx[i] = {add(first, input[i].first), add(second, input[i].second)};
  }
  int nodes = 1 + first.size() + second.size() + 1;
  int capacity = 2 * (first.size() + n + second.size());
  Graph<int, int> g(nodes, capacity);
  forn (i, sz(first)) {
    g.addEdge(g.s, i, 1, -1);
    g.addEdge(g.s, i, n, 0);
  }
  forn (i, sz(second)) {
    g.addEdge(sz(first) + i, g.t, 1, -1);
    g.addEdge(sz(first) + i, g.t, n, 0);
  }
  forn (i, n) {
    g.addEdge(idx[i].first, sz(first) + idx[i].second, 1, 0);
  }
  return n - g.mcmf().first;
}

void run() {
  freopen("in.txt", "r", stdin);
  freopen("out.txt", "w", stdout);
  int nTests;
  cin >> nTests;
  for (int iTest = 0; iTest < nTests; ++iTest) {
    cout << "Case #" << (iTest + 1) << ": ";
    auto topics = input();
    cout << solve_flow(topics) << endl;
  } 
}

// SOLUTION ENDS HERE

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);
  run();
  std::cout.flush();
  return 0;
}