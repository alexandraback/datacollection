#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int N, A, m[100];

int calc (int N) 
{
  int v = A, t = 0;
  for (int i = 0; i <= N; i++) {
    while (v <= m[i]) {
     v += v - 1;
     t ++;
    }
    v += m[i]; 
  }
  return t;
}

int Solve ()
{
  if (A == 1) {
    return N;
  }

  int answer = N;

  for (int i = 0; i < N; i++) {
    if (calc (i) + N - i - 1 < answer) {
      answer = calc (i) + N - i - 1;
    }
  }

  return answer;
}

int main () { 
  freopen ("in.txt", "r", stdin);
  freopen ("ou.txt", "w", stdout);

  int T, t;
  scanf ("%d", &T);
  for (int i = 1; i <= T; i++) {
    scanf ("%d%d", &A, &t);
    N = 0;
    for (int j = 0; j < t; j++) {
      scanf ("%d", m + N);
      if (m[N] < A) {
        A = A + m[N];
      } else {
        N ++;
      }
    }
    sort (m, m + N);
    printf ("Case #%d: %d\n", i, Solve ());
  }
}

