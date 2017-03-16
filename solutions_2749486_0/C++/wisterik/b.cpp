#include <iostream>
#include <vector>
#include <algorithm>

#define int ll
#define rep(i, n) for(int i = 0; i < (n); i++)
#define all(v) (v).begin(), (v).end()
#define trace(x) { cerr << #x << " = " << x << endl; }

using namespace std;

typedef long long ll;

string solve2(int x, int y) {
  int dist = x + y;

  int acc = 0;
  int tesu = 1;
  while(true) {
    acc += tesu;
    if(acc >= dist && acc % 2 == dist % 2) {
      break;
    }
    tesu++;
  }

  cerr << tesu << endl;

  return "";
}

string solve(int x, int y) {

  string ans = solve2(abs(x), abs(y));

  int n = ans.size();

  rep(i, n) {
    char c = ans[i];
    if(x < 0 && c == 'E') ans[i] = 'W';
    if(x < 0 && c == 'W') ans[i] = 'E';
    if(y < 0 && c == 'N') ans[i] = 'S';
    if(y < 0 && c == 'S') ans[i] = 'N';
  }

  return ans;

}

void run() {

  int T;
  cin >> T;

  rep(i, T) {
    int x, y;
    cin >> x >> y;

    cout << "Case #" << (i+1) << ": " << solve(x, y) << endl;
  }

}

#undef int
int main() {
  run();
  return 0;
}
