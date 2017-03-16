#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

const string pat = "welcome to code jam";
const unsigned MOD = 10000;

void solve(int n) {
  unsigned long long r, t;
  cin >> r >> t;
  unsigned long long R = 2 * r - 3;
  unsigned long long low = 0, high = 707106781;
  while (true) {
    //cout << "(" << low << ", " << high << ") ";
    if (high - low <= 1) {
      cout << "Case #" << n << ": " << low << endl;
      break;
    }
    unsigned long long n = (low + high) / 2;
    unsigned long long paint_n = n * R + 2 * n * (n + 1);
    //cout << "mid = " << n << ", paint needed = " << paint_n
    //  << ", allow = " << t << endl;
    if (paint_n <= t) {
      low = n;
    } else {
      high = n;
    }
  }
}

int main(int argc, const char *argv[]) {
  int N;
  cin >> N;
  cin.ignore(100000, '\n');
  for (int n = 0; n < N; n++) {
    solve(n + 1);
  }
  return 0;
}
