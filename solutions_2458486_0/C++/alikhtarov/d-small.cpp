#include <iostream>
#include <functional>
#include <unordered_map>
#include <vector>
using namespace std;

int main() {
  int n, C = 1;
  cin >> n;
  int nk, nc;
  while (n-- && cin >> nk >> nc) {
    vector<int> K(210, 0);
    vector<int> T(nc);
    vector<vector<int>> CK(nc, vector<int>());

    int k, m;
    for (int i = 0; i < nk && cin >> k; ++i)
      ++K[k];
    for (int i = 0; i < nc && cin >> T[i] >> m; ++i)
      while (m-- && cin >> k)
	CK[i].push_back(k);


    unordered_map<int, bool> cache;
    function<bool(int)> solvable = [&](int bm) {
      auto it = cache.find(bm);
      if (it != cache.end()) return it->second;

      if (bm == (1 << nc) - 1)
	return cache[bm] = true;

      vector<int> H = K;
      for (int i = 0; i < nc; ++i)
	if ((bm >> i) & 1) {
	  for (int k : CK[i])
	    ++H[k];

	  --H[T[i]];
	}

      for (int i = 0; i < nc; ++i)
	if (!((bm >> i) & 1) &&
	    H[T[i]] > 0 &&
	    solvable(bm | (1 << i)))
	  return cache[bm] = true;
      
      return cache[bm] = false;
    };


    cout << "Case #" << C++ << ":";
    if (!solvable(0)) {
      cout << " IMPOSSIBLE";
    } else {
      int bm = 0;
      vector<int> H = K;
      for (int i = 0; i < nc; ++i) {
	for (int j = 0; j < nc; ++j) {
	  if (!((bm >> j) & 1) &&
	      H[T[j]] > 0 &&
	      solvable(bm | (1 << j))) {
	    
	    bm |= (1 << j);
	    for (int k : CK[j])
	      ++H[k];
	    --H[T[j]];

	    cout << " " <<  j + 1;
	    break;
	  }
	}
      }
    }
    cout << endl;
  }
}
