#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cassert>
#include<ctime>
#include<cmath>

#include<algorithm>
#include<bitset>
#include<complex>
#include<deque>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<vector>
using namespace std;
long long isPrime(long long val){
  long long sq = sqrt(val+2) + 1;
  long long i;
  for(i = 2; i <= sq && i < val; i++)
    if(val % i == 0)
      return i;
  return 1;
}
const int N = 16;
const int J = 500;
int main(int argc, const char *argv[])
{
  int ans;
  long long S, tar, base, i, val, po, ret;
  long long div[20];
  bool flag;
  printf("Case #1:\n");
  ans = J;
  for(S = 0; S < (1LL<<(N-2)) && ans > 0; S++){
    tar = (1LL << (N-1)) | (S<<1LL) | 1;
    flag = true;
    for(base = 2; base <= 10 && flag; base ++){
      for(i = val = 0, po = 1; i < N; (i++), po *= base){
       if((1LL << i) & tar)
         val += po;
      }
      ret = isPrime(val);
      if(ret == 1) flag = false;
      else div[base] = ret;
    }
    if(flag){
      ans--;
      for(i = N-1; i >= 0; i--)
        printf("%d", ((1LL<<i) & tar)>0);
      for(i = N-1; i >= 0; i--)
        printf("%d", ((1LL<<i) & tar)>0);
      for(i = 2; i <= 10; i++)
        printf(" %lld", div[i]);
      puts("");
    }
  }
  return 0;
}
