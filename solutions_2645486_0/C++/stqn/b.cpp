#include <algorithm>
#include <cstdio>
#include <set>
#include <utility>
#include <vector>

using namespace std;

int nextInt() { int tmp; scanf("%d", &tmp); return tmp; }

struct activity {
  int timing;
  long long importance;

  activity() {}
  activity(int timing, long long importance)
    : timing(timing), importance(importance) {}
};

class cmp {
public:
  bool operator ()(const activity &a, const activity &b) {
    return a.importance > b.importance ||
      (a.importance == b.importance && a.timing > b.timing);
  }
};

void solve(int casenum)
{
  long long E = nextInt();
  long long R = nextInt();
  int N = nextInt();
  vector<long long> v(N);
  for (int i = 0; i < N; ++i)
    v[i] = nextInt();

  vector<activity> acts(N);
  for (int i = 0; i < N; ++i)
    acts[i] = activity(i, v[i]);
  sort(acts.begin(), acts.end(), cmp());

  long long ans = 0;
  set<pair<int,long long> > s;
  for (int i = 0; i < N; ++i) {
    int timing = acts[i].timing;
    if (i == 0) {
      ans += E * acts[i].importance;
      s.insert(make_pair(timing, E));
    }
    else {
      set<pair<int,long long> >::iterator lb
        = s.lower_bound(make_pair(timing, 0));

      long long rest = 0;
      if (lb != s.end())
        rest = max(rest, lb->second - R * (lb->first - timing));

      long long energy = E;
      if (lb != s.begin()) {
        lb--;
        energy = min(energy, R * (timing - lb->first));
      }

      if (energy > rest) {
        ans += (energy - rest) * acts[i].importance;
        s.insert(make_pair(timing, energy));
      }
    }
  }
  printf("Case #%d: %lld\n", casenum, ans);
}

int main()
{
  int T = nextInt();
  for (int t = 1; t <= T; ++t)
    solve(t);

  return 0;
}
