#include <vector>
#include <iostream>
#include <utility>
#include <algorithm>

using namespace std;


long long int C,D,V;
vector<long long int> former;
long long int result;

void getInput(){
  cin >> C >> D >> V;
former.clear();
  former.resize(D);
  for (long long int i = 0; i < D; ++i) {
    cin >> former[i];
  }
}


void solve() {
  result = 0;


  long long int partialSum = 0;
  if (former[0] > 1) {
    result ++; 
    partialSum += C;
    while (partialSum < former[0] - 1) {
      //manque des pieces, on ajoute la piece partialSum +1
      partialSum += (partialSum +1) * C;
      result ++;
    }


}
  former.push_back(V+1);
  for (long long int i = 0; i < former.size() - 1; ++i) {
    partialSum += C * former[i];
    while (partialSum < former[i+1] - 1) {
      //manque des pieces, on ajoute la piece partialSum +1
      partialSum += (partialSum +1) * C;
      result ++;
    }
  }
}


 int main () {
  long long int T;
  cin >> T;
  for (long long int cas = 0; cas < T; ++cas) {
    getInput();
    solve();
    cout << "Case #" << cas +1 << ": " << result << endl;
    cerr << "Case #" << cas +1 << ": " << result << endl;
  }
  
}

