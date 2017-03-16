#include <iostream>
#include <string>
using namespace std;

void run(int t) {
  int max_s;
  string s;
  cin >> max_s >> s;
  int need = 0;
  int standing = 0;
  for (int i = 0; i <= max_s; i++) {
    if (standing < i) {
      need += i - standing;
      standing = i;
    }
    standing += s[i] - '0';
  }
  cout << "Case #" << t << ": " << need << endl;
}

int main() {
  int T;
  cin >> T;
  for (int t = 1; t <= T; t++) {
    run(t);
  }
  return 0;
}
