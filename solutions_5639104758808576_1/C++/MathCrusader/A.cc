#include <iostream>
#include <cstdlib>
using namespace std;

const int MAX_N = 1030;
int A[MAX_N];

int do_case(){
  int S;
  cin >> S;
  int ans = 0, sum = 0;
  for(int i=0;i<=S;i++){
    char c;
    cin >> c;
    ans = max(ans,i-sum);
    sum += c-'0';
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
