#include <iostream>
#include <set>
#include <vector>
using namespace std;

int N;
vector<multiset<int> > ckeys;
vector<int> ctypes;
vector<vector<int> > graph;

multiset<int> keys;
vector<bool> open;
vector<int> ans;

set<vector<bool> > memory;

vector<bool> mark;

void dfs1(int c) {
  if (mark[c] || open[c]) return;
  mark[c] = true;
  for (auto d : graph[c])
    dfs1(d);
}

bool unreach() {
  mark = vector<bool>(N);
  for(int c = 0; c < N; c++)
    if(keys.find(ctypes[c]) != keys.end())
      dfs1(c);
  for(int c = 0; c < N; c++)
    if (!open[c] && !mark[c]) return true;
  return false;
}

bool dfs() {
  if (ans.size() == N) {
    for(auto c : ans) cout << " " << c;
    cout << endl;
    return true;
  }
  if (memory.find(open) != memory.end()) return false;
  if (!unreach()) for(int c = 0; c < N; c++) {
    int k = ctypes[c];
    if (!open[c] && keys.find(k) != keys.end()) {
      open[c] = true;
      keys.erase(keys.find(k));
      for(auto i : ckeys[c]) keys.insert(i);
      ans.push_back(c+1);
      if (dfs()) return true;
      ans.pop_back();
      for(auto i : ckeys[c]) keys.erase(keys.find(i));
      keys.insert(k);
      open[c] = false;
    }
  }
  memory.insert(open);
  return false;
}

int main() {
  int T;
  cin >> T;
  for(int id = 1; id <= T; id++) {
    ckeys.clear();
    ctypes.clear();
    keys.clear();
    ans.clear();
    open.clear();
    graph.clear();
    memory.clear();
    int K;
    cin >> K >> N;
    ckeys.resize(N);
    open.resize(N);
    graph.resize(N);
    for(int i = 0; i < K; i++) {
      int t;
      cin >> t;
      keys.insert(t);
    }
    for(int i = 0; i < N; i++) {
      int t,k;
      cin >> t >> k;
      ctypes.push_back(t);
      for(int j = 0; j < k; j++) {
        cin >> t;
        ckeys[i].insert(t);
      }
    }
    for (int i = 0; i < N; i++)
      for (int j = 0; j < N; j++)
        if (i != j && ckeys[i].find(ctypes[j]) != ckeys[i].end())
          graph[i].push_back(j);
    cout << "Case #" << id << ":";
    if (!dfs()) cout << " IMPOSSIBLE" << endl;
    cerr << "Solved " << id << endl;
  }
}
