#include<iostream>
#include<queue>
#include<queue>
using namespace std;
int main() {
  int tt;
  cin>>tt;
  for(int T=1;T<=tt;T++){
    int B;
    long long M;
    cin>>B>>M;
    cout << "Case #" << T << ": ";
    if (B-1 < 63 && (1LL<<(B-2)) < M) {
      cout << "IMPOSSIBLE";
    }else {
      cout<<"POSSIBLE"<<endl;
      cout << 0;
      bool ismax = (M == (1LL<<(B-2)));
      for (int i = B-3; i >=0; i--) {
        if (ismax || (M & ((1LL)<<i))) {
          cout << 1;
        }else {
          cout << 0;
        }
      }
      if (ismax) {
        cout << 1;
      }else{
        cout<<0;
      }
      cout<<endl;
      for(int i = 2; i <= B; i++) {
        for (int j = 1; j <=B;j++) {
          if (j > i) {
            cout<<1;
          }else {
            cout<<0;
          }
        }
        cout<<endl;
      }
    }
    cout<<endl;
  }
  return 0;
}
