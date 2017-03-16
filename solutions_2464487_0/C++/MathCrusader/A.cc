#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cmath>
using namespace std;

typedef __int128_t big;
const int MAX_N = 100;

big quad(big a,big b,big c){
  big under = b*b - 4*a*c;
  cout << (unsigned long long)under << endl;
  return (-b + sqrt((long double)(under))) / (2*a);
}

bool valid(big r, big t, big n){
  return 2*n*n + (2*r-1) * n <= t;
}

void do_case(){
  long long r,t,n=1;
  cin >> r >> t;
  
  while(valid(r,t,n)) n *= 2;
  
  long long lo = n/2, hi = n;
  while(hi - lo > 1){
    long long mid = (hi - lo)/2 + lo;
    if(valid(r,t,mid)) lo = mid;
    else hi = mid;
  }
  
  cout << (valid(r,t,hi) ? hi : lo);
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": "; do_case(); cout << endl;
  }
  return 0;
}
