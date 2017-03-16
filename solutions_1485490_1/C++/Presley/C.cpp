#include <cstdio>
#include <vector>

using namespace std;

long long f[128][128];

int main() {
  int t;
  scanf("%d", &t);
  for (int ti = 0; ti < t; ti++) {
    int n, m;
    scanf("%d %d", &n, &m);
    vector<long long> la(n);
    vector<int> a(n);
    vector<long long> lb(m);
    vector<int> b(m);

    for (int i = 0; i < n; i++) {
      scanf("%lld", &la[i]);
      scanf("%d", &a[i]);
    }
    
    for (int i = 0; i < m; i++) {
      scanf("%lld", &lb[i]);
      scanf("%d", &b[i]);
    }
    
    memset(f, 0, sizeof(f));
    for (int i = n - 1; i >= 0; i--) {
      for (int j = m - 1; j >= 0; j--) {
        if (a[i] == b[j]) {
          long long ac = la[i], bc = lb[j];
          int ni = i + 1, nj = j + 1;
          while (true) {
            f[i][j] = max(f[ni][nj] + min(ac, bc), f[i][j]);
            
            if (ac < bc) {
              for (; ni < n && a[ni] != a[i]; ni++);
              if (ni < n) {
                ac += la[ni];
                ni++;
              }
              else {
                break;
              }
            }
            else if (bc < ac) {
              for (; nj < m && b[nj] != b[j]; nj++);
              if (nj < m) {
                bc += lb[nj];
                nj++;
              }
              else {
                break;
              }
            }
            else {
              break;
            }
          }
        }
        else {
          f[i][j] = max(f[i + 1][j], f[i][j + 1]);
        }
      }
    }
    
    printf("Case #%d: %lld\n", ti + 1, f[0][0]); 
  }
  return 0;
}
