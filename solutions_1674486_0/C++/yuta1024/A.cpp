#include <iostream>
#include <sstream>
#include <cstdlib>
#include <cmath>
#include <map>
#include <set>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <cstdio>
#include <numeric>
#include <bitset>
#include <stack>
using namespace std;

const int INF = 1 << 30;

int main()
{
  int T;
  cin >> T;
  for (int Testcase = 1; Testcase <= T; ++Testcase) {
    int N;
    cin >> N;
    vector<vector<int> > path(N);
    for (int i = 0; i < N; ++i) {
      int M;
      cin >> M;
      for (int j = 0; j < M; ++j) {
	int X;
	cin >> X;
	path[i].push_back(X-1);
      }
    }

    bool yes = false;
    for (int i = 0; i < N && !yes; ++i) {
      for (int j = 0; j < N && !yes; ++j) {
	if (i == j)
	  continue;

	int cnt = 0;
	queue<int> que;
	que.push(i);
	vector<int> visited(N, 0);
	while (!que.empty()) {
	  int v = que.front();
	  que.pop();
	
	  if (v == j) {
	    ++cnt;
	    if (cnt == 2) {
	      yes = true;
	      break;
	    } else {
	      continue;
	    }
	  }

	  visited[v] = 1;
	  for (unsigned int k = 0; k < path[v].size(); ++k) {
	    if (!visited[path[v][k]])
	      que.push(path[v][k]);
	  }
	}
      }
    }

    cout << "Case #" << Testcase << ": ";
    if (yes)
      cout << "Yes" << endl;
    else
      cout << "No" << endl;
  }
  return 0;
}
