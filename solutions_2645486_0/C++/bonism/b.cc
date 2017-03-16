#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

const int maxn = 10 + 2;//10000 + 10;
const int maxe = 5 + 1;

long long E, R, N, v[maxn], ans;
long long F[maxn][maxe];

void init() {
  cin >> E >> R >> N;
  for (int i = 1; i <= N; ++i)
    scanf("%lld", v+i);  
}

void solve() {
  memset(F, 0, sizeof(F));
  for (int i = 0; i < N; ++i)
    for (int left = 0; left <= E; ++left) {
      int new_left = min(left + R, E);
      for (int x = 0; x <= new_left; ++x) {
        int new_val = F[i][left] + x * v[i + 1];
        if (F[i + 1][new_left - x] < new_val)
          F[i + 1][new_left - x] = new_val;
      }
    }
  ans = 0;
  for (int left = 0; left <= E; ++left)
    ans = max(ans, F[N][left]);
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int tcase = 1; tcase <= T; ++tcase) {
    init();
    solve();
    printf("Case #%d: %lld\n", tcase, ans); 
  }
  return 0;
}
