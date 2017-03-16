#include <algorithm>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

int arr[20];
int val[1<<20];
set<int> seen;

void pnt(int i) {
  int index = 0;
  while (i) {
    if (i % 2) cout << arr[index] << " ";
    i /= 2;
    index++;
  }
  cout << endl;
}

int main() {
  int t; cin >> t;
  for (int ii = 1; ii <= t; ++ii) {
    cout << "Case #" << ii << ":" << endl;

    int n; cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> arr[i];
    }

    seen.clear();
    bool found = false;
    for (int i = 0; i < (1 << 20); ++i) {
      if (i == 0) {
        val[i] == 0;
        continue;
      }
      int curr = i/2;
      int largest = 0;
      int pow = 1;
      while (curr) {
        curr /= 2;
        largest++;
        pow *= 2;
      }
      
      val[i] = val[i - pow] + arr[largest];
      if (seen.count(val[i])) {
        for (int j = 0; j < (1 << 20); ++j) {
          if (val[j] == val[i]) {
            found = true;

            pnt(j);
            pnt(i);
            break;
          }
        }
        break;
      }
      seen.insert(val[i]);
    }
    if (!found) {
      cout << "Impossible" << endl;
    }
  }
  return 0;
}