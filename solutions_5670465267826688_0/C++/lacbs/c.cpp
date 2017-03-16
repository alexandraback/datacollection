#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;
#define fr(a,b,c) for(int a = b; a < c; ++a)

char idx[] = "1ijk0IJK";
char mat[] =
  "1ijk----"
  "i0Kj----"
  "jk0I----"
  "kJi0----"
  "--------"
  "--------"
  "--------"
  "--------"
;
char tr[256];

char s[1<<20];
int n,m;
void doit() {
  scanf("%d%d%s", &n, &m, s);
  if (m > 24) m = m % 24 + 24;

  fr(i,0,n) {
    s[i] = tr[s[i]];
    fr(j,1,m) s[i+j*n] = s[i];
  }
  n *= m;
  char w = 0;
  char g = 1;

  fr(i,0,n) {
    w = mat[w + 8 * s[i]];
    if (g && w == g) {
      g = (g + 1) % 4;
      w = 0;
    }
    //printf("%c ", idx[w]);
  }
  puts(g == 0 && w == 0 ? "YES" : "NO");
}

int main() {
  fr(i,0,8) tr[idx[i]] = i;
  fr(i,0,4) fr(j,0,4)
    mat[i+8*j] = tr[mat[i + 8*(j)]],
    mat[i+4 + 8*(j+4)] = mat[i + 8*(j)],
    mat[i+4 + 8*(j)] = mat[i + 8*(j+4)] = (mat[i + 8*(j)] + 4) % 8;

  int t; scanf("%d", &t);
  for (int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    doit();
  }
  return 0;
}