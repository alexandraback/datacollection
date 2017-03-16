#include <algorithm>
#include <array>
#include <bitset>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <forward_list>
#include <functional>
#include <initializer_list>
#include <iomanip>
#include <iostream>
#include <limits>
#include <list>
#include <map>
#include <memory>
#include <numeric>
#include <regex>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <valarray>
#include <vector>
using namespace std;

#define FORI(i,n) for(int i=0; i<(int)(n); ++i)
#define FORIB(i,b,n) for(int i=(int)(b); i<(int)(n); ++i)
#define FORIR(i,n) for(int i=(int)((n)-1); i>=0; --i)
#define FORIBR(i,b,n) for(int i=(int)((n)-1); i>=(int)(b); --i)
#define MP(a,b) make_pair(a,b)
#define MT(a...) make_tuple(a)
#define ALL(L) (L).begin(),(L).end()
#define ALLR(L) (L).rbegin(),(L).rend()
#define SZ(L) (L).size()
#define MAX(a,b) ((a)>(b)?(a):(b))
#define MIN(a,b) ((a)<(b)?(a):(b))
#define SORTED_PAIR(a,b) MIN(a,b),MAX(a,b)
#define INF (1<<29)
#define EPS (1e-9)

typedef unsigned int uint;
typedef unsigned long long ull;
typedef signed long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vvi> vvvi;
typedef pair<int,int> pii;
typedef vector<pii> vii;

ll MOD = 1000000007L;

ll fact(ll x) {
  ll r = 1;
  for(ll i = 1; i <= x; ++i) {
    r *= i;
    r %= MOD;
  }
  return r;
}

void solve(int t) {
  vector<string> chars;
  vector<char> begin(256, 0), end(256, 0);
  vi only(256, 0);
  int n;
  cin >> n;
  FORI(i, n) {
    string s;
    cin >> s;

    bool same = true;
    for(char c : s) {
      same &= (c == s[0]);
    }
    if(same) {
      only[s[0]]++;
    } else {
      chars.push_back(s);
    }
  }

  for(auto& s : chars) {
    if(begin[s[0]] == 0) {
      begin[s[0]] = s[s.size() - 1];
    } else {
      printf("Case #%d: 0\n", t + 1);
      return;
    }

    if(end[s[s.size() - 1]] == 0) {
      end[s[s.size() - 1]] = s[0];
    } else {
      printf("Case #%d: 0\n", t + 1);
      return;
    }
  }

  vector<int> inside(256, 0);
  for(auto& s : chars) {
    int b = 1, e = s.size() - 1;
    while(b < s.size() && s[b] == s[0]) {
      ++b;
    }
    while(e >= 0 && s[e] == s[s.size() - 1]) {
      --e;
    }
    for(int i = b; i <= e; ++i) {
      if(s[i] != s[i - 1]) {
        inside[s[i]]++;
        if(inside[s[i]] > 1 || begin[s[i]] != 0 || end[s[i]] != 0) {
          printf("Case #%d: 0\n", t + 1);
          return;
        }
      }
    }
  }
  
  ll res = 0;
  for(int i = 0; i < 256; ++i) {
    if(begin[i] == 0 && end[i] == 0 && only[i] != 0) {
      ++res;
    }
    if(begin[i] != 0 && end[i] == 0) {
      ++res;
    }
  }
  if(res == 0) {
    printf("Case #%d: 0\n", t + 1);
    return;
  }
  res = fact(res);
  for(int i = 0; i < 256; ++i) {
    res *= fact(only[i]);
    res %= MOD;
  }
  printf("Case #%d: %lld\n", t + 1, res);
}

int main() {
  int T;
  scanf("%d", &T);
  FORI(t,T){
    solve(t);
  }
}
