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

int war(set<int> A, set<int> B){
  int r = 0; 
  for(set<int>::iterator iter = A.begin() ; iter != A.end() ; iter++){
    set<int>::iterator b = B.lower_bound(*iter); 
    if(b == B.end()) r++; 
    else {
      //cout << "war: " << *iter << " " << *b << endl;
      B.erase(b); 
    }
  }
  return r; 
}

int dec(set<int> A, set<int> B){
  int r = 0; 
  for(set<int>::iterator iter = A.begin() ; iter != A.end() ; iter++){
    int a = *iter; 
    int b = *(B.begin()); 
    
    //cout << "dec: " << a << " " << b << endl;
    
    if(a>b) {r++; B.erase(B.begin());} 
    else {set<int>::iterator bi = B.end(); bi--; B.erase(bi);}
  }
  return r; 
}

void solve(){
  int N;
  cin >> N;
  
  set<int> A; 
  set<int> B; 
  REP(i, N) {double x; cin >> x; A.insert(100000.0 * x);} 
  REP(i, N) {double x; cin >> x; B.insert(100000.0 * x);} 
  
  cout << dec(A,B) << " " << war(A,B); 
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
