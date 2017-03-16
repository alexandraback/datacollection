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
#include <unordered_map>
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

template <typename C>
void print(string s, C c)
{
  cerr << s << ": ";
  for (auto &val : c)
    cerr << val << " ";
  cerr << "\n";
}

ushort MAX_TYPE;
unordered_map<ushort, vector<ushort>> key_opens;
vector<vector<ushort>> chest_cont;
vector<ushort> chest_type;

vector<ushort> potential_keys(const list<ushort> &keys,
                              const vector<ushort> &open)
{
  set<ushort> uniqk(keys.begin(), keys.end());
  list<ushort> uniqk_list(uniqk.begin(), uniqk.end());
  vector<ushort> poten(keys.begin(), keys.end());

  auto it = uniqk_list.begin();
  while (it != uniqk_list.end()) {
    auto key = *it;
    for (auto &chest : key_opens[key]) {
      if (!open[chest]) {
        for (auto &cont : chest_cont[chest]) {
          poten.push_back(cont);
          if (uniqk.insert(cont).second == true)
            uniqk_list.push_back(cont);
        }
      }
    }
    ++it;
  }

  return poten;
}

bool open_all(list<ushort> &&keys,
              vector<ushort> &&open,
              vector<ushort> & order)
{
  //print("original keys", keys);

  // Optimisation
  vector<int> required(MAX_TYPE + 1);

  ushort closed = 0;
  for (size_t i = 1; i < open.size(); ++i)
    if (!open[i]) {
      ++closed;
      ++required[chest_type[i]];
    }

  // Recursion bottom
  if (closed == 0) return true;

  // Do I have enough keys?
  for (auto &key : potential_keys(keys, open))
    --required[key];
  for (auto &req : required)
    if (req > 0) return false;

  // for each key
  for (auto ikey = keys.begin(); ikey != keys.end(); ++ikey) {
    // skip equal keys
    if (ikey != keys.begin() && *prev(ikey) == *ikey) continue;

    // try to use a key
    auto key = *ikey;
    ikey = keys.erase(ikey);

    //print("current keys", keys);
     
    // which chests does it open
    for (auto &chest : key_opens[key]) {
      if (!open[chest]) {
        //print cerr << "opening " << chest << "\n";
        // New keychain
        auto newkeys = keys;
        newkeys.insert(
            newkeys.end(),
            chest_cont[chest].begin(), chest_cont[chest].end());
        newkeys.sort();
        // New opened chests set
        auto newopen = open;
        newopen[chest] = true;
        // Add item to accumulator
        order.push_back(chest);
        // Try to open the rest
        if (open_all(move(newkeys), move(newopen), order))
          return true;
        // Revert adding the accumulator item
        order.pop_back();
      }
    }

    // revert key removal
    ikey = keys.insert(ikey, key);

    //print("keys reverted", keys);
  }

  return false;
}

int main()
{
  ios_base::sync_with_stdio(false);
  
  int T;
  cin >> T;
  REP(TC, T) {
    ushort K, N;
    cin >> K >> N;

    MAX_TYPE = 0;
    list<ushort> keys;
    vector<ushort> order;
    chest_cont = vector<vector<ushort>>(N+1);
    chest_type = vector<ushort>(N+1);
    key_opens = unordered_map<ushort, vector<ushort>>();

    REP (i, K) {
      ushort key; cin >> key;
      keys.insert(keys.end(), key);
      MAX_TYPE = max(MAX_TYPE, key);
    }
    FOR (i, 1, N) {
      ushort Ti, Ki; cin >> Ti >> Ki;
      key_opens[Ti].push_back(i);
      chest_type[i] = Ti;
      MAX_TYPE = max(MAX_TYPE, Ti);
      chest_cont[i].resize(Ki);
      chest_cont[i].shrink_to_fit();
      REP (j, Ki) {
        cin >> chest_cont[i][j];
        MAX_TYPE = max(MAX_TYPE, chest_cont[i][j]);
      }
    }
    for (auto &vec : chest_cont)
      sort(vec.begin(), vec.end());
    keys.sort();

    vector<ushort> opened(N+1); opened[0] = true;
    if (open_all(move(keys), move(opened), order)) {
      cout << "Case #" << TC+1 << ":";
      for (auto chest : order)
        cout << " " << chest;
      cout << "\n";
    }
    else
      cout << "Case #" << TC+1 << ": IMPOSSIBLE\n";
      
  }
  
  return 0;
}
