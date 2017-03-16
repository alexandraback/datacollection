#include<bits/stdc++.h>

#define pb push_back

using namespace std;

int jp[10][10], js[10][10], ps[10][10];

typedef struct tripla{
  int j, p, s;
} tripla;

vector<tripla> sol;

int main() {
  int T;
  int J, P, S, K;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d %d %d", &J, &P, &S, &K);

    memset(jp, 0, sizeof(jp));
    memset(js, 0, sizeof(js));
    memset(ps, 0, sizeof(ps));
    sol.clear();
    tripla t;

    int R = 0;
    for(int i = 0; i < J; i++) {
      for(int j = 0; j < P; j++) {
        for(int k = 0; k < S; k++) {
          if(jp[i][j] < K && js[i][k] < K && ps[j][k] < K) {
            t.j = i+1;
            t.p = j+1;
            t.s = k+1;
            sol.pb(t);
            jp[i][j]++;
            js[i][k]++;
            ps[j][k]++;
            R++;
          }
        }
      }
    }
    printf("Case #%d: %d\n", caso, R);
    for(int i = 0; i < sol.size(); i++) {
      printf("%d %d %d\n", sol[i].j, sol[i].p, sol[i].s);
    }
  }

  return 0;
}
