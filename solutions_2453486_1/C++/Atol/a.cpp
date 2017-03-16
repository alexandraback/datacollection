#include<algorithm>
#include<cstring>
#include<cstdio>

using namespace std;

#define N 128
char tab[N][N];

int okLinhaOuCol(char c) {
  for(int linha = 0; linha < 4; linha++) {
    int cnt1 = 0, cnt2 = 0;
    for(int col = 0; col < 4; col++) {
      if(tab[linha][col] == c || tab[linha][col] == 'T') cnt1++;
      if(tab[col][linha] == c || tab[col][linha] == 'T') cnt2++;
    }
    if(cnt1 == 4 || cnt2 == 4) return 1;
  }
  return 0;
}

int okDiag(char c) {
  int cnt1 = 0, cnt2 = 0;
  for(int i = 0, j = 3; i < 4; i++, j--) {
    if(tab[i][i] == c || tab[i][i] == 'T') cnt1++;
    if(tab[i][j] == c || tab[i][j] == 'T') cnt2++;
  }
  if(cnt1 == 4 || cnt2 == 4) return 1;
  return 0;
}

int ok(char c) {
  if (okLinhaOuCol(c)) return 1;
  if (okDiag(c)) return 1;
  return 0;
}

int has(char c) {
  for(int i = 0; i < 4; i++) for(int j = 0; j < 4; j++)
    if(tab[i][j] == c) return 1;
  return 0;
}

void solve() {
  for(int i = 0; i < 4; i++) {
    scanf("%s", tab[i]);
  }
  if(ok('X')) printf("X won\n");
  else if(ok('O')) printf("O won\n");
  else if(!has('.')) printf("Draw\n");
  else printf("Game has not completed\n");
}

int main() {
  int num_testes;
  scanf("%d", &num_testes);
  for(int t = 1; t <= num_testes; t++) {
    printf("Case #%d: ", t);
    solve();
  }
  return 0;
}
