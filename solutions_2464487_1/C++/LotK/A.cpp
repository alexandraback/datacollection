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
    /*
    for(j=0 ;  ; j+=2) {
      //sum += (r+j+1)*(r+j+1) - (r+j)*(r+j);
      sum += 2*r+2*i+1;
      ans++;
      //printf("%d %lld %lld\n", j, sum, t);
      if(sum > t) break;
    }
    */
    long long left = 0, right = 1e9, mid;
    while(left <= right) {
      mid = (left + right) / 2;
      if(2*r*(mid+1) + 2*mid*(mid+1) + mid+1 <= t && 2*r*(mid+2) + 2*(mid+1)*(mid+2) + mid+2 > t) break;
      else if (2*r*(mid+1) + 2*mid*(mid+1) + mid+1 <= t ) left = mid+1;
      else right = mid-1;
    }

    printf("Case #%d: %lld\n", i+1, mid+1);
  }


}
