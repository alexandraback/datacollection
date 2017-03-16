#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>

using namespace std;

#define LOG(x) cerr << #x << " = " << (x) << "\n"

typedef long long llint;
typedef pair<int,int> pii;

int bio[(int)1e6 + 10];

void prep() {
  queue<int> q;
  q.push(1);
  memset(bio, 0, sizeof bio);
  bio[1] = 1;

  while (q.size()) {
    int t = q.front(); q.pop();
    if (t + 1 < 1e6 + 1 && bio[t+1] == 0) {
      q.push(t+1);
      bio[t+1] = bio[t] + 1;
    }
    int old = t;
    string s = to_string(t);
    reverse(s.begin(), s.end());
    sscanf(s.c_str(), "%d", &t);
    if (bio[t] == 0) {
      q.push(t);
      bio[t] = bio[old] + 1;
    }
  }
}

void solve() {
  int n;
  scanf("%d", &n);

  int ans = 0;
  ans = bio[n];
  printf("%d\n", ans);
}

int main() {
  prep();
  int t; scanf("%d", &t);
  for (int i = 0; i < t; ++i) {
    printf("Case #%d: ", i+1);
    solve();
  }
  return 0;
}

