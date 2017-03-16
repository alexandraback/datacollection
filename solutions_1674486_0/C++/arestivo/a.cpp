#include <iostream>
#include <sstream>
#include <vector>

using namespace std;

#define MAXV 1001
#define INF 200000000

struct nodo {
  vector<int> nei;
  bool visited;
};

bool percorre(nodo nodos[], int nn, int cp) {
  if (nodos[cp].visited) return true;
  nodos[cp].visited = true;
  for (int i = 0; i < nodos[cp].nei.size(); i++) {
    int next = nodos[cp].nei[i];
    bool res = percorre(nodos, nn, next);
    if (res) return true;
  }
  return false;
}

void solve(int t) {
  cout << "Case #" << t << ": ";

  int nc; cin >> nc;
  nodo nodos[nc];

  for (int c = 0; c < nc; c++) {
    int ni; cin >> ni;
    for (int i = 0; i < ni; i++) {
        int p; cin >> p;
	    nodos[c].nei.push_back(p - 1);
    }
  }

  bool found = false;
  for (int s = 0; s < nc; s++) {
	  for (int i = 0; i < nc; i++) nodos[i].visited = false;
	  if (percorre(nodos, nc, s)) {found = true; break;}
  }
  
  if (found) cout << "Yes" << endl;
  else cout << "No" << endl;
}

int main() {
	int tc; cin >> tc;

	for (int t = 1; t <= tc; t++) {
		solve(t);
	}

	return 0;
}
