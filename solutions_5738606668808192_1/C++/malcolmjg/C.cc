using namespace std;
#include <iostream>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ":" << endl;
    int N,J;
    cin >> N >> J;
    // assumes N is even.
    for (int first_ones = 1; first_ones <=N; first_ones+=2){
      for (int first_zeroes=0; first_zeroes<=N; first_zeroes++){
        for (int second_zeroes=0; second_zeroes<=N; second_zeroes+=2){
          int third_zeroes = N - 3 - first_ones - first_zeroes - second_zeroes;
          if (third_zeroes >= 0 && J>0){
            for (int i=0; i<first_ones; i++) cout << "1";
            for (int i=0; i<first_zeroes; i++) cout << "0";
            cout << "1";
            for (int i=0; i<second_zeroes; i++) cout << "0";
            cout << "1";
            for (int i=0; i<third_zeroes; i++) cout << "0";
            cout << "1";
            for (int i=2; i<=10; i++) cout << " " << i+1;
            cout << endl;
            J--;
          }
        }
      }
    }
  }
}
