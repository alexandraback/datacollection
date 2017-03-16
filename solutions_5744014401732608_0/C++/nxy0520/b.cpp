#include "iostream"
#include "stdio.h"

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int cs = 1; cs<=T; cs++) {
    cout << "Case #" << cs << ": ";
    int mp[55][55] = {};
    int t[55] = {};
    int B, N;
    cin>>B>>N;
    for (int i = 1; i<B;i++) {
      for (int j =i+1; j<B;j++) {
        mp[i][j] = 1;
      }
    }
    t[1] = 1;
    t[2] = 1;
    for (int i = 3; i <= B;i++) {
      t[i] = 2 * t[i-1];
    }
    if (N>t[B]) cout << "IMPOSSIBLE" <<endl;
    else {
      cout <<"POSSIBLE"<<endl;
      for (int i = B-1; i>=0;i--) {
        if (N>=t[i]) {
          mp[i][B]=1;
          N-=t[i];
        }
      }
      for (int i =1; i<=B;i++){
        for (int j =1;j<=B;j++) {
          cout<<mp[i][j];
        }
        cout<<endl;
      }
    }
  }
}
