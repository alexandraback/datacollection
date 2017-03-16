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

int runtc();

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    cout<<"Case #"<<(i+1)<<": ";
    cout<<runtc();
    cout<<endl;
  }
  
  return 0;
}

//=======================================================================
bool test(int c, int d, int v, vector<int> const& existing, vector<int> const& add) {
  vector<int> all;
  all.insert(all.end(), existing.begin(), existing.end());
  all.insert(all.end(), add.begin(), add.end());
  sort(all.begin(), all.end());
  forn(i,sz(all)-1) {
    if(all[i]==all[i+1]) {
      return false;
    }
  }
  vector<bool> reach(v+1, false);
  reach[0]=true;
  forv(i,all) {
    int value = all[i];
    for(int j=v-value;j>=0;--j) {
      reach[j+value] = reach[j];
    }
  }
  forv(i,reach) {
    if(!reach[i]) {
      return false;
    }
  }
  return true;
}
//=============================================================================
int runtc() {
  int c, d, v;
  cin>>c>>d>>v;
  vector<int> existing;
  forn(i,d) {
    int ei;
    cin>>ei;
    existing.push_back(ei);
  }

  if(c!=1 || v>32) {
    return -1;
  }

  if(test(c,d,v,existing,vector<int>())) {
    return 0;
  }

  vector<int> add;

  add.push_back(0);
  for(int i=1;i<=v;++i) {
    add[0]=i;
    if(test(c,d,v,existing,add)) {
      return 1;
    }
  }

  add.push_back(0);
  for(int i=1;i<=v;++i) {
    add[0]=i;
    for(int j=i+1;j<=v;++j) {
      add[1]=j;
      if(test(c,d,v,existing,add)) {
        return 2;
      }
    }
  }

  add.push_back(0);
  for(int i=1;i<=v;++i) {
    add[0]=i;
    for(int j=i+1;j<=v;++j) {
      add[1]=j;
      for(int k=j+1;k<=v;++k) {
        add[2]=k;
        if(test(c,d,v,existing,add)) {
          return 3;
        }
      }
    }
  }

  add.push_back(0);
  for(int i=1;i<=v;++i) {
    add[0]=i;
    for(int j=i+1;j<=v;++j) {
      add[1]=j;
      for(int k=j+1;k<=v;++k) {
        add[2]=k;
        for(int l=k+1;l<=v;++l) {
          add[3]=l;
          if(test(c,d,v,existing,add)) {
            return 4;
          }
        }
      }
    }
  }

  return 5;
}
