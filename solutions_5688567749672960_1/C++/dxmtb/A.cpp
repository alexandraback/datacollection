#include <cstdio>
#include <cassert>
#include <vector>
#include <algorithm>
using namespace std;

bool special(const vector<int> &n) {
  assert(n[0] > 0);
  if (n.back() != 1)
    return false;
  if (n.size() == 1)
    return n[0] == 1;
  if (n.size() <= 3) {
    if (n[0] == 1)
      return false;
    if (n.size() == 3 && n[1] != 0)
      return false;
    return true;
  }
  int non_zeros = n.size() / 2;
  int zeros = n.size() - 1 - non_zeros;
  for (int i = non_zeros; i < non_zeros + zeros; i++)
    if (n[i] != 0)
      return false;
  if (n[0] > 1)
    return true;
  for (int i = 1; i < non_zeros; i++)
    if (n[i] > 0)
      return true;
  return false;
}

void dec(vector<int> &n) {
  // minus 1
  bool flag = false;
  for (int i = n.size() - 1; i >= 0; i--) {
    if (n[i] == 0)
      n[i] = 9;
    else {
      n[i] -= 1;
      flag = true;
      break;
    }
  }
  while(n.front() == 0)
    n.erase(n.begin());
  assert(flag);
}

long long nearest_special(vector<int> &n) {
  long long ret = 0;
  while (true) {
    if (n.back() == 0) {
      ret += 1;
      dec(n);
    }
    if (n.size() == 1)
      return ret;
    int non_zeros = n.size() / 2;
    int zeros = n.size() - 1 - non_zeros;
    ret += n.back() - 1;
    n[n.size()-1] = 1;
    long long now = 0;
    for (int i = non_zeros; i < non_zeros + zeros; i++) {
      now = now * 10 + n[i];
      n[i] = 0;
    }
    now *= 10;
    ret += now;
    if (!special(n)) {
      dec(n);
      dec(n);
      ret += 2;
    }
    if (n.size() == 1 || special(n))
      break;
  }
  return ret;
}

long long getans(vector<int> n) {
  assert(n.size());
  long long ans = 0;
  while (n.size() > 1) {
    if (special(n)) {
      reverse(n.begin(), n.end());
      ans += 1;
    } else {
      ans += nearest_special(n);
    }
  }
  return ans + n[0];
}

void solve() {
  char s[20];
  scanf("%s", s);
  int len = strlen(s);
  vector<int> start;
  for (int i = 0; i < len; i++) {
    assert(s[i] >= '0' && s[i] <= '9');
    start.push_back(s[i] - '0');
  }
  long long ans = getans(start);
  printf("%lld\n", ans);
}

int main() {
  int T;
  scanf("%d", &T);
  for (int i = 1; i <= T; i++) {
    printf("Case #%d: ", i);
    solve();
  }
}
