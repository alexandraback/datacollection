#include <iostream>
#include <vector>
#include <list>
#include <map>
#include <math.h>

using namespace std;

map<int, int> countmap;

void missingrow(int t, int n) {
  cout << "Case #" << t << ":";

  vector<int> missing;

  map<int, int>::iterator mapiter = countmap.begin();

  for ( ; mapiter != countmap.end() ; ++mapiter) {
    if (mapiter->second %2) {
      missing.push_back(mapiter->first);
    }
  }

  sort(missing.begin(), missing.end());

  for (int i = 0; i < missing.size(); i++ ) {
    cout << " " << missing[i];
  }
  cout << endl;
  
}


int main() {
  int t, n;
  cin >> t;
  for (int tcount = 1; tcount <= t; tcount++) {
    countmap.clear();
    cin >> n;
    for (int i = 0; i < n * 2 - 1; ++i) {
      for (int j = 0; j < n; j++ ) {
	int next;
	cin >> next;
	if (countmap.find(next) != countmap.end()) {
	  countmap[next]++;
	} else {
	  countmap[next] = 1;
	}
      }
    }
    missingrow(tcount, n);
  }
}
