#include <iostream>
#include <cstring>
#include <cassert>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
using namespace std;
typedef long long int int64;
static const int MAX = 30;
vector<int> dA, dB, dC;
vector<int> binary(int D)
{
    vector<int> dD(MAX);
    for (int i = 0; i < MAX; i++) {
        dD[i] = ( (D & (1<<i)) != 0 );
    }
    return dD;
}
 
long dp[MAX + 1][2][2][2];
 
long rec(int t, int eqA, int eqB, int eqC)
{
    long & res = dp[t][eqA][eqB][eqC];
    if (res == -1) {
        res = 0;
        if (t == 0) {
            res = 1;
        } else {
            res = 0;
            for (int x = 0; x < 2; x++) {
                for (int y = 0; y < 2; y++) {
                    int z = x & y; 
                    if (    (!eqA || (x <= dA[t-1]) )
                         && (!eqB || (y <= dB[t-1]) )
                         && (!eqC || (z <= dC[t-1]) )
                       ) {
                        res += rec(
                                    t-1,
                                    eqA && (x == dA[t-1] ),
                                    eqB && (y == dB[t-1] ),
                                    eqC && (z == dC[t-1] )
                                  );
                    }
                }
            }
        }
    }
    return res;
}
long fn(int A, int B, int C)
{
    dA = binary(A), dB = binary(B), dC = binary(C);
    memset(dp, -1, sizeof(dp));
    return rec(MAX, 1,1,1);
}
int main(){
  freopen("in.txt","r",stdin);
  freopen("out.txt","w",stdout);
  int64 i,j,k,n,m,t,ans,cnt=1,a,b;
  cin>>t;
  while(t--){
    scanf("%lld %lld %lld",&a,&b,&k);
    ans = fn(a-1,b-1,k-1);
    printf("Case #%lld: %lld\n",cnt,ans);
    cnt++;
  }
  return 0;
}

