#include <algorithm>
#include <cstdio>

using namespace std;

int main() {
  int n, i, j;
  long long sum, ans, r, t;
  scanf("%d", &n);
  for(i=0 ; i<n ; i++) {
    scanf("%lld%lld", &r, &t);

    sum = 0;
    ans = 0;
    for(j=0 ;  ; j+=2) {
      sum += (r+j+1)*(r+j+1) - (r+j)*(r+j);
      ans++;
      //printf("%d %lld %lld\n", j, sum, t);
      if(sum > t) break;
    }
    //printf("%lld\n", sum);

    printf("Case #%d: %lld\n", i+1, ans-1);
  }


}
