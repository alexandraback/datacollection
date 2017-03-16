/*
ID: ahri1
PROG: B
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

typedef long long int64;
typedef unsigned long long uint64;
#define sz(X) ((int)(X).size())
#define foreach(i,c) for(__typeof((c).begin()) i=((c).begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

#define MOD 1000000007

void solve(){
  int N;
  cin >> N;
  vector<string> S(N);
  for(int i=0;i<N;++i){
    cin >> S[i];
  }
  
  int total_size = 0;
  string s="";
  for(int i=0;i<N;++i){
    s+=S[i];
  }
  junik(s);
  total_size=sz(s);
  
  
  int ret=0;
  
  vector<int> v;
  for(int i=0;i<N;++i){
    v.push_back(i);
  }
  
  do {
    s="";
    for(int i=0;i<N;++i){
      s+=S[v[i]];
    }
    // cerr << s << endl;
    s.erase(unique(s.begin(), s.end()), s.end());
    if (sz(s)==total_size) {
      ret++;
      if (ret==MOD) ret=0;
      // cerr << "!!" << endl;
    }
  
  } while (next_permutation(v.begin(), v.end()));
  
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
