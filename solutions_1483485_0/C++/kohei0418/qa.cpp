#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <cctype>
#include <cassert>
#include <cstring>
#include <climits>

using namespace std;

#define FOR(k,a,b) for(typeof(a) k=(a); k < (b); k++)
#define FORE(k,a,b) for(typeof(a) k=(a); k <= (b); k++)
#define REP(k,a) for(int k=0; k < (a); k++)

#define SZ size()
#define ALL(c) (c).begin(), (c).end()
#define PB push_back
#define MP make_pair
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); i++)
#define EXIST(s,e) ((s).find(e)!=(s).end())

#define dump(x) cerr << #x << ": " << (x) << endl;

typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

const int INF = 1000 * 1000 * 1000;
const double EPS = 1e-10;

const string src = "ejp mysljylc kd kxveddknmc re jsicpdrysi\
rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd\
de kr kd eoya kw aej tysr re ujdr lkgc jv";

const string dst = "our language is impossible to understand\
there are twenty six factorial possibilities\
so it is okay if you want to just give up";

char trans[256];

int main()
{
  assert(src.size() == dst.size());

  REP(i, src.size()) {
    char s = src[i], d = dst[i];
    if(isalpha(s)) {
      trans[s] = d;
    }
  }
  trans['z'] = 'q';
  trans['q'] = 'z';

  // verify
  bool used[256];
  for(char c = 'a'; c <= 'z'; c++) used[c] = false;
  for(char c = 'a'; c <= 'z'; c++) used[trans[c]] = true;
  for(char c = 'a'; c <= 'z'; c++) assert(used[c] != false);
  
  int T;
  cin >> T;
  string dummy; getline(cin, dummy);
  REP(t, T) {
    string s;
    getline(cin, s);
    REP(i, s.size()) s[i] = isalpha(s[i])? trans[s[i]] : s[i];
    cout << "Case #" << (t+1) << ": " << s << endl;
  }
  
  return 0;
}
