#include <cstdio>
#include <algorithm>
using namespace std;

int main() {
  int tc; scanf("%d", &tc);
  for(int tci = 0; tci < tc; tci++) {
    int n; scanf("%d", &n);
    static pair<int,int> a[1000], b[1000];
    for(int i = 0; i < n; i++) {
      scanf("%d%d", &a[i].first, &b[i].first);
      a[i].second = b[i].second = i;
    }
    sort(a, a+n);
    sort(b, b+n);
    static int done[1000]; fill(done, done+n, 0);
    int stars = 0;
    int a_done = 0, b_done = 0;
    int count = 0;
    for(;;) {
      if(b_done == n) {
        printf("Case #%d: %d\n", tci+1, count);
        break;
      } else if(b[b_done].first <= stars) {
        count++;
        stars += 2-done[b[b_done].second];
        done[b[b_done].second] = 2;
        b_done++;
      } else if(a_done < n && a[a_done].first <= stars) {
        if(done[a[a_done].second] == 0) {
          count++;
          stars += 1-done[a[a_done].second];
          done[a[a_done].second] = 1;
        }
        a_done++;
      } else {
        printf("Case #%d: Too Bad\n", tci+1);
        break;
      }
    }
  }
  return 0;
}
