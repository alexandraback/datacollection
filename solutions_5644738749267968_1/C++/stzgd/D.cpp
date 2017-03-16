#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using std::vector;

int n;

int DeceitfulWar(vector<double> naomi, vector<double> ken) {
  int ret = 0;
  while (!naomi.empty()) {
    if (naomi[0] > ken[0]) {
      ++ret;
      naomi.erase(naomi.begin());
      ken.erase(ken.begin());
    } else {
      naomi.erase(naomi.begin());
      ken.pop_back();
    }
  }
  return ret;
}

int War(vector<double> naomi, vector<double> ken) {
  int ret = 0;
  while (!naomi.empty()) {
    auto iter = std::lower_bound(ken.begin(), ken.end(), naomi[0]);
    if (iter == ken.end()) {
      ken.erase(ken.begin());
      ++ret;
    } else {
      ken.erase(iter);
    }
    naomi.erase(naomi.begin());
  }
  return ret;
}

int RevWar(vector<double> naomi, vector<double> ken) {
  int ret = 0;
  while (!naomi.empty()) {
    auto iter = std::lower_bound(ken.begin(), ken.end(), naomi.back());
    if (iter == ken.end()) {
      ken.erase(ken.begin());
      ++ret;
    } else {
      ken.erase(iter);
    }
    naomi.pop_back();
  }
  return ret;
}

void Work() {
  assert(scanf("%d", &n) == 1);
  vector<double> naomi, ken;
  for (int i = 0; i < n; ++i) {
    double t;
    assert(scanf("%lf", &t) == 1);
    naomi.push_back(t);
  }
  for (int i = 0; i < n; ++i) {
    double t;
    assert(scanf("%lf", &t) == 1);
    ken.push_back(t);
  }
  std::sort(naomi.begin(), naomi.end());
  std::sort(ken.begin(), ken.end());
  if (War(naomi, ken) != RevWar(naomi, ken)) fprintf(stderr, "Wrong\n");
  printf("%d %d\n", DeceitfulWar(naomi, ken), std::max(War(naomi, ken), RevWar(naomi, ken)));
}

int main() {
  int cases;
  assert(scanf("%d", &cases) == 1);
  for (int i = 1; i <= cases; ++i) {
    printf("Case #%d: ", i);
    Work();
  }
  return 0;
}
