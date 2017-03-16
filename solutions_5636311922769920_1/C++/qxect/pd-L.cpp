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
int main(int argc, const char *argv[])
{
  int tn, z;
  long long K, C, S;
  long long i, j, Sum;

  cin >> tn;
  for (z = 1; z <= tn; z++) {
    cin >> K >> C >> S;
    printf("Case #%d:", z);
    if((C==1 && S < K) || ( (K+1)/2 > S )) printf(" IMPOSSIBLE\n");
    else{
      for(i = 0; i < K; i += 1 + (C!=1)){
        for(j = Sum = 0; j < C; j++){
          Sum = Sum * K + i;
        }
        if(C != 1 && i != K-1) Sum++;
        printf(" %lld", Sum + 1LL);
      }
      puts("");
    }
  }
  return 0;
}
