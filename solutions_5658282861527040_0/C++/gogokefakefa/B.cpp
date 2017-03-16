#include <iostream>

using namespace std;


void solve(int i){
  cout << "Case #" << i << ": ";
  
  int A, B, K, res = 0;
  
  cin >> A >> B >> K;
  
  for(int i = 0; i < A; ++i)
    for(int j = 0; j < B; ++j)
      if((i&j) < K )
	++res;
      
  cout << res << endl;
}
int main(){
  int tests;
  
  cin >> tests;
  
  for(int i = 1; i <= tests; ++i)
    solve(i);
}
