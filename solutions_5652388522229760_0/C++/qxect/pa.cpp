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
  long long n, succ, tar, i, cnt, dig;
  int tn, z;
  cin >> tn;
  for (z = 1; z <= tn; z++) {
    cin >> n;
    printf("Case #%d: ", z);
    succ = 0;
    tar = (1LL << 10) - 1;
    for (i = 1; i < 10000000 && succ != tar; i++) {
      for(cnt = i*n; cnt && succ != tar; cnt /= 10){
        dig = cnt % 10LL;
        succ |= (1LL << dig);
      }
    }
    if(succ == tar) printf("%lld\n", (i-1LL)*n);
    else printf("INSOMNIA\n");
  }
  return 0;
}
