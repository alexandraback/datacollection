#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

typedef long long lli;

vector<pair<int,lli> > A[2];
lli T[101][101][102][2];

lli rec(int a, int b, int p, int t) {
  lli &res = T[a][b][p][t];
  if(res != -1) return res;
  res = 0LL;
  if(p != 101) {

  }
  if(A[0][a].first == A[0][b].first) {

  }
}

lli solve() {
  fill(T[0][0][0],T[101][0][0],-1LL);
  for(int i = 0; i < A[0].size(); ++i) {
    for(int j = 0; j < A[1].size(); ++j) {
      for(int k = 0; k < 101; ++k) {
	for(int j = 0; j < 2; ++j) {

	}
      }
    }
  }
}

int main() {
  int Tc;
  cin >> Tc;
  for(int tc = 1; tc <= Tc; ++tc) {
    int n, m;
    pair<int,lli> p;
    cin >> n >> m;
    A[0].clear();
    A[1].clear();
    for(int i = 0; i < n; ++i) {
      cin >> p.second >> p.first;
      A[0].push_back(p);
    }
    for(int i = 0; i < m; ++i) {
      cin >> p.second >> p.first;
      A[1].push_back(p);
    }
    cout << "Case #" << tc << ": " << solve() << endl;
  }
  return 0;
}

