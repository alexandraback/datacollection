#include <iostream>
#include <fstream>
#include <vector>
#include <string>

int main()
  {
  long cases;
  
  std::ifstream fin(L"B-large.in");
  std::ofstream fout(L"B-large.out");
  std::istream& in = fin;
  std::ostream& out = fout;
  
  /*
  std::istream& in = std::cin;
  std::ostream& out = std::cout;
  */
  in >> cases;
  for (long case_i = 1; case_i <= cases; ++case_i)
    {
    int b;
    long long m;
    in >> b >> m;

    long long max = 1;
    for (int i = 2; i < b; ++i)
      max *= 2;
    if (m > max)
      {
      out << "Case #" << case_i << ": IMPOSSIBLE" << std::endl;
      continue;
      }

    std::vector<std::vector<int>> matrix(b, std::vector<int>(b, 0));
    for (int i = 0; i < b - 1; ++i)
      for (int j = i + 1; j < b - 1; ++j)
        matrix[i][j] = 1;
    
    for  (int i = b - 2; i >= 0; --i)
      {
      if (m == 0)
        break;
      max /= 2;
      if (m >= max)
        {
        matrix[i][b-1] = 1;
        m -= max;
        }
      }
      
    out << "Case #" << case_i << ": POSSIBLE" << std::endl;
    for (int i = 0; i < b; ++i)
      {
      for (int j = 0; j < b; ++j)
        out << matrix[i][j];
      out << std::endl;
      }
    }

  return 0;
  }