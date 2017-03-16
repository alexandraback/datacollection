#include <cstdio>

const int max_n = 200;

int h[max_n][max_n];
int g[max_n][max_n];

int n,m;
void solve(int t)
{
  scanf("%d %d",&n,&m);
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++) {
      scanf("%d",&h[i][j]);
      g[i][j] = 100;
    }

  int max;
  for(int i=0; i<n; i++) {
    max = 0;
    for(int j=0; j<m; j++)
      if(h[i][j] > max)
        max = h[i][j];
    for(int j=0; j<m; j++)
      if(g[i][j] > max)
        g[i][j] = max;
  }

  for(int j=0; j<m; j++) {
    max = 0;
    for(int i=0; i<n; i++)
      if(h[i][j] > max)
        max = h[i][j];
    for(int i=0; i<n; i++)
      if(g[i][j] > max)
        g[i][j] = max;
  }

  bool diff = false;
  for(int i=0; i<n; i++)
    for(int j=0; j<m; j++)
      if(h[i][j] != g[i][j])
        diff = true;

  if(diff)
    printf("Case #%d: NO\n",t+1);
  else
    printf("Case #%d: YES\n",t+1);
}

main()
{
  int t;
  scanf("%d",&t);
  for(int tt=0; tt<t; tt++)
    solve(tt);
}
