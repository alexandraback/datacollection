#include <cstdio>
#include <algorithm>
using namespace std;


int ntc;
int t[200];
void solve() {
  int a, n;
  scanf("%d%d", &a, &n);
  for (int i=0; i<n; ++i)
    scanf("%d", t +i);
  sort(t, t+n);
  int o=0;
  int res = 100000000;
  for(int i=0; i<n; ++i) {
    res = min(res, o+n-i);
    if (a > t[i]) {
      a+=t[i];
    } else {
      if (a == 1) break;
      else {
        while(!(a>t[i])) {
          a+=a-1;
          ++o;
        }
        a+=t[i];
      }
    }
    res = min(res, o+n-i-1); 
  }
  
  printf("%d\n", res);


}

int main() {
  scanf("%d", &ntc);
  for(int c=1; c<=ntc; ++c) {
    printf("Case #%d: ", c);
    solve();
  }  

}
