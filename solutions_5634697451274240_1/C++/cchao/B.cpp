#include <bits/stdc++.h>
using namespace std;

int toi(char s[]) {
  int r = 0;
  for(int i = 0; s[i]; ++i)
    r = (r << 1) + (s[i] == '+');
  return r;
}

void tos(int x, int n, char s[]) {
  for(int i = n - 1; i >= 0; --i) {
    s[i] = (x & 1) ? '+' : '-';
    x >>= 1;
  }
}

int bf(char s[]) {
  int d[5566] = {};
  char t[5566] = {};
  d[toi(s)] = 1;
  const int n = strlen(s);
  queue<int> q;
  q.push(toi(s));
  while(q.size()) {
    int x = q.front(); q.pop();
    tos(x, n, t);
    for(int i = 0; i < n; ++i) {
      t[i] = t[i] == '+' ? '-' : '+';
      int tmp = toi(t);
      if(!d[tmp]) {
        d[tmp] = d[x] + 1;
        q.push(tmp);
      }
    }
  }
  return d[(1 << n) - 1] - 1;
}

int main() {
  int T = 2048;
  char s[5566] = {};
  scanf("%d", &T);
  for(int kase = 1; kase <= T; ++kase) {
    // tos(kase - 1, 11, s);
    scanf("%s", s);
    printf("Case #%d: ", kase);
    const int N = strlen(s);
    int answer = 0;
    bool flip = false;
    for(int i = N - 1; i >= 0; --i) {
      if((s[i] == '-') != flip) {
        flip = !flip;
        answer++;
      }
    }
    // assert(answer == bf(s));
    // printf("-- %d ", bf(s));
    printf("%d\n", answer);
  }
  return 0;
}
