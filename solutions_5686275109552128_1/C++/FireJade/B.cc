#include <iostream>
#include <map>
using namespace std;

map<long long,long long> increment(map<long long, long long> m, long long idx, long long ct) {
  if (m.find(idx) == m.end()) {
    m[idx] = ct;
  } else {
    m[idx] += ct;
  }
  return m;
}

int main() {
  int T; cin >> T;
  int D, P; long long total= 0;
  for (int caseNum = 1; caseNum <= T; caseNum++) {
    map<long long, long long> plates;
    cin >> D;
    for (int i = 0; i < D; i++) {
      cin >> P; plates = increment(plates, P, 1);
    }
    long long maxNum = plates.rbegin()->first;
    long long best = maxNum;
    for (int i = 1; i < maxNum; i++) {
      long long tot = 0;
      for (map<long long,long long>::iterator it = plates.begin(); it != plates.end(); ++it) {
        if (it->first > i) {
          tot += it->second * ((it->first - 1) / i);
        }
      }
      best = min(best, tot + i);
    }
    cout << "Case #" << caseNum << ": " << best << endl;
  }
}
