#include <cstdio>

int npred[1024], hit[1024], found;
int ne[1024], e[1024][1024];

void dfs(int k)
{
  if (hit[k]) {
    found=1;
    return;
  }
  hit[k]=1;
  for (int j = 0; j < ne[k]; ++j)
    dfs(e[k][j]);
}

void clear(int k)
{
  hit[k]=0;
  for (int j = 0; j < ne[k]; ++j)
    clear(e[k][j]);
}

int main() {
  int t;
  scanf("%d",&t);
  for (int i = 0; i < t; ++i) {
    int n;
    scanf("%d",&n);
    found=0;
    for (int j = 0; j < n; ++j)
      npred[j] = hit[j] = 0;
    for (int j = 0; j < n; ++j) {
      int m;
      scanf("%d",&m);
      ne[j] = m;
      for (int k = 0; k < m; ++k) {
        scanf("%d", &e[j][k]);
        --e[j][k];
        ++npred[e[j][k]];
      }
    }
    for (int j = 0; j < n && !found; ++j)
      if (npred[j]==0) {
        dfs(j);
        if (!found) clear(j);
      }
    printf("Case #%d: %s\n", i+1, found?"Yes":"No");
  }
  return 0;
}

