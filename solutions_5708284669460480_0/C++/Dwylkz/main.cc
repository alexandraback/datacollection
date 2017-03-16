#include <cstdio>
#include <iostream>

using namespace std;

const int N = 1e2+5;
const int C = 26;

void Kmp(char s[], int n, int p[])
{
  int i = 1, j = -1;
  p[0] = -1;
  while (i < n)
    if (s[i] == s[j+1]) {
      p[i++] = ++j;
    } else if (j != -1) {
      j = p[j];
    } else {
      p[i++] = j;
    }
  // for (int i = 0; i < n; i++) printf("%d%c", p[i], i < n-1? ' ': '\n');
}

int Next(char s[], int n, int p[], int i, int c)
{
  while (i != -1 && s[i+1] != c) i = p[i];
  if (s[i+1] == c) i++;
  return i;
}

int Max(int m, int p[], int n)
{
  if (p[n-1] == -1) return m/n;
  int head = n-1-p[n-1], tail = n-head;
  return (m-tail)/head;
}

bool Check(int x[], int y[])
{
  for (int i = 0; i < C; i++)
    if (x[i] == 0 && y[i] > 0) return false;
  return true;
}

int k, l, s, h[C], he[C], kmp[N];
char kb[N], ew[N];
double p[N][N], e[N][N];

int main()
{
  int T;
  scanf("%d", &T);
  for (int kas = 1; kas <= T; kas++) {
    printf("Case #%d: ", kas);
    scanf("%d%d%d%s%s", &k, &l, &s, kb, ew);
    memset(h, 0, sizeof(h));
    for (int i = 0; i < k; i++) h[kb[i]-'A']++;
    memset(he, 0, sizeof(he));
    for (int i = 0; i < l; i++) he[ew[i]-'A']++;
    if (!Check(h, he)) {
      printf("%f\n", 0.0);
      continue;
    }
    Kmp(ew, l, kmp);
    memset(p, 0, sizeof(p));
    memset(e, 0, sizeof(e));
    p[0][0] = 1.0;
    for (int i = 0; i < s; i++)
      for (int j = 0; j <= l; j++)
        for (int c = 0; c < C; c++) {
          int next = Next(ew, l, kmp, j-1, c+'A')+1;
          double q = 1.0*h[c]/k;
          p[i+1][next] += p[i][j]*q;
          e[i+1][next] += e[i][j]*q;
          if (next == l) e[i+1][next] += p[i][j]*q;
        }
    double exp = 0.0;
    for (int i = 0; i <= l; i++) exp += e[s][i];
    printf("%f\n", 1.0*Max(s, kmp, l)-exp);
  }
  return 0;
}
