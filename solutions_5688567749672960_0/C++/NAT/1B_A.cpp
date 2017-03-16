#include<cstdio>

int T;
//0 to right
//1 to left
long long N, temp;
long long ct;
int len, lent;

int main(){
  scanf("%d", &T);
  for(int tt = 1; tt <= T; tt++){
    scanf("%lld", &N);

    len = 0;
    ct = 0;

    if(N % 10 == 0){
      N--;
      ct++;
    }

    temp = N;
    while(temp > 0){
      len++;
      temp /= 10;
    }

    while(len > 1){
      lent = 1;
      for(int i = 0; i < (len + 1) / 2; i++)
	lent *= 10;
      ct += N % lent - 1;
      
      N -= N % lent - 1;
      //printf("...%lld %d\n", N, ct);

      temp = 0;
      while(N > 0){
	temp *= 10;
	temp += N % 10;
	N /= 10;
      }
      N = temp;
      ct++;

      lent = 1;
      for(int i = 0; i < len / 2; i++)
	lent *= 10;
      
      if(N % lent == 1)ct--;
      else{
	ct += N % lent - 1;
	N -= N % lent - 1;
      }
      //printf("...%lld %d\n", N, ct);

      N -= 2;
      ct += 2;
      len--;
    }

    ct += N;

    printf("Case #%d: %lld\n", tt, ct);
  }
}
