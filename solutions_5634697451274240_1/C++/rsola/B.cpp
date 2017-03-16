#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 105;

char s[N];

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    scanf("%s", s);
    int ans = s[strlen(s) - 1] == '-';
    for (int i = 1; s[i]; i++) {
      if (s[i] != s[i - 1]) { ans++; }
    }
    printf("Case #%d: %d\n", C, ans);
  }
}
