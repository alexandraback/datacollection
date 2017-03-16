#include <bits/stdc++.h>

#define llong unsigned long long

#define pii pair<int, int>

#define pb push_back
#define mp make_pair

#define f first
#define s second

using namespace std;

typedef vector<int> big;

const double eps = 1e-11;

const int MAXN = (int) 2e6 + 7;
const int INF = (int) 1e9 + 7;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {1, -1, 0, 0};

int d[MAXN];

int rev(int x) {
  int res = 0;
  while (x) {
    res = res * 10 + x % 10;
    x /= 10;
  }
  return res;
}

int main() {  
  #ifdef LOCAL
  freopen("in", "r", stdin);
  freopen("out", "w", stdout);
  #endif
  
  d[1] = 1;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int v = q.front();
    q.pop();
    if (v + 1 < MAXN && !d[v + 1]) {
      d[v + 1] = d[v] + 1;
      q.push(v + 1);
    }
    int nxt = rev(v);
    if (nxt < MAXN && !d[nxt]) {
      d[nxt] = d[v] + 1;
      q.push(nxt);
    }
  }
  
  int t;
  scanf("%d", &t);
  for (int cases = 1; cases <= t; cases++) {
    int from;
    scanf("%d", &from);
    printf("Case #%d: %d\n", cases, d[from]);
  }

  return 0;
}