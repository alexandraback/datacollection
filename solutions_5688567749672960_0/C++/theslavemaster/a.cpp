#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;
const int SIZE = 1000000;
int f[SIZE+1];  
long long reverse(long long x) {
  long long res = 0;
  while(x) {
    res = res*10+x%10;
    x /= 10;
  }
  return res;
}
// vector<int> digits(long long x) {

// }
int main(int argc, char const *argv[])
{
  for (int i = 0; i <= 20; i++) {
    f[i] = i;
  }
  for (int i = 21; i < SIZE+1; i++) {
    int rev = reverse(i);
    if (rev >= i || i%10 == 0) {
      f[i] = f[i-1]+1;
    } else {
      f[i] = min(f[i-1]+1, f[rev]+1);
    }
  }
  
  int t = 0;
  scanf("%d\n", &t);
  for (int ii = 0; ii < t; ii++) {
    long long n = 0;
    scanf("%lld\n", &n);
    printf("Case #%d: %d\n", ii+1, f[n]);
    // long strat:

  }
  // int pow10[] = {1,10,100,1000,10000,100000,1000000,10000000};
  // for (int i = 0; i <= 7; i++ ) {
  //   printf("%d: %d\n", pow10[i], f[pow10[i]]);
  // }
  return 0;
}