#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <ctype.h>
#include <assert.h>

using namespace std;

typedef long long i64;
typedef vector<int> VI;
typedef vector<string> VS;
#define REP(i,n) for(int _n=n, i=0;i<_n;i++)
#define FOR(i,a,b) for(int i=(a),_b=(b);i<=_b;i++)
#define ALL(x)   (x).begin(),(x).end()
#define SORT(x) sort(ALL(x))
#define PB push_back

map<char, char> mp;

void init() {
  string s1 = "ejp mysljylc kd kxveddknmc re jsicpdrysirbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcdde kr kd eoya kw aej tysr re ujdr lkgc jv";
  string s2 = "our language is impossible to understandthere are twenty six factorial possibilitiesso it is okay if you want to just give up";
  REP(i, s1.length()) mp[s1[i]]=s2[i];
  mp['z'] = 'q';
  mp['q'] = 'z';
}

int main() {
  init();
  int T;
  string str;
  cin>>T; getline(cin, str);
  FOR(cs, 1, T) {
    getline(cin, str);
    REP(i, str.length()) str[i]=mp[str[i]];
    cout<<"Case #"<<cs<<": "<<str<<endl;
  }
  return 0;
}
