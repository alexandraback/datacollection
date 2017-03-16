#include <algorithm>
#include <iomanip>
#include <iostream>
#include <sstream>
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

double runtc();

int main(){
  std::ios::sync_with_stdio(false);
  std::cin.tie(0);

  int ntc;
  cin>>ntc;
  for(int i=0;i<ntc;++i) {
    cout<<"Case #"<<(i+1)<<": ";
    cout<<std::fixed << std::showpoint<<setprecision(10)<<runtc();
    cout<<endl;
  }
  
  return 0;
}

//=============================================================================
int k, l, s;
char keyboard[200];
char tword[200];
in maxocc;
in totalposs;
in banana;

void makeword(int p, char* word) {
  //cerr<<p<<" "<<word<<endl;
  if(p == s) {
    totalposs++;
    in occ = 0;
    forn(i, s-l+1) {
      if(!memcmp(word+i, tword, l)) {
        occ++;
        banana++;
        //cerr<<word<<endl;
      }
    }
    if(occ > maxocc) {
      maxocc = occ;
    }
  } else {
    forn(i, k) {
      word[p]=keyboard[i];
      word[p+1]=0;
      makeword(p+1, word);
    }
  }
}

double runtc() {
  maxocc = 0;
  totalposs = 0;
  banana = 0;

  cin>>k>>l>>s;
  cin>>keyboard;
  cin>>tword;

  char word[200];
  word[0]=0;
  
  makeword(0, word);
  //cerr<<endl;
  //cerr<<maxocc<<endl;
  //cerr<<banana<<endl;
  //cerr<<totalposs<<endl;

  return maxocc - (((double)banana)/totalposs);
}

