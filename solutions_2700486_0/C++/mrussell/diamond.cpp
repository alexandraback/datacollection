#include <iostream>
#include <algorithm>
using namespace std;

unsigned nChoosek( unsigned n, unsigned k )
{
  if (k > n) return 0;
  if (k * 2 > n) k = n-k;
  if (k == 0) return 1;

  int result = n;
  for( int i = 2; i <= k; ++i ) {
    result *= (n-i+1);
    result /= i;
  }
  return result;
}

double probHasDiamond(unsigned n, unsigned k, int max) {
  unsigned num, denom;
  int i;

  if (n == max*2+1) return 1.;

  num = 0; denom = 0;
  // calc numerator
  for (i=k; i<=n; i++)  {
    if ((i <= max) && (n - i) <= max)
      num += nChoosek(n, i);
  }

  // calc denominator
  for (i=0; i<=n; i++)  {
    if ((i <= max) && (n - i) <= max)
      denom += nChoosek(n, i);
  }
  return ((double) num) / ((double) denom);
}

double find_traingular_numbers_between(int n, int xx, int y) {
  int last = 0, next = 0, c, x = 1, count = 0;
  while (next < n) {
    c = next;
    next = next + x;
    x += 1;
    last = c;
    count++;
  }
  if (x % 2 != 0)
    next += x;
  else
    last -= (x - 2);

  int max_x_plus_y;
  if (count % 2 != 0)
    max_x_plus_y = count - 1;
  else 
    max_x_plus_y = count;
  //printf("max_x_plus_y %d\n", max_x_plus_y);

  int x_plus_y = abs(xx) + y;
  //printf("x_plus_y %d\n", x_plus_y);
  if (x_plus_y <= max_x_plus_y - 2)
    return 1.;
  else if (x_plus_y <= max_x_plus_y) {
    int new_y = y + 1;
    int new_n = n - last;
    int max = (next - last - 1) / 2;
    return probHasDiamond(new_n, new_y,max);
  } else 
    return 0.;

}	

int one(int t, int n, int x, int y) {
  // int n, k = 3, max = 4;
  // for (n = 1; n <= 9; n++) {
  //   printf ("prob of %d,%d w/max of %d = %f\n", n, k, max, probHasDiamond(n,k,max));
  // }
  
  double ans = find_traingular_numbers_between(n, x, y) ;
  printf("Case #%d: %f\n", t, ans);
  
  return 0;
}

int main() {
  int T, t;
  scanf("%d", &T);
  for (t = 1; t <= T; t++) {
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    one(t, n, x, y);
  }
    
}
