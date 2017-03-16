#include <bits/stdc++.h>

using namespace std;

#define MAXN 51

int adj[MAXN][MAXN];
map<long long, int> mm;

void pre() {
  long long x = 1;
  for(int i = 0; i<=50; i++) {
    mm[x] = i;
    x*=2;
  }
}

int getI(long long x) {
  return mm[x]+1;
}

int main() {

  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  pre();

  int t;
  scanf("%d", &t);
  for(int test = 1; test<=t; test++) {
    long long b;
    long long m;
    scanf("%lld %lld", &b, &m);
    long long maximum = 1LL<<(b-2);
    if(maximum >= m) {
      printf("Case #%d: POSSIBLE\n", test);
      for(int i = 0; i<b; i++) {
        for(int j = 0; j<b; j++) {
          adj[i][j] = 0;
        }
      }
      for(int i = 0; i<b; i++) {
        for(int j = i+1; j<b; j++) {
          adj[i][j] = 1;
        }
      }
      long long left = maximum - m;
      if(left > 0) {
        adj[0][b-1] = 0;
        left--;
      }
      while(left) {
        long long x = left&(-left);
        adj[getI(x)][b-1] = 0;
        left -= x;
      }
      for(int i = 0; i<b; i++) {
        for(int j = 0; j<b; j++) {
          printf("%d", adj[i][j]);
        }
        printf("\n");
      }
    }
    else {
      printf("Case #%d: IMPOSSIBLE\n", test);
      continue;
    }
  }

  return 0;
}
