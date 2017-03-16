#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <numeric>
#include <bitset>
#include <complex>
#include <iomanip>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <climits>
#include <cctype>
#include <cassert>
using namespace std;

typedef long long ll;
static const double EPS = 1e-8;
static const double PI = 4.0 * atan(1.0);
bool ISINT(double x){return fabs(x-(int)round(x))<EPS;}
bool ISEQ(double x,double y){return fabs(x-y)<EPS;}
string itos(ll x){stringstream ss;ss<<x;return ss.str();}
#define foreach(itr,c) for(__typeof(c.begin()) itr=c.begin();itr!=c.end();itr++)

ll A, B, K;
ll dp[200][2][2][2]; //[idx][flgA][flgB][flgK]

string bitA, bitB, bitK;

string getBit(ll x){
  string res = "";

  while(x > 0){
    if(x % 2 == 0){
      res = "0" + res;
    }
    else{
      res = "1" + res;
    }
    x /= 2;
  }

  while(res.size() != 32) res = "0" + res;

  return res;
}

int check(string bit, int idx, bool flg, int nextBit){
  if(flg) return flg;
  int nowBit = bit[idx] - '0';

  if(nowBit == nextBit){
    return 0;
  }
  else if(nowBit > nextBit){
    return 1;
  }
  return -1;
}

void solve(){
  bitA = getBit(A);
  bitB = getBit(B);
  bitK = getBit(K);

  memset(dp, 0, sizeof(dp));
  dp[0][0][0][0] = 1;

  for(int i = 0; i < 32; i++){
    for(int a = 0; a < 2; a++){
      for(int b = 0; b < 2; b++){
        for(int k = 0; k < 2; k++){
          if(dp[i][a][b][k] == 0) continue;

          for(int nextA = 0; nextA < 2; nextA++){
            for(int nextB = 0; nextB < 2; nextB++){
              int flgA = check(bitA, i, a, nextA);
              if(flgA == -1) continue;
              int flgB = check(bitB, i, b, nextB);
              if(flgB == -1) continue;

              int nextK = nextA & nextB;
              int flgK = check(bitK, i, k, nextK);
              if(flgK == -1) continue;

              dp[i + 1][flgA][flgB][flgK] += dp[i][a][b][k];
            }
          }
        }
      }
    }
  }

  cout << dp[32][1][1][1] << endl;
}

int main(void){
  int T;
  cin >> T;

  for(int CASE = 1; CASE <= T; CASE++){
    cout << "Case #" << CASE << ": ";
    cin >> A >> B >> K;
    solve();
  }
}
