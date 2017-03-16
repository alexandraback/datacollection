#include <cstdio>
#include <cstring>
#include <iostream>
#include <set>
#include <vector>
using namespace std;

const int maxn = 10000 + 10;

long long E, R, N, v[maxn];
long long Req[maxn], Left[maxn], ans; 
set<int> vis, vis_neg;
vector<pair<int, int> > ord;

void init() {
  cin >> E >> R >> N;
  for (int i = 1; i <= N; ++i)
    scanf("%lld", v+i);  
}

void solve() {
  ord.clear();
  for (int i = 1; i<= N; ++i)
    ord.push_back(make_pair(-v[i], i));
  sort(ord.begin(), ord.end());

  ans = 0;
  vis.clear();
  vis.insert(0);
  vis.insert(N + 1);
  vis_neg.clear();
  vis_neg.insert(0);
  vis_neg.insert(-(N + 1));
  Left[0] = E;
  Req[N + 1] = 0;
  for (int ptr = 0; ptr < N; ++ptr) {
    int cur = ord[ptr].second;
    int prev = - *(vis_neg.upper_bound(-cur));
    int succ = *(vis.upper_bound(cur));
    Req[cur] = min(E, Left[prev] + R * (cur - prev));
    Left[cur] = max(0LL, Req[succ] - R * (succ - cur));
    ans += (Req[cur] - Left[cur]) * v[cur];
    vis.insert(cur);
    vis_neg.insert(-cur);
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("log.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tcase = 1; tcase <= T; ++tcase) {
    init();
    solve();
    printf("Case #%d: %lld\n", tcase, ans); 
  }
  return 0;
}
