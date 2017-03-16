#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n, m;
bool adj[64][64];
string code[64];
string res;

void go(vector<int>& cur, int mask, vector<int>& seq) {
  if (mask == (1 << n) - 1) {
    string curres = "";
    for (int i = 0; i < seq.size(); i++) curres += code[seq[i]];
    if (res == "" || curres < res) res = curres;
    return;
  }

  int last = cur[cur.size() - 1];
  if (cur.size() > 1) {
    cur.pop_back();
    go(cur, mask, seq);
    cur.push_back(last);
  }

  for (int i = 0; i < n; i++) {
    if ((mask & (1 << i)) == 0 && adj[last][i]) {
      cur.push_back(i);
      seq.push_back(i);
      go(cur, mask | (1 << i), seq);
      seq.pop_back();
      cur.pop_back();
    }
  }
}

int main() {
  int t; cin >> t;
  for (int c = 1; c <= t; c++) {
    cin >> n >> m;
    // n = 8; m = 28;
    memset(adj, 0, sizeof(adj));
    for (int i = 0; i < n; i++) {
      cin >> code[i];
      // code[i] = string(1, '0' + i);
    }
    /* for (int i = 0; i < n; i++)
      for (int j = i+1; j < n; j++)
        adj[i][j] = adj[j][i] = true; */
    for (int i = 0; i < m; i++) {
      int x, y; cin >> x >> y;
      adj[x-1][y-1] = adj[y-1][x-1] = true;
    }
    res = "";



    vector<int> cur, seq;
    for (int i = 0; i < n; i++) {
      cur.push_back(i);
      seq.push_back(i);
      go(cur, 1 << i, seq);
      seq.pop_back();
      cur.pop_back();
    }
    cout << "Case #" << c << ": " << res << endl;
  }
  return 0;
}
