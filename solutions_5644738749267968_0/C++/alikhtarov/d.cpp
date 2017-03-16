#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
  int ncases;
  cin >> ncases;
  for (int ncase = 1; ncase <= ncases; ++ncase) {
    int n;
    cin >> n;						       
    vector<double> a, b;
    double x;
    for (int i = 0; i < n && cin >> x; ++i) a.push_back(x);
    for (int i = 0; i < n && cin >> x; ++i) b.push_back(x);
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int cheat = 0, win = 0;
    {
      auto ai = a.begin();
      auto bi = b.begin();
      while (ai != a.end() && bi != b.end()) {
	if (*ai > *bi) {
	  ++cheat;
	  ++ai, ++bi;
	} else {
	  ++ai;
	}
      }
    }
    {
      auto ai = a.begin();
      auto bi = b.begin();
      while (ai != a.end() && bi != b.end()) {
	if (*ai < *bi) {
	  ++win;
	  ++ai, ++bi;
	} else {
	  ++bi;
	}
      }
    }

    cout << "Case #" << ncase << ": "
	 << cheat << ' ' << a.size() - win << endl;
  }
}
