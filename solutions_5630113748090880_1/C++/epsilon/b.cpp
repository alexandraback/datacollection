#include <bits/stdc++.h>

using namespace std;

int main(){
  int t;
  cin >> t;
  for(int cas = 1; cas <= t; cas++){
    cout << "Case #" << cas << ": ";
    int n, a;
    cin >> n;
    map<int, int> num;
    for(int i = 0; i < 2*n*n - n; i++){
      cin >> a;
      num[a]++;
    }
    for(auto x: num){
      if(x.second % 2 == 1){
        cout << x.first << " ";
      }
    }
    cout << endl;
  }
}