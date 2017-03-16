// :)
#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

map<string, int> F, S;
pair<string, string> arr[20];
vector<int> h[20], g[20], l[20];
bool b[20];

bool isCyclicUtil(int v, bool visited[], bool* recStack) {
  if (visited[v] == false) {
    visited[v] = true;
    recStack[v] = true;
    vector<int>::iterator i;
    for (i = g[v].begin(); i != g[v].end(); ++i) {
      if (!visited[*i] && isCyclicUtil(*i, visited, recStack))
        return true;
      else if (recStack[*i])
        return true;
    }
  }
  recStack[v] = false;
  return false;
}

bool isCyclic(int n) {
  bool* visited = new bool[n];
  bool* recStack = new bool[n];
  for (int i = 0; i < n; i++) {
    visited[i] = false;
    recStack[i] = false;
  }
  for (int i = 0; i < n; i++)
    if (isCyclicUtil(i, visited, recStack))
      return true;
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  freopen("/Users/Ayur/Downloads/C-small-attempt2.in.txt", "r", stdin);
  freopen("/Users/Ayur/Downloads/C-small-2.txt", "w", stdout);
  int t, tt, i, j, k, n, a;
  string p, q;
  cin >> tt;
  for (t = 1; t <= tt; t++) {
    cout << "Case #" << t << ": ";
    F.clear();
    S.clear();
    cin >> n;
    for (i = 0; i < n; i++) {
      b[i] = false;
      g[i].clear();
      l[i].clear();
    }
    for (i = 0; i < n; i++) {
      cin >> p >> q;
      F[p]++;
      S[q]++;
      arr[i] = {p, q};
    }
    for (i = 0; i < n; i++) {
      p = arr[i].first;
      q = arr[i].second;
      if (F[p] >= 2 && S[q] >= 2)
        b[i] = true;
      else
        continue;
      for (j = 0; j < n; j++) {
        if (i == j)
          continue;
        if (arr[j].first == p || arr[j].second == q) {
          h[j].push_back(i);
          l[i].push_back(j);
        }
      }
    }
    /*int c = 0;
    for (i = 0; i < n; i++)
      if (b[i])
        c++;
    cout << c << '\n';*/
    a = 0;
    for (i = 0; i < (1 << n); i++) {
      if (n - __builtin_popcount(i) <= a)
        continue;
      for (j = 0; j < n; j++)
        g[j].clear();
      for (j = 0; j < n; j++) {
        if ((i & (1 << j)) == 0 && !b[j])
          break;
        if ((i & (1 << j)))
          g[j] = h[j];
      }
      if (j < n)
        continue;
      if (!isCyclic(n))
        a = max(a, n - __builtin_popcount(i));
    }

    cout << a << '\n';
  }
  return 0;
}