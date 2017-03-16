#include <iostream>
#include <string>
using namespace std;

int main(){
  int T; // number of question
  cin >> T; cin.ignore();
  for(int i=0; i<T; i++){
    int S;
    string aud;
    cin >> S >> aud; cin.ignore();

    int fri = 0;
    for(int j=1; j<S+1; j++){
      int sum = fri;
      for(int k=0; k<j; k++){
        sum += (int)aud[k] -48;
      }
      if(sum < j){
        fri += j-sum;
      }
    }
    cout << "Case #" << i+1 << ": " << fri << endl;
  }
  //*/
  return 0;
}
