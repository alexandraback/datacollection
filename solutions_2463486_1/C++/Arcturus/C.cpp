#include <stdio.h>
#include <math.h>

int DP[10000010] = {0};
int icase;

bool CheckPalin(long long a){
  int arr[20];
  int id=0;
  while(a > 0){
    arr[id] = a%10;
    a/=10;
    id++;
  }
  
  int lim = id/2;
  for(int i=0; i<lim; i++){
    if(arr[i] != arr[id-i-1]) return false;
  }
  return true;
}

void Prework(){
  long long t;
  
  DP[0] = 0;
  for(int i=1; i<=10000000; i++){
    if(CheckPalin(i)){
      t = i;
      t *= i;
      if(CheckPalin(t)){
        DP[i] = DP[i-1]+1;
        //printf("%d\n", i);
      }
      else DP[i] = DP[i-1];
    }
    else DP[i] = DP[i-1];
  }
}

void Work(long long a, long long b){
  long long a1, b1;
  a1 = a-10;
  if(a1 < 0) a1 = 0;
  
  a1 = sqrt(a1-10);
  b1 = sqrt(b+10);
  
  while(a1*a1 < a) a1++;
  while(b1*b1 > b) b1--;
  
  int ans = DP[b1] - DP[a1-1];
  printf("Case #%d: %d\n", icase+1, ans);
}

int main(){
  int jcase;
  long long a, b;
  
  Prework();
  
  freopen("C-large-1.in", "r", stdin);
  freopen("C-large-1.out", "w", stdout);
  
  scanf("%d", &jcase);
  for(icase=0; icase<jcase; icase++){
    scanf("%lld %lld", &a, &b);
    Work(a, b);
  }
  
  return 0;
}
