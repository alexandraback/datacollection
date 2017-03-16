#include <cstdio>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;

void solve(int tc) {
  ll cost;
  ll armin;
  ll N;
  scanf("%lld %lld", &armin, &N);
  vector<ll> motes(N);
  vector<ll> growth_cost(N,0);
  for (int i = 0; i < N; ++i)
    scanf("%lld", &motes[i]);

  sort(motes.begin(), motes.end());

  cost = N; /* worst case, remove every mote */

  /* armin can only eat if he's larger than one */
  if (armin > 1) {
    for (size_t i = 0; i < motes.size(); ++i) {
      if (i > 0)
        growth_cost[i] = growth_cost[i-1];

      /* grow armin til he's larger */
      while (armin <= motes[i]) {
        armin += armin - 1;
        growth_cost[i]++;
      }
      /* we can eat the mote */
      armin += motes[i];

      cost = min(cost, growth_cost[i] + (ll)(motes.size() - i - 1));
    }
  }

  printf("Case #%d: %lld\n", tc, cost);
}

int main() {
  int N;
  scanf("%d\n", &N);
  for (int tc = 1; tc <= N; ++tc)
    solve(tc);
  return 0;
}
