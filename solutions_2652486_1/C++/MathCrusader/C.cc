#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set>
#include <cassert>
using namespace std;

int K,M,N;

void do_case(){
  int A[10],B[10],x,y;
  A[2] = A[3] = A[5] = A[7] = 0;
  B[2] = B[3] = 0;
  
  for(int i=0;i<K;i++){
    cin >> x;
    
    if(x % 2 == 0 && x % 4 != 0 && x % 3 != 0) B[2] = true;
    if(x % 3 == 0 && x % 9 != 0 && x % 2 != 0) B[3] = true;
    
    for(y=0;x % 2 == 0;y++) x /= 2;
    A[2] = max(y,A[2]);
    
    for(y=0;x % 3 == 0;y++) x /= 3;
    A[3] = max(y,A[3]);
    
    for(y=0;x % 5 == 0;y++) x /= 5;
    A[5] = max(y,A[5]);
    
    for(y=0;x % 7 == 0;y++) x /= 7;
    A[7] = max(y,A[7]);
  }
  
  // How many 5s and 7s do I need?
  cout << string(A[5],'5') << string(A[7],'7');
  int n = N - A[5] - A[7];
  int m = A[2] + A[3];
  
  if(B[2]){
    cout << 2;
    A[2]--;
    m--;
    n--;
  }
  
  if(B[3]){
    cout << 3;
    A[3]--;
    m--;
    n--;
  }
  
  // Use some 6s!
  while(m - 2 >= n - 1 && n > 0 && A[2] >= 1 && A[3] >= 1){
    cout << 6;
    A[2]--;
    A[3]--;
    m -= 2;
    n--;
  }
  
  // Use some 8s!
  while(m - 3 >= n - 1 && n > 0 && A[2] >= 3){
    cout << 8;
    A[2] -= 3;
    m -= 3;
    n--;
  }
  
  // Now some 4s!
  while(m - 2 >= n - 1 && A[2] >= 2){
    cout << 4;
    A[2] -= 2;
    m -= 2;
    n--;
  }
  
  cout << string(A[3],'3') << string(n-A[3],'2') << endl;
}

int main(){
  int T,C=1;
  cin >> T; // Always 1
  cout << "Case #1:" << endl;
  
  int R;
  cin >> R >> N >> M >> K;
  
  while(R--)
    do_case();
  
  return 0;
}
