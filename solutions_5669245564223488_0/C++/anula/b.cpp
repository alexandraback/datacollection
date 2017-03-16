#include <cstdio>
#include <algorithm>
#include <vector>
#include <iostream>
#include <unordered_set>
using namespace std;
const int modulo = 1000000007;

int brut(vector<string> &cars) {
  vector <int> perm;
  for (unsigned int i = 0; i < cars.size(); i++) {
    perm.push_back(i);
  }

  int result = 0;
  do {
    char started = -1;
    unordered_set<char> used;
    for (unsigned int i = 0; i < perm.size(); i++) {
      string curr = cars[perm[i]];
      for (unsigned int j = 0; j < curr.size(); j++) {
        if (curr[j] != started) {
          if (used.find(curr[j]) != used.end()) {
            goto not_found;
          }
          used.insert(curr[j]);
          started = curr[j];
        }
      }
    }
    result ++;
    result %= modulo;
    continue;
not_found:
    continue;
    
  } while (next_permutation(perm.begin(), perm.end()));
  return result;
}

int main() {
  int zet;
  cin >> zet;
  int caseNo = 1;
  while (zet--) {
    cout << "Case #" << caseNo << ": ";
    caseNo++;
    int n;
    cin >> n;
    vector <string> cars;
    for (int i = 0; i < n; i++) {
      string a;
      cin >> a;
      cars.push_back(a);
    }

    cout << brut(cars) << endl;
  }
  return 0;
}
