#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
typedef long long int lli;

vector<pair<int, int> > edges;

int mat[6][6];
int B;
int M;

void traduz(int R) {
  memset(mat, 0, sizeof(mat));
  for(int i = edges.size()-1; i >= 0; i--) {
    if(R%2 == 1) {
      mat[edges[i].first][edges[i].second] = 1;
    }
    R /= 2;
  }
}

int conta(int i = 0) {
  if(i == B-1) return 1;

  int R = 0;
  for(int j = 0; j < B; j++) {
    if(mat[i][j])
      R += conta(j);
  }
  return R;
}

void imprime() {
  printf("POSSIBLE\n");
  for(int i = 0; i < B; i++) {
    for(int j = 0; j < B; j++) {
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
}

int main() {
  int T;

  scanf("%d", &T);

  for(int caso = 1; caso <= T; caso++) {
    scanf("%d %d", &B, &M);

    edges.clear();
    for(int i = 0; i < B; i++) {
      for(int j = i+1; j < B; j++) {
        edges.pb(mp(i, j));
      }
    }

    int R = 1;
    bool possible = false;

    printf("Case #%d: ", caso);

    while(R < (1 << edges.size())) {
      traduz(R);
      if(conta() == M) {
        imprime();
        possible = true;
        break;
      }
      R++;
    }

    if(!possible)
      printf("IMPOSSIBLE\n");
  }

  return 0;
}
