#include <iostream>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>

using namespace std;

typedef long long int LLI;

void printPath(map<LLI, LLI> & r, LLI rep, LLI pos, LLI base, LLI dest) {
  bool space=false;
  for(LLI i=0;i<rep;++i) {
    if(space) {
      cout<<" ";
    }
    space=true;
    cout<<pos;
  }
  while(base != 0) {
    if(space) {
      cout<<" ";
    }
    space=true;
    cout<<base-r[base];
    base = r[base];
  }
  cout<<endl;
  space=false;
  while(dest != 0) {
    if(space) {
      cout<<" ";
    }
    space=true;
    cout<<dest-r[dest];
    dest = r[dest];
  }
  cout<<endl;
}

void solve() {
  map<LLI, LLI> input;
  LLI N;
  cin>>N;
  for(LLI n=0;n<N;++n) {
    LLI i;
    cin>>i;
    if(input.find(i)==input.end()) {
      input[i] = 1;
    } else {
      input[i] = input[i] + 1;
      cerr<<"Duplicate!"<<endl;
    }
  }
  map<LLI, LLI> reachable;
  map<LLI, LLI> newr;
  newr[0] = 0;

  for(map<LLI, LLI>::iterator mi = input.begin(); mi != input.end(); mi++) {
    LLI pos = mi->first;
    LLI repeat = mi->second;
    cerr<<".";
    for(LLI rep = repeat; rep >= 1; rep--)
    {
      reachable = newr;
      for(map<LLI, LLI>::reverse_iterator w = reachable.rbegin(); w != reachable.rend(); w++) {
        LLI base = w->first;
        LLI dest = pos*rep + base;
        LLI prev = pos*(rep-1) + base;
        map<LLI, LLI>::iterator f = reachable.find(dest);
        if(f!=reachable.end()) {
          printPath(reachable, rep, pos, base, dest);
          return;
        } else {
          newr[dest]=base;
        }
      }
    }
  }
  cout<<"Impossible"<<endl;
}


int main(int argc, char** argv) {

  int T;
  cin>>T;
  for(int t=0;t<T;++t) {
    cout<<"Case #"<<t+1<<":"<<endl;
    solve();
    cerr<<endl;
  }
  return 0;
}
