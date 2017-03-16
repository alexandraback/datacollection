#include <iostream>
using namespace std;

int main() {
  //                abcdefghijklmnopqrstuvwxyz
  const string Transform = "yhesocvxduiglbkrztnwjpfmaq";
  int T; cin >> T;
  string G; getline(cin, G); // end of line after T
  for (int t = 1; t <= T; t++) {
    getline(cin, G);
    for (size_t i = 0; i < G.size(); i++) {
      if ('a' <= G[i] && G[i] <= 'z') {
        G[i] = Transform[G[i] - 'a'];
      }
    }
    cout << "Case #" << t << ": " << G << endl;
  }
  return 0;
}

