#include <iostream>
#include <string>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <sstream>

#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cctype>

#include "gmpxx.h"

#define FOR(i,n) for(int i = 0, n_ = (n); i < n_; i++)
#define FORS(i,s,n) for(int i = (s), n_ = (n); i < n_; i++)
#define ITER(i,l) for(typeof((l).begin()) i = (l).begin(); i != (l).end(); ++i)


#define X first
#define Y second
#define PB push_back
#define MP make_pair

using namespace std;

template<typename T> inline void updatemax(T &a, T b) { if(a<b) a = b; }
template<typename T> inline void updatemin(T &a, T b) { if(a>b) a = b; }


void process(){
  int x, y;
  cin>>x>>y;
  if(x>0) FOR(i,x) cout<<"WE";
  if(x<0) FOR(i,-x) cout<<"EW";
  if(y>0) FOR(i,y) cout<<"SN";
  if(y<0) FOR(i,-y) cout<<"NS";
  cout<<endl;
}

int main(){
  int T;
  cin >> T;

  FOR(t, T){
    cout<<"Case #"<<t+1<<": ";
    process();
  }
  return 0;
}
