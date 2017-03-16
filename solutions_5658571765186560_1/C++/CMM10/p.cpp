#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <cmath>
#include <stack>
#include <cstdio>
#include <stack>
#include <algorithm>

using namespace std;

int main(){
  freopen("in", "r", stdin);
  freopen("out", "w", stdout); 
  int tt;
  cin >> tt;
  for(int pp=0; pp<tt; ++pp){
    int X, R, C;
    cin >> X >> R >> C;
    bool richard = false;
    if(!(X==1)){
      if(X>R && X>C) richard=true; // big
      else if((R*C)%X!=0) richard=true; // small
      else if(ceil((float)X/2)>min(R,C)) richard=true; // half out 
      else if(X==4 && R*C==8) richard=true; // special for small
    }
    
    if(!richard) cout << "Case #" << pp+1 << ": " << "GABRIEL" << endl;
    else cout << "Case #" << pp+1 << ": " << "RICHARD" << endl;
  }
}