using namespace std;
#include <iostream>
#include <algorithm>
#include <vector>

int main(){
  int T;
  cin >> T;
  for (int t=1; t<=T; t++){
    int n;
    cin >> n;
    bool h[2501] = {};
    for (int i=0; i<2*n-1; i++){
      for (int j=0; j<n; j++){
        int in;
        cin >> in;
        h[in] = !h[in];
      }
    }
    vector<int> list;
    for (int i=1; i<=2500; i++){
      if (h[i]) list.push_back(i);
    }
    sort(list.begin(), list.end());
    cout << "Case #" << t << ":";
    for (int i=0; i<list.size(); i++){
      cout << " " << list.at(i);
    }
   cout << endl;
  }
} 

