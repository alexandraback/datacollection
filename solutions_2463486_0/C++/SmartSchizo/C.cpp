#include<stdio.h>
#include<math.h>

long long A,B;
int cnt[10000010];

int check(long long n) {
  long long x=n,y=0;
  while(x) {
    y = y*10+x%10;
    x /= 10;
  }
  return y==n;
}

void go(int t) {
  scanf("%lld %lld",&A,&B);
  long long a = (int)sqrt(A-1), b = (int)sqrt(B);
  printf("Case #%d: %d\n",t,cnt[b]-cnt[a]);
}

int main() {
  int t,T=1;

  long long x;
  
  for(x=1;x<10000010;x++) {
    cnt[x] = cnt[x-1];
    if(check(x) && check(x*x)) {
      cnt[x]++;
      //printf("%lld\n",x);
    }
  }

  scanf("%d",&T);
  for(t=1;t<=T;t++) go(t);
  return 0;
}
