#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

template<typename T>
bool is_prefix(T aitr, T aend, T bitr, T bend) {
  while (aitr != aend && bitr != bend) {
    if (*aitr != *bitr) {
      return false;
    }
    aitr++;
    bitr++;
  }

  return true;
}

int main() {
  //Test cases
  int T;
  int c = 1;
  cin >> T;
  while (T--) {
    //Case data
    int R, C, W;
    cin >> R >> C >> W;

    int to_find = R*(C / W);
    int to_sink = (W - 1);
    if (C%W != 0) { to_sink++; }
    cout << "Case #" << c++ << ": " << to_find + to_sink << endl;

  }
  return 0;

}