using namespace std;
#include <iostream>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    cout << "Case #" << t << ":";
    int K,C,S;
    cin >> K >> C >> S;
    if (S*C < K) {
      cout << " IMPOSSIBLE" << endl;
      continue;
    }
    unsigned long long next = 0;
    while (next < K){
      unsigned long long base = 1;
      unsigned long long posn = 0;
      for (unsigned long long i=0; (i<C) && (next < K); i++){
        posn += base * next;
        base *= K;
        next++;
      }
      cout << " " << posn + 1;
    }
    cout << endl;
  }
}
