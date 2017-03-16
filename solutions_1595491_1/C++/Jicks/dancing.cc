#include <vector>
#include <algorithm>
#include <iostream>

bool comp(int i, int j) { return (i > j); }

int main()
{
  int T; std::cin >> T; std::cin.ignore();

  for (int i = 1; i <= T; i++)
  {
    int total = 0;
    int N; std::cin >> N;
    int S; std::cin >> S;
    int p; std::cin >> p;
    std::vector<int> vect;
    for (int j = 0; j < N; j++)
    {
      int ti; std::cin >> ti; vect.push_back(ti);
    }
    std::sort(vect.begin(), vect.end(), comp);
    for (int j = 0; j < N; j++)
    {
      if (vect[j] < (3 * p - 2))
        break;
      total++;
    }
    while (S > 0 && total < N)
    {
      if (vect[total] < (3 * p - 4) || vect[total] < p)
        break;
      S--; total++;
    }

    std::cout << "Case #" << i << ": " << total << std::endl;
  }
}
