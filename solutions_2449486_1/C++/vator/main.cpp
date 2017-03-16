#include <cmath>
#include <algorithm>
#include <iomanip>
#include <algorithm>
#include <cstdio>
#include <cstring>

using namespace std;

int A[111][111];
int row[111];
int col[111];
int n,m;

inline bool check()
{
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      int a = A[i][j];
      if (a < row[i] && a < col[j]) return false;
    }
  }
  return true;
}

int main(void)
{
  int t;
  //freopen("input.txt", "rt", stdin);
  //freopen("output.txt", "wt", stdout);
  scanf("%d",&t);
  for (int ti = 0; ti < t; ti++) {
    memset(row,0,sizeof(row));
    memset(col,0,sizeof(col));
    scanf("%d%d",&n,&m);
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        int a;
        scanf("%d",&a);
        row[i] = max(row[i],a);
        col[j] = max(col[j],a);
        A[i][j] = a;
      }
    }
    printf("Case #%d: ", ti+1);
    if (check())
      puts("YES");
    else
      puts("NO");
  }
  return 0;
}
