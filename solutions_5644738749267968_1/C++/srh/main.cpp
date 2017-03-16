#include <algorithm>
#include <iostream>
#include <vector>

int main() {
  int T;
  std::cin >> T;
  for (int casenum = 1; casenum <= T; ++casenum) {
    int N;
    std::cin >> N;
    std::vector<double> naomi(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> naomi[i];
    }
    std::vector<double> ken(N);
    for (int i = 0; i < N; ++i) {
      std::cin >> ken[i];
    }

    std::sort(naomi.begin(), naomi.end());
    std::sort(ken.begin(), ken.end());
    int deceitful_points = 0;
    {
      int i = 0;
      int x = 0;
      int y = N;

      while (i != N) {
	if (naomi[i] > ken[x]) {
	  ++deceitful_points;
	  ++i;
	  ++x;
	} else {
	  ++i;
	  --y;
	}
      }
    }

    int honest_points = 0;
    {
      int x = 0;
      int y = N;
      for (int i = N - 1; i >= 0; --i) {
	if (naomi[i] > ken[y - 1]) {
	  ++honest_points;
	  ++x;
	} else {
	  --y;
	}
      }
    }

    std::cout << "Case #" << casenum << ": "
	      << deceitful_points << " " << honest_points << std::endl;




  }
}
