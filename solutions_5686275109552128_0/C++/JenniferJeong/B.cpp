#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;
int dp[1111];
int go(vector<int> &p) {

  int sz = (int)p.size();
  int maxval = -1;
  int maxidx = 0;
  for (int i = 0; i < sz; i++) {
    if (maxval < p[i]) {
      maxval = p[i];
      maxidx = i;
    }
  }

  int ret = maxval;
  if (ret <= 2) return ret;
  
  vector<int> new_p(p);
  new_p.push_back(0);

  if (dp[maxval] != -1) {
    new_p[maxidx] = p[maxidx] - dp[maxval];
    new_p[sz] = p[maxidx] - new_p[maxidx];
    ret = min(ret, 1 + go(new_p));
  } else {
    for (int i = 2; i <= p[maxidx]/2; i++) {
      new_p[maxidx] = p[maxidx] - i;
      new_p[sz] = p[maxidx] - new_p[maxidx];
      ret = min(ret, 1 + go(new_p));
    }
  }
  return ret;
}

int main() {

  int TC;

  cin >> TC;

  for (int i = 0; i < 1111; i++) {
    dp[i] = -1;
  }

  for(int tc = 1; tc <= TC; tc++) {
    int dish;
    cin >> dish;

    vector<int> pancake;
    for (int i = 0; i < dish; i++) {
      int tmp;
      cin >> tmp;
      pancake.push_back(tmp);
    }

    int result = go(pancake);
    printf("Case #%d: %d\n", tc, result);
  }

  return 0;
}
