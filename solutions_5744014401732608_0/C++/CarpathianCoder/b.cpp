#define MAX_B 50
#include <iostream>
#include <algorithm>

int grid[MAX_B][MAX_B];

long long count_ways(int pos, int b) {
  if (pos == b - 1) {
    return 1LL;
  } else {
    return 1LL << (b - 2 - pos);
  }
}

void solve_case(int case_num)
{
  int b;
  long long m;

  std::cin >> b >> m;
  std::cout << "Case #" << case_num << ": ";

  long long base = 1LL;
  base <<= b - 2;
  if (m > base) {
    std::cout << "IMPOSSIBLE" << std::endl;
  } else {
    std::cout << "POSSIBLE" << std::endl;
    for (int i = 0; i < b; i++) {
      std::fill(grid[i], grid[i] + b, 0);
    }
    int k = -1;
    for (long long x = 1LL; x <= m; x <<= 1) {
      k++;
    }
    for (int i = b - 2 - k; i < b; i++) {
      for (int j = i + 1; j < b; j++) {
	grid[i][j] = 1;
      }
    }

    if (b - 2 - k > 0) {
      for (int i = b - 2 - k; i < b; i++) {
        long long e = count_ways(i, b);
        if (e <= m) {
	  m -= e;
	  grid[0][i] = 1;
	}
      }
    }

    /*
    for (int i = b - 2 - k; i < b; i++) {
      std::cout << "i: " << i << " - " << count_ways(i, b) << std::endl;
    }
    */

    for (int i = 0; i < b; i++) {
      for (int j = 0; j < b; j++) {
	std::cout << grid[i][j];
      }
      std::cout << std::endl;
    }
  }
}

int main()
{
  int num_cases;

  std::cin >> num_cases;
  for (int i = 1; i <= num_cases; i++) {
    solve_case(i);
  }
  
  return 0;
}
