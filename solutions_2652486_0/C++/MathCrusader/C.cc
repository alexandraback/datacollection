#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <utility>
#include <vector>
#include <map>
#include <set>
using namespace std;

int K,M,N;

void do_case(){
  int A[10],x,y;
  A[2] = A[3] = A[5] = 0;
  for(int i=0;i<K;i++){
    cin >> x;
    for(y=0;x % 2 == 0;y++) x /= 2;
    A[2] = max(y,A[2]);
    for(y=0;x % 3 == 0;y++) x /= 3;
    A[3] = max(y,A[3]);
    for(y=0;x % 5 == 0;y++) x /= 5;
    A[5] = max(y,A[5]);
  }
  
  // How many 3s and 5s do I need?
  cout << string(A[3],'3') << string(A[5],'5');
  
  int n = N - A[3] - A[5];
  
  // Use as few 4s as I can
  while(n < A[2]){
    cout << 4;
    A[2] -= 2;
    n--;
  }
  
  cout << string(n,'2') << endl;
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
