#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
  int num_test, test;
  scanf("%d", &num_test);
  for (test = 1; test<=num_test; test++) {
    int n, m, a[100][100];
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) scanf("%d", &a[i][j]);
    bool check = true;
    for (int i = 0; i < n; i++)
      for (int j = 0; j < m; j++) {
        bool find1 = false, find2 = false;
        for (int k = 0; k < n; k++) if (a[k][j] > a[i][j]) find1 = true;
        for (int k = 0; k < m; k++) if (a[i][k] > a[i][j]) find2 = true;
        if (find1 && find2) check = false;
      }
    if (check) printf("Case #%d: YES\n", test);
    else printf("Case #%d: NO\n", test);
  }
}
