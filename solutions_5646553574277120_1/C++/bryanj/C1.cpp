#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int t;
  cin >> t;
  for (int ti = 1; ti <= t; ti++) {
    long long c, d, v;
    cin >> c >> d >> v;
    long long units[150];
    for (int di = 0; di < d; di++)
      cin >> units[di];
    long long answer = 0;
    if (units[0] > 1) {
      for (int di = d; di > 0; di--)
        units[di] = units[di-1];
      units[0] = 1;
      answer++;
      d++;
    }
    long long mx = 0;
    for (int di = 0; di < d - 1; di++) {
      mx += units[di];
      long long from = mx;
      long long to = units[di+1];
      int cnt = 0;
      while (from + 1 < to) {
        mx += from + 1;
        from += from + 1;
        cnt++;
      }
      answer += cnt;
    }
    mx += units[d-1];
    mx *= c;
    while (mx < v) {
      answer += 1;
      mx += (mx + 1) * c;
    }
    cout << "Case #" << ti << ": " << answer << endl;
  }
  return 0;
}
