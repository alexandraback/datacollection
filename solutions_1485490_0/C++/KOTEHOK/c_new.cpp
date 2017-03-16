#include <cstdio>
#include <algorithm>

using namespace std;

long long D[200][200];
long long A[200], B[200];
int at[200], bt[200];
int N, M;

void match_chain2 (int i, int j, long long cur, long long cap);
 
void match_chain1 (int i, int j, long long cur, long long cap) {
  //  printf ("mc1 %d %d %lld %lld\n", i, j, cur, cap);
  long long left = cap;
  for (int k = i; k < N; k++) {
    if (at[k] == bt[j]) {
      left -= A[k];
      long long cleft = left;
      if (cleft < 0) cleft = 0;
      D[k + 1][j + 1] = max (D[k + 1][j + 1], cur + cap - cleft);
      if (left < 0) {
	match_chain2 (k, j + 1, cur + cap, -left);
	break;
      }
    } else {
      D[k + 1][j + 1] = max (D[k + 1][j + 1], cur + cap - left);
    }
  }
}


void match_chain2 (int i, int j, long long cur, long long cap) {
  //  printf ("mc2 %d %d %lld %lld\n", i, j, cur, cap);
  long long left = cap;
  for (int k = j; k < M; k++) {
    if (bt[k] == at[i]) {
      left -= B[k];
      long long cleft = left;
      if (cleft < 0) cleft = 0;
      D[i + 1][k + 1] = max (D[i + 1][k + 1], cur + cap - cleft);
      if (left < 0) {
	match_chain1 (i + 1, k, cur + cap, -left);
	break;
      }
    } else {
      D[i + 1][k + 1] = max (D[i + 1][k + 1], cur + cap - left);
    }
  }
}

int main () {
  int tc;
  scanf ("%d", &tc);
  for (int tn = 1; tn <= tc; tn++) {
    scanf ("%d%d", &N, &M);
    for (int j = 0; j < N; j++)
      scanf ("%lld%d", &A[j], &at[j]);
    for (int j = 0; j < M; j++)
      scanf ("%lld%d", &B[j], &bt[j]);
    for (int i = 0; i <= N; i++)
      for (int j = 0; j <= M; j++)
	D[i][j] = 0;
    for (int i = 0; i < N; i++)
      for (int j = 0; j < M; j++) {
	D[i + 1][j] = max (D[i + 1][j], D[i][j]);
	D[i][j + 1] = max (D[i][j + 1], D[i][j]);
	if (at[i] == bt[j]) {
	  match_chain1 (i, j, D[i][j], B[j]);
	  match_chain2 (i, j, D[i][j], A[i]);
	}
      }
    long long res = 0;
    for (int i = 0; i <= N; i++) res = max (res, D[i][M]);
    for (int i = 0; i <= M; i++) res = max (res, D[N][i]);
    printf ("Case #%d: %lld\n", tn, res);
  }
  return 0;
}
