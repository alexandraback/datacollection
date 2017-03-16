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

typedef long long LL;
typedef unsigned long long ULL;
#define sz(X) ((int)(X).size())
#define FOREACH(i,c) for(__typeof(c.begin()) i=(c.begin());i!=(c).end();++i)
template<class T> vector<T> tokenize_to(const string &str) { vector<T> r; T x; istringstream is(str); while (is >> x) r.push_back(x); return r; }
#define junik(X) {sort( (X).begin(), (X).end() ); (X).erase( unique( (X).begin(), (X).end() ), (X).end() ); }

int mX[]={0, 0, 1, -1};
int mY[]={1, -1, 0, 0};
char dir[]={'N', 'S', 'E', 'W'};

char go(bool X, bool plus, bool swapped) {
  int delta = 0;
  if (X) delta=2;
  if (plus==swapped) delta++;
  return dir[delta];
}

void solve(){
  int X, Y;
  cin >> X >> Y;
  bool swap=false;
  
  string ret="";
  if (X<0) {
    swap=true;
    X=-X;
  }
  int i=1;
  int sum=0;
  int diff=0;
  if (X!=0){
    for(;i+sum<=X;i++) {
      sum+=i;
      ret+=go(true, true, swap);
    }
    diff = X-sum;
    //if (diff==0) i--;
    for(int j=0;j<diff;++j){
      i+=2;
      ret+=go(true, false, swap);
      ret+=go(true, true, swap);
    }
  }
  if (Y!=0){
    if (Y<0){
      swap=true;
      Y=-Y;
    } else {
      swap=false;
    }
    sum=0;
    for(;i+sum<=Y;i++) {
      sum+=i;
      ret+=go(false, true, swap);
    }
    diff = Y-sum;
    for(int j=0;j<diff;++j){
      ret+=go(false, false, swap);
      ret+=go(false, true, swap);
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
