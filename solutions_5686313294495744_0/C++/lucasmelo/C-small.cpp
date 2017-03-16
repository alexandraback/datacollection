#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define in(a,b) ( (b).find(a) != (b).end())

int m;
map<string, int> idx1;
map<string, int> idx2;
int n1, n2;

#define MAX 17
vector<int> adj[MAX];
int cnt1[MAX];
int cnt2[MAX];

int edge[MAX][2];

bool ok(int msk) {
  memset(cnt1, 0, sizeof(cnt1));
  memset(cnt2, 0, sizeof(cnt2));
  for (int i = 0; i < m; ++i) {
    if (!((1 << i) & msk)) {
      ++cnt1[edge[i][0]];
      ++cnt2[edge[i][1]];
    }
  }

  for (int i = 0; i < n1; ++i) {
    if (cnt1[i] == 0) return false;
  }
  for (int i = 0; i < n2; ++i) {
    if (cnt2[i] == 0) return false;
  }
  return true;
}

int main() {
  ios::sync_with_stdio(0);
  int t;
  cin >> t;
  for (int cn = 1; cn <= t; cn++) {
    n1 = n2 = 0;

    cin >> m;
    for (int i = 0; i < m; ++i) {
      string a, b;
      cin >> a >> b;
      if (!in(a, idx1)) {
        idx1[a] = n1++;
      }
      if (!in(b, idx2)) {
        idx2[b] = n2++;
      }
      edge[i][0] = idx1[a];
      edge[i][1] = idx2[b];
    }

    int mx = 0;
    for (int i = 1; i < (1 << m); ++i) {
      if (ok(i)) {
        mx = max(mx, __builtin_popcount(i));
      }
    }

    printf("Case #%d: %d\n", cn, mx);
    idx1.clear();
    idx2.clear();
  }
  return 0;
}
