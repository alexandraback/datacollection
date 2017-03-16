#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 1030;
int A[MAX_N];

int do_case(){
  int D;
  cin >> D;
  
  for(int i=0;i<D;i++)
    cin >> A[i];
  
  int ans = 1000;
  
  for(int h=1;h<=1000;h++){
    int tot = h;
    for(int i=0;i<D;i++)
      tot += (A[i] + h - 1) / h - 1;
    ans = min(tot,ans);
  }
  
  return ans;
}

int main(){
  int T,C=1;
  cin >> T;
  while(T--)
    cout << "Case #" << C++ << ": " << do_case() << endl;
  return 0;
}
