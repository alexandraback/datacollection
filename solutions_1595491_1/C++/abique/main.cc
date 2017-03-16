#include <iostream>
#include <string>

int main()
{
  int         ntests;
  int         N;
  int         S;
  int         p;

  std::cin >> ntests;

  for (int i = 0; i < ntests; ++i) {

    std::cin >> N >> S >> p;

    int min = 3 * p - 2;
    int min_surprising = min - 2;
    int res = 0;
    int score;

    if (p == 0)
      min = 0;
    if (p == 1)
      min_surprising = 1;

    for (int j = 0; j < N; ++j) {
      std::cin >> score;
      if (score >= min)
        ++res;
      else if (S > 0 && score >= min_surprising) {
        --S;
        ++res;
      }
    }
    std::cout << "Case #" << (i + 1) << ": " << res << std::endl;
  }
  return 0;
}
