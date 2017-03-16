#include <stdio.h>
#include <memory.h>

void solve()
{
  int n, m;
  int a[105][105], b[105][105];
  int rm[105], cm[105];
  memset(rm, 0, sizeof(rm));
  memset(cm, 0, sizeof(cm));

  scanf("%d%d", &n, &m);

  int i, j;
  for(i=1; i<=n; i++){
    for(j=1; j<=m; j++){
      scanf("%d", &a[i][j]);
      if(a[i][j] > rm[i]) rm[i] = a[i][j];
      if(a[i][j] > cm[j]) cm[j] = a[i][j];
    }
  }
  for(i=1; i<=n; i++){
    for(j=1; j<=m; j++){
      b[i][j] = 101;
      if(b[i][j] > rm[i])
        b[i][j] = rm[i];
      if(b[i][j] > cm[j])
        b[i][j] = cm[j];
      if(a[i][j] != b[i][j]){
        printf("NO\n");
        return;
      }
    }
  }
  printf("YES\n");
}

int main()
{
    freopen("B-small-attempt0.in", "r", stdin);
    freopen("B-small-attempt0.out", "w", stdout);
    int testcase;
    scanf("%d", &testcase);
    int i;
    for(i=1; i<=testcase; i++){
        printf("Case #%d: ", i);
        solve();
    }
    return 0;
}
