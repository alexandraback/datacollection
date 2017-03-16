#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#include <utility>
#include <algorithm>
#include <functional>

using namespace std;

#define rep(i,n) for((i)=0;(i)<(int)(n);(i)++)
#define foreach(itr,c) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
template<class T> inline T toA(string& s){T v; istringstream sin(s);sin>>v;return v;}
template<class T> inline string toS(T& x){ostringstream sout;sout<<x;return sout.str();}

bool cycle(int i, int j){
  int k;
  string A = toS(i), B = toS(j);
  rep(k,A.size()) if(B == A.substr(k) + A.substr(0,k)) return true;
  return false;
}

void main2(){
  int A,B,i,j,res = 0;

  scanf("%d %d",&A,&B);
  for(i = A; i <= B; i++) for(j = A; j < i; j++) if(cycle(i,j)) res++;
  cout << res << endl;
}

int main(){
  int T,t;
  scanf("%d",&T);
  rep(t,T){
    printf("Case #%d: ",t+1);
    main2();
  }
  return 0;
}
