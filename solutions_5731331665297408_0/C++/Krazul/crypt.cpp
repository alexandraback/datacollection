#include <algorithm>
#include <iostream>
#include <map>
#include <stack>
#include <vector>

using namespace std;

int n, m;
vector<pair<int, int> > zips;
map<int, int> orig_to_final;

int A[100][100];

bool attempt(vector<int>& temp) {
  int idx = 1; // trying to go to...
  stack<int> nodes;
  nodes.push(temp[0]);
  while (true) {
    if (nodes.empty()) return false; // ran out
    if (idx == n) return true; // made it
    int curr = nodes.top();
    if (A[curr][temp[idx]]) {
      nodes.push(temp[idx]);
      ++idx;
      continue;
    } else {
      nodes.pop();
      continue;
    }
  }
}

bool super(vector<int>& temp) {
  if (temp.size() == n) {
    return attempt(temp);
  }
  for (int i = 0; i < n; ++i) {
    bool found = false;
    for (int j = 0; j < temp.size(); ++j) {
      if (temp[j] == i) found = true;
    }
    if (found) continue;
    temp.push_back(i);
    if (super(temp)) return true;
    temp.pop_back();
  }
  return false;
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
    vector<int> temp;
    super(temp);
    cout << "Case #" << test << ": ";
    for (int i = 0; i < n; ++i) {
      cout << zips[temp[i]].first;
    }
    cout << endl;
  }
  return 0;
}