#include <iostream>

int main() {
  int t; std::cin >> t;
  for (int tc=1; tc<=t; ++tc) {
    int m; std::string s; std::cin >> m >> s;
    int need = 0, standing=0, should=0;
    for (char c : s) {
      int x = c-'0';
      standing += x;
      ++should;
      while (standing < should)
        ++standing, ++need;
    }
    std::cout << "Case #" << tc << ": " << need << '\n';
  }
}
