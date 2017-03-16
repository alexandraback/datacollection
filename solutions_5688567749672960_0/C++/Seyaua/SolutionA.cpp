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

int rever(int x) {
  int res = 0;
  while (x > 0) {
    int nw = x % 10;
    res *= 10;
    res += nw;
    x /= 10;
  }
  return res;
}

void solve(int tcase) {
  printf("Case #%d: ", tcase);
  int n;
  scanf("%d", &n);
  cout << res[n] << endl;
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  int t;
  scanf("%d", &t);

  memset(res, -1, sizeof(res));
  queue<int> q;
  q.push(1);
  res[1] = 1;

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
      q.push(val);
    }
  }

  for (int i = 0; i < t; ++i) {
    solve(i + 1);
  }
  return 0;
}
