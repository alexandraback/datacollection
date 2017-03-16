#include <iostream>
#include <string>

using namespace std;

void solve(string &T,int i,int j) {
  if (j<i) return;
  if (i==j) cout << T[i];
  else {
    int k=i;
    for (int p=i+1; p<=j; p++)
      if (T[p]>=T[k]) k=p;
    cout << T[k];
    solve(T,i,k-1);
    for (int p=k+1; p<=j; p++)
      cout << T[p];    
  };
};

main() {
  int T;
  cin >> T;
  for (int x=1; x<=T; x++) {
    cout << "Case #" << x << ": ";
    string T;
    cin >> T;
    solve(T,0,T.length()-1);
    cout << endl;
  }
};
