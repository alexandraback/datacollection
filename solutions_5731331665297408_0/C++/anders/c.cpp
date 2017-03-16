#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <map>
#include <set>
#include <vector>


using namespace std;

vector<int> cities[10];
int ints[10];
string zips[10];
bool visited[10];
int n, m;

void dfs(int indx) {
  visited[indx] = true;
  int node = ints[indx];
  while (true) {
    int next = 0;
    for (int i=1; i<=n; ++i) {
      if (!visited[i]) {
	next = i;
	break;
      }
    }
    if (next == 0) return;
    bool found = false;
    for (int i=0; i<cities[node].size(); ++i) {
      if (cities[node][i] == ints[next]) {
	dfs(next);
	found = true;
      }
    }
    if (!found) return;
  }
}

bool possible() {
  memset(visited, 0, sizeof(visited));
  dfs(1);
  for (int i = 1; i<=n; ++i) if (!visited[i]) return false;
  return true;
}

void solve() {
  cin >> n >> m;
  for (int i=1; i<=n; ++i) {
    ints[i] = i;
    cities[i].clear();
    cin >> zips[i];
  }
  for (int i = 0; i<m; ++i) {
    int x,y;
    cin >> x >> y;
    cities[x].push_back(y);
    cities[y].push_back(x);
  }
  string best = "9999999999999999999999999999999999999999999999999999999999999999999999999";
  do {
    string s = "";
    for (int i = 1; i<=n; ++i) s += zips[ints[i]];
    if (s < best && possible()) best = s;
  } while(next_permutation(ints+1, ints+n+1));
  cout << best << endl;
}

int main() {
  int c;
  cin >> c;
  for (int i=1; i<=c; ++i) {
    cout << "Case #" << i << ": ";
    solve();
  }
  return 0;
}

