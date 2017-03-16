#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAX_N = 100030;    // Change as necessary
const ll  MODD = 1000000009; //

void do_case(){
  int n; cin >> n;
  if(n == 0){ cout << "INSOMNIA" << endl; return; }
  
  int used[10] = {0},ctr=0;
  for(int i=1;;i++){
    long long x = i*n;
    while(x){
      if(!used[x%10]){
        used[x%10] = true;
        ctr++;
      }
      x /= 10;
    }
    if(ctr == 10) { cout << i*n << endl; return; }
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  
  int T,C=1; cin >> T;
  
  while(T--){
    cout << "Case #" << C++ << ": ";
    do_case();
  }
  
  return 0;
}
