#include <iostream>
#include <vector>
#include <cstdio> 
#include <algorithm>
#include <set>
#include <string>
#include <map>
#include <queue>
#include <iomanip>
#include <cmath>

using namespace std;

#define REP(i, to) for(int i=0; i<to; i++)

typedef long long int LLI;
typedef pair<int, int> PII; 

void solve(){
  double C,F,X; 
  cin >> C >> F >> X; 
  
  double d=2.0; 
  double t=0.0; 
  double r = X/d; 
  
  while(t < X){
    t += C/d; 
    d += F; 
    if(t + X/d < r) r = t + X/d; 
    else break; 
    
    //cout << "r=" << r << " t=" << t << " d=" << d << endl;
  }
  
  cout << setprecision(15) << r;
}

int main(){
  int T;
  cin >> T;
  REP(t, T) {
    cout << "Case #" << t+1 << ": ";
    solve(); 
    cout << endl; 
  } 
  return 0; 
}
