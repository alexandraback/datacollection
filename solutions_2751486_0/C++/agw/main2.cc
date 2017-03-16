#include <iostream>
#include <string>


int main(int argc, char** argv)
{
  std::cin.tie(0);
  std::ios_base::sync_with_stdio(0);

  int T;

  std::cin >> T;

  for (int t = 1; t <= T; t ++) {
    std::string s;

    int L;

    std::cin >> s >> L;

    std::string ss(L, 'c');

    int n = 0;

    for (int i = 0, size = s.size(); i < size; i ++)
      for (int j = i + 1; j <= size; j ++) {
        std::string t(s.substr(i, j - i));

        std::string u(t);
        
        for (int k = 0, size = t.size(); k < size; k ++)
          t[k] = (strchr("aeiou", t[k]) != NULL) ? 'v' : 'c';
        
        n += (t.find(ss) != std::string::npos) ? 1 : 0;
      }

    std::cout << "Case #" << t << ": " << n << std::endl;
  }
}
