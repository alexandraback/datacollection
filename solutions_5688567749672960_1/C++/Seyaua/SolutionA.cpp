#include <iostream>
#include <cstdio>
#include <set>
#include <map>
#include <string>
#include <cstring>
#include <vector>
#include <queue>
#include <bitset>
#include <cmath>
#include <ctime>
#pragma comment(linker, "/STACK:256000000")

using namespace std;

const int maxN = 11000000;
int res[maxN];
int hs[maxN];

long long rever(long long x) {
  long long res = 0;
  while (x > 0) {
    long long nw = x % 10LL;
    res *= 10;
    res += nw;
    x /= 10;
  }
  return res;
}

long long mylen(long long x) {
  long long ret = 0;
  while (x > 0) {
    ++ret;
    x /= 10;
  }
  return ret;
}

long long get_mod(long long x) {
  long long cur = mylen(x);
  cur /= 2;
  long long ret = 1LL;
  for (int i = 0; i < cur; ++i) {
    ret *= 10LL;
  }
  return ret;
}

void solve2(int tcase) {
  printf("Case #%d: ", tcase);
  int n;
  scanf("%d", &n);
  cout << res[n] << endl;
}

long long get_res(long long value) {
  long long ret = 1;
  while (value != 1) {
    if (value <= rever(value)) {
      --value;
      ++ret;
      continue;
    }
    long long cur = get_mod(value);
    long long rem = value % cur;
    if (rem == 1) {
      if (rever(value) < value) {
        value = rever(value);
        ++ret;
        continue;
      } else {
        --value;
        ++ret;
        continue;
      }
    }
    if (rem == 0) {
      --value;
      ++ret;
      continue;
    }
    ret += rem - 1;
    value -= rem;
    ++value;
  }
  return ret;
}

void solve(int tcase) {
  printf("Case #%d: ", tcase);
  long long x;
  cin >> x;
  cout << get_res(x) << endl;
}

void print_his(int value) {
  int pr_value = -1;
  while (true) {
    cout << value << endl;
    pr_value = value;
    value = hs[value];
    if (value == -1) {
      break;
    }
  }
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  //cout << get_res(21) << endl;

  //cout << get_res(102101) << endl;

  int t;
  scanf("%d", &t);

  /*memset(res, -1, sizeof(res));
  queue<int> q;
  q.push(1);
  res[1] = 1;
  hs[1] = -1;

  int cnt = 0;
  while (!q.empty()) {
    ++cnt;
    if (cnt % 1000000 == 0) cerr << cnt << endl;
    int cur = q.front();
    q.pop();
    vector<int> v;
    v.push_back(cur + 1);
    v.push_back(rever(cur));
    for (int i = 0; i < v.size(); ++i) {
      int val = v[i];
      if (val >= maxN || res[val] != -1) {
        continue;
      }
      res[val] = res[cur] + 1;
      hs[val] = cur;
      q.push(val);
    }
  }*/

  /*for (int i = 1; i <= 1000000; ++i) {
    if (i % 1000 == 0) cerr << i << endl;
    int v1 = res[i];
    int v2 = get_res(i);
    //cerr << i << endl;
    if (v1 != v2) {
      cerr << i << endl;
      cerr << v1 << endl;
      cerr << v2 << endl;
      print_his(i);
      return 0;
    }
  }*/

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}
