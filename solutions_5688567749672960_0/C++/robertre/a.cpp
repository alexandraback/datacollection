#include <algorithm>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>

#include <cassert>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>

using namespace std;
#define PB push_back
#define MP make_pair
#define sz(v) ((v).size())
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef long long in;
typedef unsigned long long int llu;

void runtc();

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    cout<<"Case #"<<(i+1)<<": ";
    runtc();
    cout<<endl;
  }
  
  return 0;
}

//=============================================================================
in flip(in i) {
  string s = to_string(i);
  reverse(s.begin(), s.end());
  in f = stoi(s);
  return f;
}

void runtc() {
  const int MAX = 1000000;
  in n;
  cin>>n;
  vector<in> K(MAX+1, MAX+2);
  K[0]=0;

  forn(i,MAX) {
    K[i+1] = min(K[i]+1, K[i+1]);
    in f = flip(i);
    K[f] = min(K[i]+1, K[f]);
  }

  cout<<K[n];
}
