#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

char s[N];

void solve(char *s) {
  int n = strlen(s);
  deque<char> q;
  for (int i = 0; i < n; ++i) {
    if (q.empty() || q.front() <= s[i]) {
      q.push_front(s[i]);
    }
    else {
      q.push_back(s[i]);
    }
  }
  for (int i = 0; i < q.size(); ++i) {
    putchar(q[i]);
  }
  putchar('\n');
}

int main() {
  int t;
  scanf("%d", &t);
  for (int _ = 1; _ <= t; ++_) {
    scanf("%s", s);
    printf("Case #%d: ", _);
    solve(s);
  }
  return 0;
}
