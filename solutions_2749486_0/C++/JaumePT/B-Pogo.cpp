#include <iostream>
#include <vector>
#include <string>
#include <queue>
using namespace std;

typedef pair<int, int> PI;
typedef pair<PI, int> PII;

const int MAX = 100;

vector< vector<string> > sol(2*MAX+1, vector<string>(2*MAX + 1, ""));

int main() {
  queue<PII> q;
  q.push(PII(PI(MAX, MAX), 1));
  while (not q.empty()) {
    int x, y, d;
    x = q.front().first.first;
    y = q.front().first.second;
    d = q.front().second;
    q.pop();
    if (x+d < 2*MAX+1 and sol[x+d][y] == "") {
      sol[x+d][y] = sol[x][y] + "E";
      q.push(PII(PI(x+d, y), d+1));
    }
    if (x-d >= 0 and sol[x-d][y] == "") {
      sol[x-d][y] = sol[x][y] + "W";
      q.push(PII(PI(x-d, y), d+1));
    }
    if (y+d < 2*MAX+1 and sol[x][y+d] == "") {
      sol[x][y+d] = sol[x][y] + "N";
      q.push(PII(PI(x, y+d), d+1));
    }
    if (y-d >= 0 and sol[x][y-d] == "") {
      sol[x][y-d] = sol[x][y] + "S";
      q.push(PII(PI(x, y-d), d+1));
    }
  }
  int T;
  cin >> T;
  for (int cas = 1; cas <= T; ++cas) {
    int x, y;
    cin >> x >> y;
    cout << "Case #" << cas << ": " << sol[x+MAX][y+MAX] << endl;
  }
}
