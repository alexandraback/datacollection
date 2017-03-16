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

void solve(){
  int A, N;
  cin >> A >> N;
  vector<int> s(N);
  for(int i=0;i<N;++i) cin >> s[i];
  sort(s.begin(), s.end());
  vector<int> d(N);
  fill(d.begin(), d.end(), 0);
  for(int i=0;i<N;++i) {
    if (A>s[i]) { 
      A+=s[i];
    } else {
      if (A==1) { 
        d[i]=N;
      } else {
        while (A<=s[i]) {
          A+=A-1;
          d[i]++;
        }
        A+=s[i];
      }
    }
    if (i<N-1) d[i+1]=d[i];
  }
  int sol=N;
  for(int i=0;i<N;++i) {
    sol = min(sol, N-i-1+d[i]);
  }
  
  cout << sol << endl;
  
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
