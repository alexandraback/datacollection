#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool pal(long k)
{
  int num = 0, a[1000];
  while(k>0) {
    a[num++] = k % 10; k = k /10;
  }
  for (int i = 0; i < num; i++) 
    if (a[i] != a[num-i-1]) return false;
  return true;
}

long pnum(long n)
{
  long ans = 0;
  for (long i = 1; i * i <= n; i++) {
    if (pal(i) && pal(i*i)) ans ++;
  }
  return ans;
}

int main()
{
  long num_test, test;
  scanf("%ld", &num_test);
  for (test = 1; test<=num_test; test++) {
    long n, m;
    scanf("%ld%ld", &n, &m);
    printf("Case #%ld: %ld\n", test, pnum(m) - pnum(n-1));
  }
}
