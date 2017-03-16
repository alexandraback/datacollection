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
const unsigned long POW2 [64] = {1ul,2ul,4ul,8ul,16ul,32ul,64ul,128ul,256ul,512ul,1024ul,2048ul,4096ul,8192ul,16384ul,32768ul,65536ul,131072ul,262144ul,524288ul,1048576ul,2097152ul,4194304ul,8388608ul,16777216ul,33554432ul,67108864ul,134217728ul,268435456ul,536870912ul,1073741824ul,2147483648ul,4294967296ul,8589934592ul,17179869184ul,34359738368ul,68719476736ul,137438953472ul,274877906944ul,549755813888ul,1099511627776ul,2199023255552ul,4398046511104ul,8796093022208ul,17592186044416ul,35184372088832ul,70368744177664ul,140737488355328ul,281474976710656ul,562949953421312ul,1125899906842624ul,2251799813685248ul,4503599627370496ul,9007199254740992ul,18014398509481984ul,36028797018963968ul,72057594037927936ul,144115188075855872ul,288230376151711744ul,576460752303423488ul,1152921504606846976ul,2305843009213693952ul,4611686018427387904ul,9223372036854775808ul};
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
inline bool EQ(double a, double b) { return fabs(a-b) < 1e-9; }

std::vector<ulong> primes(ulong N)
{
  // next line can be replaced with a bitset-like container to save memory 
  std::vector<char> sieve(N+1);
  sieve[0]=sieve[1]=true;
  ulong sqN = std::sqrt(N);
  ulong primes_cnt = 0;

  // mark primes and count primes up to sqrt(N)
  for (ulong i = 2; i <= sqN; ++i)
    if (!sieve[i]) {
      for (ulong j = i+i; j <= N; j += i)
        sieve[j] = true;
      ++primes_cnt;
    }
  // count primes from sqrt(N)+1 to N
  for (ulong i = sqN+1; i <= N; ++i)
    if (!sieve[i])
      ++primes_cnt;
  // create list of marked primes
  std::vector<ulong> primes;
  primes.reserve(primes_cnt);
  //primes.shrink_to_fit(); // save memory with C++11
  for (ulong i = 2; i <= N; ++i)
    if (!sieve[i])
      primes.push_back(i);

  return primes;
}

ulong gcd(ulong a, ulong b)
{
  if (b==0)
    return a;
  return gcd(b, a % b);
}

int main()
{
  int T; cin >> T;
  for (int tc=1;tc<=T;++tc) {
    cout << "Case #" << tc << ": ";
    ulong P,Q;
    scanf("%lu/%lu", &P,&Q);

    /*
    auto PRIMES = primes(ceil(sqrt(max(P,Q))));
    for (auto n : PRIMES) {
    //for (ulong n = 2; n <= max(P,Q); ++n) {
      while (P%n == 0 && Q%n == 0) {
        P /= n;
        Q /= n;
      }
    }
    */
    auto gc = gcd(P,Q);
    P /= gc;
    Q /= gc;

    if (POW2[40] % Q != 0) {
      cout << "impossible\n";
    } else {
      double f = (double)P/Q;
      for (int i=1;i<=40;++i) {
        if (1./POW2[i] <= f) {
          cout << i << "\n";
          break;
        }
      }
    }
  }

  return 0;
}
