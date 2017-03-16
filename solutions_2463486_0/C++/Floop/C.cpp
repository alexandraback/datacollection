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
#include <gmpxx.h>
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

int main()
{
  ios_base::sync_with_stdio(false);

  vector<string> sqrts = {"0", "1", "2", "00", "11"};
  vector<mpz_class> sqrti;

  size_t UPTO = 10;

  /* 0 and 1 wrapping grammar */
  for (size_t len = 3; len <= UPTO; len++) {
    size_t i = 0; while (sqrts[i].length() < len-2) ++i;
    while (sqrts[i].length() == len-2) {
      string num = "0" + sqrts[i] + "0";
      sqrts.push_back(num);

      num = "1" + sqrts[i] + "1";
      sqrts.push_back(num);
      ++i;
    }
  }

  /* remove items wrapped with 0's */
  sqrts.erase(remove_if(sqrts.begin(), sqrts.end(),
        [](const string &a){ return a.front() == '0'; }), sqrts.end());

  /* 2 0 0 . 0 . 0 0 2 */
  /* 2 0 0 . 1 . 0 0 2 */
  for (size_t len = 3; len <= UPTO; len += 2) {
    string num(len, '0');
    string numm(len-1, '0');

    num.front() = num.back() = '2';
    numm.front() = numm.back() = '2';
    sqrts.push_back(num);
    sqrts.push_back(numm);

    num[len/2] = '1';
    sqrts.push_back(num);
  }
  sqrts.push_back("0");
  sqrts.push_back("3");

  for (auto &str : sqrts)
    sqrti.push_back(mpz_class(str));
  sort(sqrti.begin(), sqrti.end());

  int T;
  cin >> T;
  REP(TC, T) {
    mpz_class A,B;
    cin >> A >> B;

    size_t sum = 0;
    for (auto &val : sqrti) {
      mpz_class sqval = val*val;
      string strval = sqval.get_str();
      string revstrval = strval;
      reverse(revstrval.begin(), revstrval.end());
      if (strval == revstrval && sqval >= A && sqval <= B)
        ++sum;
    }
    cout << "Case #" << TC+1 << ": "<< sum << "\n";
  }
  
  return 0;
}
