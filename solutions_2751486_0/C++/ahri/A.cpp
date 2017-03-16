/*
ID: ahri1
PROG: A
LANG: C++
*/
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <ctime>
#include <iostream>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

#define MAXN 1000001

bool isWovel(char c) {
  if (c=='a' || c=='i' || c=='e' || c=='o' || c=='u') return true;
  return false;
}

int d[MAXN];

void solve(){
  string s;
  int n;
  cin >> s >> n;
  ULL ret=0;
  int sum = 0;
  d[0]=0;
  int last = -1;
  for(int i=0;i<sz(s);++i) {
    if (!isWovel(s[i])) {
      sum++;
      if (i>0) d[i]=d[i-1]+1;      
      else d[i]=1;
    } else {
      d[i]=0;
    }
    if (d[i]>=n) {
      ret+=i-n+2;
      last = i;
    } else {
      if (last!=-1) {
        ret+=last-n+2;
      }
    }
  }
  cout << ret << endl;
}

int main() {

  cin.sync_with_stdio(0);
  int T;
  cin >> T;
  for (int i=0;i<T;i++) {
    cout << "Case #" << i+1 << ": ";
    solve();
  }
  
  return 0;
}
