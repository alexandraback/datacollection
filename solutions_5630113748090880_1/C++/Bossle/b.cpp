#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef long long int lli;

int main() {
  int t;
  cin >> t;
  for (int ta=1; ta<=t; ++ta) {
    cout << "Case #" << ta << ":";
    vector<int> num_occ(2501, 0);
    int n;
    cin >> n;
    for (int i=0; i<(2*n-1)*n; ++i) {
      int x;
      cin >> x;
      num_occ[x]++;
    }
    for (int i=0; i<2501; ++i) {
      if (num_occ[i]%2)
        cout << ' ' << i;
    }
    cout << endl;
  }
}