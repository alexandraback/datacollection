#include <iostream>
#include <bitset>
#include <cstdint>
#include <vector>
#include <string>

using namespace std;

typedef int64_t ii;
typedef uint64_t ui;

int64_t expo(int64_t a, int64_t b){
  int64_t result = 1ll;

  while (b>0ll){
    result *= a;
    b--;
  }

  return result;
}

int main() {
  freopen("in", "r", stdin);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cout << "Case #" << i << ": ";
    string pile; cin >> pile;
    char cur = pile[0];
    int flips = 0;
    for (ui i = 1; i < pile.size(); ++i) {
      if (pile[i] != cur) {
        cur = pile[i]; flips++;
      }
    }
    if (pile.back() == '-') flips++;
    cout << flips << "\n";
  }
}
