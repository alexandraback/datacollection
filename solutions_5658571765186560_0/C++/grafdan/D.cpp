#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstdio>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <utility>
#include <vector>
using namespace std;
typedef long long in;
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(int i=0;i<(n);i++)
#define forv(i,v) forn(i,sz(v))
typedef vector<in> VI;

bool test() { // can we always win?
  in X, R, C;
  cin >> X >> R >> C;
  if((R*C)%X) {
    return false;
  }
  if(min(R,C)==1) return !(X>=3);
  if(min(R,C)==2) return !(X>=4);
  if(min(R,C)==3) return !(X>=6);
  return !(X>=7);

}

int main(){
  std::ios::sync_with_stdio(false); // remove this if you use printf/scanf
  std::cin.tie(0);

  in T; cin >> T;
  forn(t,T) {
    cout << "Case #" << t+1 << ": ";
    if(test()) cout << "GABRIEL";
    else cout << "RICHARD";
    cout << endl;
  }

  return 0;  
}
