#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 1010;

string topics[MAX_N][2];

map<string, int> compressed_topics[2];

int get_compressed(const string &s, int id) {
  int result;
  if (compressed_topics[id].find(s) == compressed_topics[id].end()) {
    result = compressed_topics[id].size();

    compressed_topics[id][s] = result;
  } else {
    result = compressed_topics[id][s];
  }

  return result;
}

vector<int> adjacent_nodes[MAX_N];
int p[MAX_N];
int last_visited[MAX_N];
int timer = 0;

bool dfs(int v) {
  if (last_visited[v] == timer) {
    return false;
  }

  last_visited[v] = timer;

  for (int u : adjacent_nodes[v]) {
    if (p[u] == -1 || dfs(p[u])) {
      p[u] = v;
      return true;
    }
  }

  return false;
}

void solve(int case_id) {
  int n; cin >> n;

  compressed_topics[0].clear();
  compressed_topics[1].clear();

  for (int i = 0; i < MAX_N; i++) {
    adjacent_nodes[i].clear();
  }

  for (int i = 0; i < n; i++) {
    cin >> topics[i][0] >> topics[i][1];

    int a = get_compressed(topics[i][0], 0);
    int b = get_compressed(topics[i][1], 1);

    adjacent_nodes[a].push_back(b);
  }

  for (int i = 0; i < MAX_N; i++) {
    p[i] = -1;
  }

  int result = 0;
  for (int i = 0; i < compressed_topics[0].size(); i++) {
    timer += 1;
    result += dfs(i);
  }

  result = compressed_topics[0].size() + compressed_topics[1].size() - result;

  cout << "Case #" << case_id << ": " << n - result << "\n";
}

int main() {
  int cases; cin >> cases;

  for (int i = 1; i <= cases; i++) {
    solve(i);
  }

  return 0;
}