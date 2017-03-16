#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stack>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int> > zips;
map<int, int> orig_to_final;

int A[100][100];

bool solvable(vector<int>& tree, set<int>& dead) {
  set<int> explored;
  for (set<int>::iterator it = dead.begin(); it != dead.end(); ++it) {
    explored.insert(*it);
  }
  for (int i = 0; i < tree.size(); ++i) explored.insert(tree[i]);
  
  for (int i = 0; i < tree.size(); ++i) {
    stack<int> phoenix;
    phoenix.push(tree[i]);
    while (!phoenix.empty()) {
      int curr = phoenix.top(); phoenix.pop();
      for (int i = 0; i < n; ++i) {
        if (!explored.count(i) && A[curr][i]) {
          phoenix.push(i);
          explored.insert(i);
        }
      }
    }
  }
  return (explored.size() == n);
}

int main() {
  int t; cin >> t;
  for (int test = 1; test <= t; ++test) {
    cin >> n >> m;
    zips.clear(); zips.resize(n);
    for (int i = 0; i < n; ++i) {
      cin >> zips[i].first;
      zips[i].second = i+1;
    }
    sort(zips.begin(), zips.end());
    orig_to_final.clear();
    for (int i = 0; i < zips.size(); ++i) {
      orig_to_final[zips[i].second] = i;
    }

    memset(A, 0, sizeof(A));
    for (int i = 0; i < m; ++i) {
      int a, b; cin >> a >> b;
      a = orig_to_final[a];
      b = orig_to_final[b];
      A[a][b] = 1;
      A[b][a] = 1;
    }

    vector<int> tree; tree.push_back(0);
    vector<int> path; path.push_back(0);
    set<int> dead;

    while (path.size() != n) {
      for (int i = 0; i < n; ++i) { // let's try to go to i next
        bool found = false;
        for (int j = 0; j < path.size(); ++j) {
          if (path[j] == i) found = true;
        }
        if (found) continue;

        vector<int> tree_cpy = tree;
        set<int> dead_cpy = dead;

        bool found_attempt = false;
        while (!tree_cpy.empty()) {
          if (A[tree_cpy.back()][i]) {
            tree_cpy.push_back(i);
            found_attempt = true;
            break;
          } else {
            dead_cpy.insert(tree_cpy.back());
            tree_cpy.pop_back();
          }
        }
        if (solvable(tree_cpy, dead_cpy)) {
          tree = tree_cpy;
          dead = dead_cpy;
          path.push_back(i);
          break;
        }
      }
    }

    cout << "Case #" << test << ": ";
    for (int i = 0; i < n; ++i) {
      cout << zips[path[i]].first;
    }
    cout << endl;
  }
  return 0;
}