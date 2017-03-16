#include <cmath>
#include <iostream>
#include <vector>

using namespace std;

vector<long long> solve(long long k, long long c, long long s) {
  long long num_tiles_needed = ceil((double)k / c);

  //  cout << "Num tiles needed: " << num_tiles_needed << "\n";
  //  cout << "S: " << s << endl;

  if (num_tiles_needed > s) {
    return {};
  }

  long long cur_dir = 0;

  vector<long long> result;

  for (long long i = 0; i < num_tiles_needed; i++) {
    long long cur_pos = cur_dir;
    for (long long j = 0; j < c - 1; j++) {
      cur_pos *= k;
      if (cur_dir < k - 1) {
        cur_dir++;
      }
      cur_pos += cur_dir;
    }
    if (cur_dir < k - 1) {
      cur_dir++;
    }
    result.push_back(cur_pos + 1);
  }

  return result;
}

int main() {
  long long T;
  cin >> T;

  for (long long i = 1; i <= T; i++) {
    cout << "Case #" << i << ":";

    long long k, c, s;
    cin >> k >> c >> s;
    
    auto result = solve(k, c, s);
    if (result.empty()) {
      cout << " IMPOSSIBLE\n";
    } else {
      for (auto tile : result) {
        cout << ' ' << tile;
      }
      cout << "\n";
    }
  }
}
