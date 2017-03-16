#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>

static double calc_water_level(int n, std::vector<int> & points, double water) {
    std::vector<int> sorted_points = points;
    std::sort(sorted_points.begin(), sorted_points.end());

    for (int i = 0; i < n - 1; i++) {
        int needed = (sorted_points[i+1] - sorted_points[i]) * (i+1);
        if (water <= needed)
            return sorted_points[i] + (water / (i+1));
        water -= needed;
    }
    return sorted_points[n-1] + (water / n);
}

int main(void)
{
    int ncases;

    std::cin >> ncases;
    std::cin.ignore();
    for (int casenr = 1; casenr <= ncases; casenr++) {
      int n;
      std::vector<int> points;
      int sum = 0;

      std::cin >> n;
      for (int i = 0; i < n; i++) {
          int s;
          std::cin >> s;
          points.push_back(s);
          sum += s;
      }
      std::cin.ignore();

      double water_level = calc_water_level(n, points, sum);
      std::cerr << "water level " << water_level << " ";
      
      std::cout << "Case #" << casenr << ":";
      std::cerr << "Case #" << casenr << ":";
      std::cout << std::setprecision(9);
      std::cerr << std::setprecision(9);
      for (int i = 0; i < n; i++) {
          double needed;
          if (points[i] >= water_level)
              needed = 0;
          else
              needed = 100 * (water_level - points[i]) / sum;
          std::cout << " " << needed;
          std::cerr << " " << needed;
      }
      std::cout << "\n";
      std::cerr << "\n";
    }
}
