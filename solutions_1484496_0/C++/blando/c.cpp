#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <complex>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <cassert>
#include <queue>
#include <cctype>
using namespace std;

typedef long double Real;

const Real o = 1e-8;
const Real pi = acos(-1.0);
const int max_n = 32;

bool ans;
int ans1, ans2;
int n;
int a[max_n];
map<int, int> s;
int T, I;

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i)
    cin >> a[i];
}

void search(int i, int bitmask, int sum) {
  if (i == n) {
    if (s.count(sum)) {
      ans = true;
      ans1 = s[sum];
      ans2 = bitmask;
      assert(ans1 != ans2);
    }
    s[sum] = bitmask;
    return;
  }
  search(i + 1, bitmask, sum);
  if (ans)
    return;
  search(i + 1, bitmask | (1 << i), sum + a[i]);
}

void solve() {
  ans = false;
  s.clear();
  search(0, 0, 0);
}

void output() {
  printf("Case #%d:\n", I + 1);
  if (!ans) {
    printf("Impossible\n");
  } else {
    // fprintf(stderr, "ans1 = %d\nans2 = %d\n", ans1, ans2);
    vector<int> set1, set2;
    for (int i = 0; i < n; ++i) {
      if ((ans1 & (1 << i)) && (ans2 & (1 << i)))
        continue;
      if (ans1 & (1 << i))
        set1.push_back(a[i]);
      if (ans2 & (1 << i))
        set2.push_back(a[i]);
    }
    assert(!set1.empty() && !set2.empty());
    for (size_t i = 0; i < set1.size(); ++i) {
      if (i > 0)
        printf(" ");
      printf("%d", set1[i]);
    }
    printf("\n");
    for (size_t i = 0; i < set2.size(); ++i) {
      if (i > 0)
        printf(" ");
      printf("%d", set2[i]);
    }
    printf("\n");
  }
}

int main() {
  cin >> T;
  for (I = 0; I < T; ++I) {
    input();
    solve();
    output();
  }
	return 0;
}

