#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>

using namespace std;

int gx, gy;

int main(){
  int CS;
  cin >> CS;
  for(int cs = 1 ; cs <= CS ; cs++){
    cin >> gx >> gy;
    string ans ="";
    string N, E, S, W;
    N = "SN";
    E = "WE";
    S = "NS";
    W = "EW";
    
    if(gx > 0){
      for(int i = 0 ; i < abs(gx) ; i++){
	ans += E;
      }
    }
    if(gx < 0){
      for(int i = 0 ; i < abs(gx) ; i++){
	ans += W;
      }
    }

    if(gy > 0){
      for(int i = 0 ; i < abs(gy) ; i++){
	ans += N;
      }
    }
    if(gy < 0){
      for(int i = 0 ; i < abs(gy) ; i++){
	ans += S;
      }
    }   
    cout << "Case #" << cs << ": " << ans << endl;
  }
  return 0;
}

