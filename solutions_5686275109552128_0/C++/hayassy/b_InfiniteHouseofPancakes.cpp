#include <iostream>
#include <string>
using namespace std;

//// main
int main(){
  int T;
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int D;            // diner which has pancake
    int P[1000] = {}; // num of ith diner's pancake
    int max=0;        // max of p
    cin >> D; cin.ignore();

    for(int j=0; j<D; j++){
      cin >> P[j];
      if(max < P[j])
        max = P[j];
    } cin.ignore();

    if(max<=3){
      cout << "Case #" << i+1 << ": " << max << endl;
      continue;
    }

    int res=1000*1000; // infinite
    for(int j=2; j<=max; j++){
      int sum = j;
      for(int k=0; k<D; k++){
        sum += (P[k]-1)/j;
      }
      if(sum < res){
        res = sum;
      }
    }

    cout << "Case #" << i+1 << ": " << res << endl;
  }

  return 0;
}
