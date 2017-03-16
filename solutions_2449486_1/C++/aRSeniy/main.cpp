#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <set>
#include <map>
#include <vector>
#include <bitset>
#include <cstdio>
#include <queue>

using namespace std;

void solve () {
  int n, m;
  cin >> n >> m;  

  map <int, vector <pair <int, int> >, greater<int> > positions;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      int h;
      cin >> h;
      positions[h].push_back(make_pair(i, j));
    }
  }
  
  vector <bool> used_line(n, false), used_column(m, false);
  map <int, vector <pair <int, int> >, greater<int> >::iterator it = positions.begin();
  for (; it != positions.end(); ++it) {
    for (int i = 0; i < it->second.size(); ++i) {
      int line = it->second[i].first;
      int column = it->second[i].second;

      if (used_line[line] && used_column[column]) {
        cout << "NO" << endl;
        return;
      }
    }
    for (int i = 0; i < it->second.size(); ++i) {
      int line = it->second[i].first;
      int column = it->second[i].second;

      used_line[line] = true;
      used_column[column] = true;
    }
  }

  cout << "YES" << endl;
}

int main() {
	freopen("B-large.in","r",stdin);
	freopen("output.txt","w",stdout);

	int T;
	cin >> T;
	for (int test = 1; test <= T; ++test) {
		cout << "Case #" << test << ": ";
    solve();
	}
	return 0;
}
