#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int c[51][11];

bool bfs(int n) {
  vector<int> childs;
  int idx = 0;
  childs.push_back(n);
  while (idx < childs.size()) {
    for (int i = 1; i <= c[childs[idx]][0]; i++) {
      int e = c[childs[idx]][i];
      if (e == n) continue;
      if (find(childs.begin(), childs.end(), e) == childs.end()) {
	childs.push_back(e);
      } else {
	return true;
      }
    }
    idx++;
  }
  return false;
}


int main() {

  int T;

  cin >> T;

  for (int i = 0; i < T; i++) {
    int N = 0;
    cin >> N;
    c[0][0] = N;
    for (int j = 1; j <= N; j++) {
      int n;
      cin >> n;
      c[j][0] = n;
      for (int k = 1; k <= n; k++) {
	int r;
	cin >> r;
	c[j][k] = r;  
      }
    }
    
    bool h = false;

    for (int j = 1; j <= N; j++){
      if (bfs(j)) {
	h = true;
	break;
      }
    }
    if (h)
      cout << "Case #" << i+1 << ": Yes" << endl;
    else
      cout << "Case #" << i+1 << ": No" << endl;

  }


  return 0;
}
