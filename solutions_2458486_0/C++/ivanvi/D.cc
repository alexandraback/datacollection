#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

#define MAX 20
#define MAX_KEYS 45

#define POW2(a) ((1) << (a))
#define BIT(a, b) (((a) >> (b)) & (1))

void input(void);
void solve(void);
int possible(int mask);

int n, m;
vector <int> start_keys;
int type[MAX];
vector <int> keys[MAX];
int cache[POW2(MAX)];
int case_cnt = 1;

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    input();
    solve();
  }
  return 0;
}

void input(void) {
  scanf("%d %d", &m, &n);
  start_keys.clear();
  for (int i = 0; i < m; i++) {
    int k;
    scanf("%d", &k);
    start_keys.push_back(k);
  }
  for (int i = 0; i < n; i++) {
    int t, k;
    scanf("%d %d", &t, &k);
    type[i] = t;
    keys[i].clear();
    for (int j = 0; j < k; j++) {
      int v;
      scanf("%d", &v);
      keys[i].push_back(v);
    }
  }
}

void solve(void) {
  memset(cache, -1, sizeof(cache));

  if (!possible(0)) {
    printf("Case #%d: IMPOSSIBLE\n", case_cnt++);
    return;
  }

  int mask = 0;
  int freq[MAX_KEYS];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < start_keys.size(); i++) freq[start_keys[i]]++;

  vector <int> res;
  while (mask != POW2(n) - 1) {
    for (int i = 0; i < n; i++) {
      if (BIT(mask, i) == 1) continue;
      if (freq[type[i]] <= 0) continue;
      if (!possible(mask | POW2(i))) continue;
      res.push_back(i + 1);
      mask |= POW2(i);
      freq[type[i]]--;
      for (int j = 0; j < keys[i].size(); j++) freq[keys[i][j]]++;
      break;
    }
  }

  printf("Case #%d: ", case_cnt++);
  for (int i = 0; i < res.size(); i++) {
    printf("%d%c", res[i], (i + 1 == res.size() ? '\n' : ' '));
  }
}

int possible(int mask) {
  if (mask == POW2(n) - 1) return 1;
  if (cache[mask] != -1)   return cache[mask];

  int freq[MAX_KEYS];
  memset(freq, 0, sizeof(freq));
  for (int i = 0; i < start_keys.size(); i++) freq[start_keys[i]]++;
  
  for (int i = 0; i < n; i++) {
    if (!BIT(mask, i)) continue;
    freq[type[i]]--;
    for (int j = 0; j < keys[i].size(); j++) freq[keys[i][j]]++;
  }


  int res = 0;
  for (int i = 0; i < n; i++) {
    if (BIT(mask, i) == 1) continue;
    if (freq[type[i]] <= 0) continue;
    if (possible(mask | POW2(i))) {
      res = 1;
      break;
    }
  }

  return cache[mask] = res;
}

