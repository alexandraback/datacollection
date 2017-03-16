#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>

using namespace std;

int main() {
  int nnn;
  cin >> nnn;
  for (int iii = 0; iii < nnn; ++iii) {
    int N;
    cin >> N;
    if (N == 0) {
      cout << "Case #" << iii+1 << ": INSOMNIA" << endl;
      continue;
    }

    long long ans = 0;
    int unseen = (1<<10) - 1;
    while(unseen != 0) {
      ans += N;
      for (long long v = ans; v > 0; v /= 10) {
	unseen &= ~(1 << (v%10));
      }
    }
    cout << "Case #" << iii+1 << ": " << ans << endl;
  }
}
