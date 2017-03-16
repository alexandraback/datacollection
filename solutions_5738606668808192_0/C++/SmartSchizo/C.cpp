#include<stdio.h>

long long check_prime(long long n, int l, int b) {
  long long p, z;
  
  for(p=2;p*p<=n;p++) {
    z = 1;
    for(int i = 1;i<l;i++) {
      z *= b;
      z %= p;
    }
    if((z+n)%p==0) return p;
  }
  return 0;
}

int main() {
  int b,j,l = 6;
  long long n, jamcoin;
  long long nums[11], divisors[11];
  int cnt = 100;
  
  scanf("%d %d %d",&j,&l,&cnt);
  printf("Case #1:\n");
  for(n = 1; n<((unsigned int)1<<(l-1)); n+=2) {
    
    for(b = 2;b<=10;b++) {
      jamcoin = 0;
      for(j = l-1;j>=0;j--) jamcoin = b*jamcoin + (n>>j)%2;
      divisors[b] = check_prime(jamcoin, l, b);
      jamcoin = 1;
      for(j = l-2;j>=0;j--) jamcoin = b*jamcoin + (n>>j)%2;
      nums[b] = jamcoin;
      if(!divisors[b]) break;
    }
    if(b == 11) {
      printf("1");
      for(j = l-2;j>=0;j--) printf("%d",(n>>j)&1);
      for(b = 2;b<=10;b++) printf(" %lld",divisors[b]);
      printf("\n");
      cnt--;
      if(cnt == 0) break;
    }  
  }
  
  return 0;
}
