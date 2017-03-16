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
#include <array>
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

bool check_train(vector<tuple<int,string>> &cars)
{
  vector<int> used('z'-'a'+1); 
  string train;
  for (int i = 0; i < (int)cars.size(); ++i) {
    train += get<1>(cars[i]);
  }
  used[train[0]-'a'] = true;
  for (int i = 1; i < (int)train.size(); ++i) {
    if (train[i] != train[i-1] && used[train[i]-'a'])
      return false;
    used[train[i]-'a'] = true;
  }
  return true;
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  int T; cin >> T;
  for (int tc=1;tc<=T;++tc) {
    cout << "Case #" << tc << ": ";
    int N; cin >> N;
    string car;

    vector<tuple<int,string>> cars;
    for (int i=0;i<N;++i) {
      cin >> car;
      cars.emplace_back(i, car);
    }

    ulong sum = 0;
    do {
      sum += check_train(cars);
    } while (next_permutation(cars.begin(), cars.end()));

    cout << sum << "\n";
  }

  return 0;
}
