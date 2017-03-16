#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int a[10];

bool update(int n){
  while(n!=0){
    a[n % 10] = 1;
    n = n / 10;
  }
  for(int i=0; i<10; i++){
    if(a[i] == 0) return false;
  }
  return true;
}

int main(){

  int T;
  cin >> T;
  for(int i=0; i< T; i++){
    int n;
    cin >> n;
    if(n == 0){
      cout << "Case #" << (i+1) << ": INSOMNIA" << endl;
      continue;
    }
    
    for(int j=0; j<10; j++) a[j] = 0;
    int cur_n = n;
    int id = 1;
    while(true){
      if(update(cur_n)) break;
      id++;
      cur_n = id * n;
    }
    
    cout << "Case #" << (i+1) << ": " << cur_n << endl;
    
  }

}
