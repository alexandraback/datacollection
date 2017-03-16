#include <cmath>
#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <bitset>
#include <algorithm>
#include <cstring>
using namespace std;

#define rep(i, a, b) for(int i = (a); i < int(b); ++i)
#define trav(it, v) for(typeof((v).begin()) it = (v).begin(); it != (v).end(); ++it)

typedef double fl;
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

map<char,char> translate;

char str[150];

bool solve(int tc) {
  cin.getline(str, 150);
  cout << "Case #" <<(tc+1)<<": ";
  rep(i,0,strlen(str)) str[i] = translate[str[i]];
  cout << str << endl;
  return true;
}

string cipher[] = {"ejp mysljylc kd kxveddknmc re jsicpdrysi",
"rbcpc ypc rtcsra dkh wyfrepkym veddknkmkrkcd",
"de kr kd eoya kw aej tysr re ujdr lkgc jv"};

string plain[] = {"our language is impossible to understand",
"there are twenty six factorial possibilities",
"so it is okay if you want to just give up"
};

int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0.out", "w", stdout);
  translate['z'] = 'q';
  translate['q'] = 'z';
  rep(i,0,3)
    rep(j,0,cipher[i].size())
      translate[cipher[i][j]] = plain[i][j];
  int n = 0;
  if(!n) cin >> n;
  cin.ignore();
  for(int i = 0; i < n && solve(i); ++i);
}