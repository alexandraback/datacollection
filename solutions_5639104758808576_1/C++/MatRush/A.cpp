#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 111111;

string s;

int main() {
  int cases;
  scanf("%d", &cases);
  for (int T = 1; T <= cases; ++T) {
    int n;
    string s;
    cin >> n >> s;

    long long ans = 0, cnt = 0;
    for (int i = 0; i <= n; ++i) {
      if (s[i] != '0') {
        if (cnt < i) {
          ans += i - cnt;
          cnt = i;
        }
        cnt += (s[i] - '0');
      }
      // printf("%d %d\n", cnt, ans);
    }

    printf("Case #%d: %lld\n", T, ans);
  }
}