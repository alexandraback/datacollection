#include <algorithm>
#include <bitset>
#include <cassert>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int N, M;
vector<vector<int>> G;
vector<string> zip(N);
vector<pair<string, int>> order(N);

vector<bool> V;

void dfs(int at, const vector<bool>& visited) {
  if (V[at])
    return;
  V[at] = true;
  for (auto e : G[at]) {
    if (visited[e]) {
      continue;
    }
    dfs(e, visited);
  }
}

bool possible(const vector<int>& path, const vector<bool>& visited) {
  for (int i = 0; i < N; i++)
    V[i] = false;
  for (auto p : path) {
    dfs(p, visited);
  }
  for (int i = 0; i < N; i++) {
    if (!V[i] && !visited[i]) {
      return false;
    }
  }
  return true;
}

string solve(vector<int> path, vector<bool> visited) {
  bool left = false;
  for (auto v : visited) {
    left |= !v;
  }
  if (!left) {
    return "";
  }

  vector<pair<string&, int>> moves;
  int at = path[path.size()-1];
  for (auto e : G[at]) {
    if (visited[e])
      continue;
    std::pair<string&, int> p(zip[e], e);
    moves.push_back(p);
  }
  string best = "";
  int m;
  sort(moves.begin(), moves.end());
  for (const auto& move : moves) {
    path.push_back(move.second);
    visited[move.second] = true;
    if (possible(path, visited)) {
      best = zip[move.second] + solve(path, visited);
      m = move.second;
      visited[move.second] = false;
      path.pop_back();
      break;
    }
    path.pop_back();
    visited[move.second] = false;
  }

  string best2 = "";
  path.pop_back();
  if (possible(path, visited)) {
    best2 = solve(path, visited);
  }
  path.push_back(at);

  if (best.size() == 0 && best2.size() == 0) {
    assert(false);
  } else if (best.size() == 0) {
    return best2;
  } else if (best2.size() == 0) {
    visited[m] = true;
    return best;
  } else if (best < best2) {
    visited[m] = true;
    return best;
  } else {
    return best2;
  }
}


int main() {
  int T;
  cin >> T;
  for (int zz = 1; zz <= T; zz++) {
    cin >> N >> M;
    zip.clear(); 
    zip.resize(N);
    order.clear(); 
    order.resize(N);
    V.clear();
    V.resize(N);
    for (int i = 0; i < N; i++) {
      cin >> zip[i];
      order[i] = make_pair(zip[i], i);
    }
    sort(order.begin(), order.end());

    G.clear();
    G.resize(N);
    for (int i = 0; i < M; i++) {
      int a, b;
      cin >> a >> b;
      a--;
      b--;
      G[a].push_back(b);
      G[b].push_back(a);
    }

    vector<bool> visited(N);
    visited[order[0].second] = true;
    auto ans = zip[order[0].second] + solve({order[0].second}, visited);
    cout << "Case #" << zz << ": " << ans << endl;

  }
}
