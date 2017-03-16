#include <stdio.h>
#include <vector>
#include <queue>

#define MAXN 1000002

using namespace std;

typedef pair<int, int> pii;

int reverse(int a) {
  int orig = a;
  int rev = 0;
  while (a) {
    rev *= 10;
    rev += (a % 10);
    a /= 10;
  }
  //printf("reverse of %d is %d\n", orig, rev);
  return rev;
}

int main() {
  int T;
  scanf("%d", &T);
  for (int ncase = 0; ncase < T; ncase++) {
    int N;
    scanf("%d", &N);
    bool tab[MAXN];
    for (int i = 0; i < MAXN; i++)
      tab[i] = false;
    queue<pii> q;
    q.push(make_pair(1, 1));
    int ans = -1;
    while (!q.empty()) {
      pii p = q.front();
      q.pop();
      //printf("pop %d %d\n", p.first, p.second);
      if (tab[p.first])
        continue;
      //printf("continue\n");
      tab[p.first] = true;
      if (p.first == N) {
        //printf("got %d\n", N);
        ans = p.second;
        break;
      }
      q.push(make_pair(p.first+1, p.second+1));
      q.push(make_pair(reverse(p.first), p.second+1));
    }
    printf("Case #%d: %d\n", ncase + 1, ans);
  }
  return 0;
}
