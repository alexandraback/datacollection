#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main () {
  long long t, n, input;
  cin >> t;
  vector<long long> missing;
  vector<long long> present;
  for (int i = 0; i < t; i++) {
    cin >> n;
    present.clear();
    present.resize(2500, 0);
    missing.clear();
    for (int j = 0; j < n*((2*n)-1); j++) {
      cin >> input;
      present[input] ++;
    }
    for (int j = 1; j <= present.size(); j++) {
//       cout << j << " " << present[j] << endl;
      if (present[j] % 2 == 1) {
	missing.push_back(j);
      }
    }
    sort(missing.begin(), missing.end());
    cout << "Case #" << i+1 << ": ";
    for (int j = 0; j < missing.size(); j++) {
      if (j < missing.size()-1) {
	cout << missing[j] << " ";
      } else {
	cout << missing[j] << "\n";
      }
    }
  }
  return 0;
}