#include <cstdio>
#include <algorithm>
#include <vector>
#include <list>
#include <utility>

using namespace std;

void make(){
  int e, r, n;
  scanf("%d%d%d", &e, &r, &n);
  vector<int> values(n);
  vector<pair<int, int> > acts(n);
  for (int i = 0; i < n; ++i) {
    acts[i].second = i;
    scanf("%d", &acts[i].first);
    values[i] = acts[i].first;
  }
  sort(acts.begin(), acts.end(), greater<pair<int, int> >());
  vector<int> reqs(n, 0);
  vector<int> ress(n, -1);
  for (auto& act : acts) {
    int start;
    if (ress[act.second] >= 0) {
      start = ress[act.second];
    } else {
      start = e;
    }
    for (int t = 1; act.second - t >= 0 && start-r*t >= 0; ++t) {
      if (start-r*t > reqs[act.second-t]) {
	reqs[act.second-t] = start-r*t;
      }
    }
    for (int s = 0; act.second+s < n && reqs[act.second] + r*s < e; ++s) {
      if (ress[act.second+s] < 0 ||
	  reqs[act.second] + r*s < ress[act.second+s]) {
	ress[act.second+s] = reqs[act.second] + r*s;
      }
    }

    /*
  for (int i = 0; i < n; ++i) {
    printf("%d ", reqs[i]);
  }
  printf("\n");
  for (int i = 0; i < n; ++i) {
    printf("%d ", ress[i]);
  }
  printf("\n");*/
    
  }

  
  
  long long ans = values[0]*static_cast<long long>(e - reqs[0]);
  for (int i = 1; i < n; ++i) {
    ans += values[i]*static_cast<long long>(reqs[i-1] + r - reqs[i]);
  }
  printf("%lld\n", ans);
}

int main(){
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  
  int test_n;
  scanf("%d", &test_n);
  for (int test_i = 1; test_i <= test_n; ++test_i) {
    printf("Case #%d: ", test_i);
    make();
  }
  return 0;
}
