#include <iostream>
#include <string>
#include <vector>

using namespace std;


int main (){
  int T;
  cin >> T;
  for (int t = 1; t <= T; ++t){
    long long int M;
    int B;
    cin >> B >> M;
    if (M > (1 << B-2)){ 
      cout << "Case #" << t << ": IMPOSSIBLE" << endl;
    }
    else{
      cout << "Case #" << t << ": POSSIBLE" << endl;
      vector<vector<int> > edge(B, vector<int> (B));
      int i = 0;
      while (M >= (1 << i)){
        for (int j = 0; j <= i; ++j){
          edge[B-2-i][B-1-j] = 1;
        }
        i++;
      }
      if (i  <= B-2){
        int b = 0;
        for (int j = 0; j < i; ++j){
          b = (M >> j) - ((M >> (1+j)) << 1);
          edge[0][B-2-j] = b;
        }
      }
      for (int j = 0; j < B; ++j){
        for (int k = 0; k < B; ++k){
          cout << edge[j][k];
        }
        cout << endl;
      }
    }
  }


}
