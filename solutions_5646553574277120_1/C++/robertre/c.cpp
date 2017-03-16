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
  in c, d, v;
  cin>>c>>d>>v;
  set<in> existing;
  forn(i,d) {
    in ei;
    cin>>ei;
    existing.insert(ei);
  }

  in reach = 0;
  int add = 0;

  //cerr<<endl;
  while(reach < v) {
    in want = reach + 1;
    //cerr<<"reach = "<<reach<<" want="<<want<<endl;
    bool skip = false;
    while(!existing.empty() && *existing.begin() <= want) {
      in value = *existing.begin();
      existing.erase(value);
      reach += value*c;
      skip = true;
    }
    if(!skip) {
      reach += want*c;
      add++;
    }
  }

  return add;
}
