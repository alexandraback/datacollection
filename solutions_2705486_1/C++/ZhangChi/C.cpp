#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;

char dict[600000][20], S[10000];
int F[10000][6], len[600000];
int W, L;

void Init ()
{
  FILE *f;
  f = fopen ("dict.txt", "r");
  W = 0;
  while (fgets (dict[W], 1000, f)) {
    len[W] = strlen (dict[W]) - 1;
    dict[W][len[W]] = '\0';
    W ++;
  }
  fclose (f);
}

void update (int X, int Y)
{
  //printf ("%s\n", dict[Y]);
  //printf ("%s %d\n", S, len[Y]);
  if (len[Y] > X) return;
  int first = -1, last = -1, t = 0;  
  for (int i = 0; i < len[Y]; i++) {
    if (dict[Y][len[Y] - 1 - i] == S[X - 1 - i]) continue;
    if (last > -1 && i - last < 5) {
     return; 
    }
    last = i;
    t ++;
    if (first == -1) first = i;
  }
  if (first == -1) {
    int j;
    for (int i = 0; i < 6; i++) {
      j = i + len[Y];
      if (j > 5) j = 5;
      if (F[X - len[Y]][i] < F[X][j]) {
       F[X][j] = F[X - len[Y]][i]; 
       //printf ("A %d %s first = %d last = %d F[%d][%d] = F[%d][%d] = %d\n", X, dict[Y], first, last, X, j, X - len[Y], i, F[X][j]);
      }
    } 
  } else {
    last = len[Y] - last;
    last = 5 - last;
    if (last < 0) last = 0;
    if (first > 5) first = 5;
    for (int i = last; i < 6; i++) {
      if (F[X - len[Y]][i] + t < F[X][first]) {
        F[X][first] = F[X - len[Y]][i] + t;
       //printf ("B %d %s first = %d last = %d F[%d][%d] = F[%d][%d] + %d = %d\n", X, dict[Y], first, last, X, first, X - len[Y], i, t, F[X][first]);
      }
    }
  }
}

int Solve ()
{
  //update (4, 122757);
  //return 0;
  for (int i = 0; i < 6; i++) F[0][i] = 0;
  L = strlen (S);
  for (int i = 1; i <= L; i++) {
    for (int j = 0; j < 6; j++) F[i][j] = 100000;
    for (int j = 0; j < W; j++) {
      update (i, j);
    } 
    for (int j = 4; j >= 0; j--) {
      if (F[i][j] > F[i][j + 1])
         F[i][j] = F[i][j + 1];
    } 
  }
  int answer = 10000000;
  for (int i = 0; i < 6; i++)
    if (F[L][i] < answer) answer = F[L][i];
  return answer;
}

int main ()
{
  Init ();
  freopen ("in.txt", "r", stdin);
  //freopen ("ou.txt", "w", stdout);
  int T;
  scanf ("%d\n", &T);
  for (int i = 1; i <= T; i++) {
    scanf ("%s\n", S);
    printf ("Case #%d: %d\n", i, Solve());
  }
}

