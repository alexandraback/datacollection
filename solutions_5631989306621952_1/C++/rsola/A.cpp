#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1005;
const int M = 1000000007;

char s[N];

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    scanf("%s", s);
    string ans; ans.push_back(s[0]);
    for (int i = 1; s[i]; i++) {
      if (s[i] >= ans[0]) { ans.insert(0, 1, s[i]); }
      else { ans.push_back(s[i]); }
    }
    printf("Case #%d: %s\n", C, ans.c_str());
  }
}
