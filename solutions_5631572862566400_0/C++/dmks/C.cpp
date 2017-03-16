#include <vector>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>

using namespace std;

int N;

vector<int> v;
int best;

bool verify(const vector<int>& path) {
  if (path.size() < 2) return false;
  for (int i = 0; i < path.size(); i++) {
    int j = i - 1;
    int k = i + 1;
    if (j < 0) j = path.size() - 1;
    if (k >= path.size()) k = 0;

    int bff = v[path[i]];
    if (path[j] != bff && path[k] != bff) {
      return false;
    }
  }
  return true;
}

void go(vector<int>& path, int G) {
  if (verify(path)) {
    if (path.size() > best) best = path.size();
  }
  for (int next = 0; next < N; next++) if (!(G & (1<<next))) {
    path.push_back(next);
    go(path, G | (1<<next));
    path.pop_back();
  }
}

void solve() {
  cin >> N;
  v.clear();
  for (int i = 0; i < N; i++) {
    int k;
    cin >> k;
    v.push_back(k-1);
  }
  best = 0;
  vector<int> path;
  go(path, 0);
  cout << best;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; i++) {
    cout << "Case #" << (i+1) << ": ";
    solve();
    cout << endl;
  }
  return 0;
}
