#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <climits>
#include <queue>
#define LL long long
#define ULL unsigned long long
#define ABS(a) (((a) > 0) ? (a) : (-(a)))
#define MAX(a,b) (((a)>(b)) ? (a) : (b))
#define MIN(a,b) (((a)<(b)) ? (a) : (b))
using namespace std;
template<typename T> ostream& operator<<(ostream& s, vector<T>& v) {
  s << '{';
  for (int i = 0 ; i < v.size(); ++i)
    s << (i ? "," : "") << v[i];
  return s << '}';
}
template<typename S, typename T> ostream& operator<<(ostream &s, pair<S,T>& p){
  return s << "(" << p.first << "," << p.second << ")";
}

int tc;

void solve(int X, int R, int C){
  bool tilable = false;
  if(X == 1){
    tilable = true;
  }
  else if(X == 2){
    if(R%2==0 || C%2==0)
      tilable = true;
  }
  else if(X == 3){
    if(C==1) tilable = false;
    else if(R*C % 3 == 0) tilable = true;
  }
  else if(X == 4){
    if(R == 4 && C == 4) tilable = true;
    if(R == 4 && C == 3) tilable = true;
  }
  printf("Case #%d: %s\n", tc, tilable?"GABRIEL":"RICHARD");
}

int main(){
  int TC;cin>>TC;
  for(tc=1; tc<=TC; tc++){
    int X,R,C;cin>>X>>R>>C;
    if(R<C) solve(X,C,R);
    else solve(X,R,C);
  }
}

