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
/*
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
*/

double runtc() {
  /*
  maxocc = 0;
  totalposs = 0;
  banana = 0;
  */

  cin>>k>>l>>s;
  cin>>keyboard;
  cin>>tword;

  /*
  char word[200];
  word[0]=0;
  */
  
  //makeword(0, word);
  //cerr<<endl;
  //cerr<<maxocc<<endl;
  //cerr<<banana<<endl;
  //double P1 = (double)banana/totalposs;

  vector<int> letter(255, 0);
  forn(i,k) {
    letter[keyboard[i]]++;
  }
  double prob = 1;
  bool possible = true;
  forn(i,l) {
    prob *= (double)letter[tword[i]]/k;
    if(letter[tword[i]]==0) {
      possible = false;
    }
  }
  double P2 = prob*(s-l+1);
  /*
  if(abs(P1 - P2) > 1e-10) {
    cerr<<"PPP = "<<P1<<" "<<P2<<endl;
  }
  */

  int overlap = l;
  for(int i=1;i<l;++i) {
    if(!memcmp(tword, tword+i, l-i)) {
      overlap = i;
      break;
    }
  }
  int maxocc2 = 1+(s-l)/overlap;
  if(!possible) {
    maxocc2 = 0;
  }
  /*
  if(maxocc2 != maxocc) {
    cerr<<"OVERLAP = "<<maxocc<<" "<<maxocc2<<"  :"<<overlap<<" s="<<s<<" "<<tword<<endl;
  }
  */

  //return maxocc - (((double)banana)/totalposs);
  return maxocc2 - P2;
}

