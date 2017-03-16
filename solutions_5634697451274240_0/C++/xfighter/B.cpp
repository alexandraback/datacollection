#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int main() {
  int T;
  cin >> T;
  for (int t = 0; t < T; ++t) {
    string in;
    cin >> in;
    char p = in[0];
    int count = 0;
    for (int i = 1; i < in.size(); ++i) {
      if (p != in[i]) {
        p = in[i];
        ++count;
      }
    }
    if (in[in.size() - 1] == '-') ++count;
    cout << "Case #" << t + 1 << ": " << count << endl;
  }
}
