#include <iostream>
#include <algorithm>
using namespace std;

const int MAX_N = 1030;

double A[MAX_N],B[MAX_N];
double A1[MAX_N],B1[MAX_N];

void do_case(){
  int N;
  
  cin >> N;
  for(int i=0;i<N;i++) cin >> A[i];
  for(int i=0;i<N;i++) cin >> B[i];
  
  sort(A,A+N); copy(A,A+N,A1);
  sort(B,B+N); copy(B,B+N,B1);
  
  // For the non-cheater, just choose your guys in smallest-to-largest
  int non_cheat = 0;
  for(int i=0;i<N;i++){
    double me = A[i];
    if(me > B[N-1]) non_cheat++;
    else {
      copy(B+i,lower_bound(B+i,B+N,me),B+i+1);
    }
  }
  
  copy(A1,A1+N,A);
  copy(B1,B1+N,B);
  
  // For the cheater, just take the smallest victory you can
  int cheat = 0;
  for(int i=0;i<N;i++){
    double you = B[i];
    if(you > A[N-1]) break; // I cannot win any more rounds...
    cheat++;
    copy(A+i,lower_bound(A+i,A+N,you),A+i+1);
  }
  
  cout << cheat << " " << non_cheat << endl;
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  return 0;
}
