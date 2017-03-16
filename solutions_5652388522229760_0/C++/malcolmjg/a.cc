using namespace std;
#include <iostream>

int main(){
  int T;
  cin >> T;
  for (int i=1; i<=T; i++){
    int N, firstN;
    cin >> N;
    firstN = N;
    if (N==0) {
      cout << "Case #" << i << ": INSOMNIA" << endl;
      continue;
    }
    bool seen[10] = {0};
    while(true){
      int M = N;
      while (M>0){
        int d = M%10;
        seen[d] = 1;
        M/=10;
      }
      bool done = true;
      for (int j=0; j<10; j++) if(!seen[j]) done = false;
      if (done){
        cout << "Case #" << i << ": " << N << endl;
        break;
      }
      N += firstN;
    }
  }
}

