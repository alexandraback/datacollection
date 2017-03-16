#include <iostream>
#include <sstream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <string>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <algorithm>
#include <climits>
using namespace std;
typedef unsigned long ulong;
typedef unsigned int uint;
typedef unsigned short ushort;
typedef unsigned char byte;
typedef long long ll;
typedef unsigned long long ull;
//const unsigned long PRIME = 1000003ul;
//const unsigned long POW2 [32] ={1ul,2ul,4ul,8ul,16ul,32ul,64ul,128ul,256ul,512ul,1024ul,2048ul,4096ul,8192ul,16384ul,32768ul,65536ul,131072ul,262144ul,524288ul,1048576ul,2097152ul,4194304ul,8388608ul,16777216ul,33554432ul,67108864ul,134217728ul,268435456ul,536870912ul,1073741824ul,2147483648ul};
//const unsigned long POW2 [64] = {1ul,2ul,4ul,8ul,16ul,32ul,64ul,128ul,256ul,512ul,1024ul,2048ul,4096ul,8192ul,16384ul,32768ul,65536ul,131072ul,262144ul,524288ul,1048576ul,2097152ul,4194304ul,8388608ul,16777216ul,33554432ul,67108864ul,134217728ul,268435456ul,536870912ul,1073741824ul,2147483648ul,4294967296ul,8589934592ul,17179869184ul,34359738368ul,68719476736ul,137438953472ul,274877906944ul,549755813888ul,1099511627776ul,2199023255552ul,4398046511104ul,8796093022208ul,17592186044416ul,35184372088832ul,70368744177664ul,140737488355328ul,281474976710656ul,562949953421312ul,1125899906842624ul,2251799813685248ul,4503599627370496ul,9007199254740992ul,18014398509481984ul,36028797018963968ul,72057594037927936ul,144115188075855872ul,288230376151711744ul,576460752303423488ul,1152921504606846976ul,2305843009213693952ul,4611686018427387904ul,9223372036854775808ul};
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

void sum(int &sumX, int &sumO, char ch)
{
  switch (ch) {
    case 'X':
      sumX++;
      break;
    case 'O':
      sumO++;
      break;
    case 'T':
      sumX++; sumO++;
  }
}

string result(string boardstr)
{
  int sumX = 0, sumO = 0;
  // horiz
  REP(i,4) {
    sumX = sumO = 0;
    REP(j,4)
      sum(sumX, sumO, boardstr[4*i+j]);
    if (sumX == 4)
      return "X won";
    if (sumO == 4)
      return "O won";
  }
  // diag
  sumX = sumO = 0;
  REP(i, 4)
    sum(sumX, sumO, boardstr[5*i]);
  if (sumX == 4)
    return "X won";
  if (sumO == 4)
    return "O won";

  return string();
}

int main()
{
  ios_base::sync_with_stdio(false);
  int T;
  cin >> T;
  REP(TC, T) {
    int nodot = 0;
    char board[4][4] = {};

    REP(i,4) REP(j,4) {
      cin >> board[i][j];
      if (board[i][j] != '.') ++nodot;
    }
    string horizstr, vertstr;
    REP(i,4) REP(j,4) { horizstr += board[i][j]; }
    FORD(j,3,0) REP(i,4) { vertstr += board[i][j]; }
    string res = result(horizstr);
    if (!res.empty())
      goto end;
    res = result(vertstr);
    if (!res.empty())
      goto end;
    if (nodot == 16) {
      res = "Draw";
      goto end;
    }
    res = "Game has not completed";

    end:
      cout << "Case #" << TC+1 << ": "<< res << "\n";
  }
  
  return 0;
}
