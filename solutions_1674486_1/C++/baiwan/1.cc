#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N;

int main() {
  int T;
  cin >> T;
  for (int t=1;t<=T;++t) {
    vector<vector<int> > G;
    vector<int> E;
    int N;
    cin >> N;
    set<int> S;
    for (int i=0;i<N;++i)
      S.insert(i);
    for (int i=0;i<N;++i) {
      G.push_back(E);
      int Mi;
      cin >> Mi;
      for (int j=0;j<Mi;++j) {
	int x;
	cin >> x;
	--x;
	G[i].push_back(x);
	if (S.find(x) != S.end())
	  S.erase(x);
      }
    }
    bool sol = false;
    for (set<int>::iterator it = S.begin(); it != S.end(); ++it) {
      queue<int> Q;
      set<int> V;
      V.insert(*it);
      Q.push(*it);
      while (!Q.empty()) {
	int c = Q.front();
	Q.pop();
	for (int k = 0; k < G[c].size(); ++k) {
	  if (V.find(G[c][k]) != V.end()) {
	    sol = true;
	    break;
	  }
	  V.insert(G[c][k]);
	  Q.push(G[c][k]);
	}
	if (sol) break;
      }
      if (sol) break;
    }
    if (sol) cout << "Case #" << t << ": " << "Yes" << endl;
    else  cout << "Case #" << t << ": " << "No" << endl;
  }
  return 0;
}
