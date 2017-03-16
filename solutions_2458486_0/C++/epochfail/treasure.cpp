#include <cstdio>
#include <cstring>
#include <map>
using namespace std;

int n;
int start[45];
int needs[25];
int gives[25][45];

int seen[1 << 25];
int next[1 << 25];

bool f(int visited) {
  if (__builtin_popcount(visited) == n)
    return true;
  if (seen[visited])
    return seen[visited] == 1;

  // Count the keys.
  int keys[45] = {};
  for (int i = 0; i < 45; i++) {
    keys[i] = start[i];
    for (int k = 0; k < 25; k++)
      if (visited & (1 << k))
        keys[i] += gives[k][i];
  }
  for (int i = 0; i < 25; i++)
    if (visited & (1 << i))
      keys[needs[i]]--;

  // Go.
  for (int i = 0; i < n; i++) {
    if (visited & (1 << i)) continue;
    if (keys[needs[i]] == 0) continue;

    if (f(visited | (1 << i))) {
      seen[visited] = 1;
      next[visited] = i;
      return true;
    }
  }

  seen[visited] = 2;
  return false;
}

map<int, int> conv;
int convert(int x) {
  if (conv.find(x) == conv.end())
    conv[x] = conv.size();
  return conv[x];
}

void solve() {
  memset(start, 0, sizeof(start));
  memset(needs, 0, sizeof(needs));
  memset(gives, 0, sizeof(gives));
  memset(seen, 0, sizeof(seen));
  conv.clear();

  int startkeys;
  scanf("%d %d\n", &startkeys, &n);
  for (int i = 0; i < startkeys; i++) {
    int a;
    scanf("%d", &a);
    a = convert(a);
    start[a]++;
  }

  for (int i = 0; i < n; i++) {
    int ntypes;
    scanf("%d %d ", &needs[i], &ntypes);
    needs[i] = convert(needs[i]);
    for (int k = 0; k < ntypes; k++) {
      int a;
      scanf("%d ", &a);
      a = convert(a);
      gives[i][a]++;
    }
  }

  bool ans = f(0);
  if (ans) {
    int at = 0;
    for (int i = 0; i < n; i++) {
      printf(" %d", next[at]+1);
      at |= 1 << next[at];
    }
    printf("\n");
  } else {
    printf(" IMPOSSIBLE\n");
  }
}

int main() {
  int n;
  scanf("%d ", &n);
  for (int i = 0; i < n; i++) {
    printf("Case #%d:", i+1);
    solve();
  }

  return 0;
}
