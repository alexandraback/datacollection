#include <iostream>

int main()
{
  int T; std::cin >> T; std::cin.ignore();

  for (int i = 1; i <= T; ++i)
  {
    int A,B; std::cin >> A; std::cin >> B; std::cin.ignore();
    int digits = 0;
    int power = 1;
    int total = 0;

    while (power * 10 < B) { digits++; power *= 10; }

    for (; A <= B; A++)
    {
      int C = A;
      int tab[digits];
      for (int i = 0; i < digits; i++)
        tab[i] = 0;
      for (int i = 0; i < digits; i++)
      {
        C = (C % 10) * power + (C / 10);
        if (C >= A && C <= B && C != A)
        {
          int j = 0;
          for (; j < digits; j++)
            if (C == tab[j]) break;
          if (j == digits) { tab[i] = C; total++; }
        }
      }
    }

    std::cout << "Case #" << i << ": " << total << std::endl;
  }
}
