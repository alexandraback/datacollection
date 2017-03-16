#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int T;
long long P,Q;

long long gcd(long long a,long long b){
  if(a%b == 0) return b;
  else return gcd(b,a%b);
}

int bit_count(long long bit){
  int c = 0;
  for(; bit; bit>>=1){
    c += bit&1;
  }
  return c;
}

/*
int solve(long long a,long long b){
  if(a/2 == b/2 || (a%2 && (a/2+1) == b/2)) return 1;
  return min(solve(a/2,b/2),a%2?solve(a/2+1,b/2):10000) + 1;
}
*/

int solve(long long a,long long b){
  if(a == b) return 0;
  return solve(min(a,b/2),b/2)+1;
}

int main(void){
  scanf("%d",&T);
  for(int t = 1; t <= T; t++){
    scanf("%lld/%lld",&P,&Q);

    long long a = gcd(Q,P);
    P /= a;
    Q /= a;
    //cout << P << " " << Q << endl;
    //printf("%d\n",bit_count(Q));
    if(bit_count(Q)!=1){
      printf("Case #%d: impossible\n",t);
      continue;
    }
    printf("Case #%d: %d\n",t,solve(P,Q));
  }
}
