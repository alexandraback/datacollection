#include <map> 
#include <set> 
#include <queue> 
#include <stack> 
#include <bitset> 
#include <algorithm> 
#include <functional> 
#include <numeric> 
#include <sstream> 
#include <iostream> 
#include <iomanip> 
#include <cmath> 
#include <ctime> 
#include <float.h> 

using namespace std; 

#define REP(i, from, to) for (int i = (from); i < (to); ++i) 
#define FOR(i, n) REP(i, 0, (n)) 
#define ALL(x) x.begin(), x.end() 
#define SIZE(x) (int)x.size() 
#define PB push_back 
#define MP make_pair 

typedef long long i64; 
typedef vector<int> VI; 
typedef vector<VI> VVI; 
typedef vector<string> VS; 
typedef vector<VS> VVS; 
typedef pair<int, int> PII; 

void readMapping(map<char, char>& mapping) {
  string original, encoded;
  while (getline(cin, encoded) && getline(cin, original)) {
    FOR (i, SIZE(original))
      if (original[i] != ' ')
        mapping[original[i]] = encoded[i];
    cin.ignore();
  }

  mapping['a'] = 'y';
  mapping['o'] = 'e';
  mapping['z'] = 'q';
  mapping['q'] = 'z';
  
  string keys, used;
  for (map<char, char>::const_iterator it = mapping.begin(); it != mapping.end(); ++it) {
    keys += it->first;
    used += it->second;
  }

  //sort(ALL(used));

  //if (used != keys) throw 10;
  cout << "We have " << SIZE(mapping) << " mappings\n";
}

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);

  //map<char, char> mapping;
  //readMapping(mapping);
  string const CODEMAP = "ynficwlbkuomxsevzpdrjgthaq";

  int t;
  cin >> t;

  cin.ignore();
  FOR (tt, t) {
    string encoded;
    getline(cin, encoded);

    string original;
    FOR (i, SIZE(encoded)) {
      if (encoded[i] == ' ')
        original += " ";
      else {
        int const k = CODEMAP.find(encoded[i]);
        original += char('a' + k);
      }
    }

    printf("Case #%d: %s\n", tt + 1, original.c_str());
  }

  return 0;
}