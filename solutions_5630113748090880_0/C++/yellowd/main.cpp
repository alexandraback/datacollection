#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::ifstream in("input.txt");
std::ofstream out("output.txt");

int main() {
  int data_size = 0;
  in >> data_size;
  std::vector<int> heights(2500, 0);
  for (int i = 0; i < data_size; ++i) {
    int N;
    in >> N;
    int val;
    for (int index = 0; index < 2*N - 1; ++index) {
      for (int j = 0; j < N; ++j) {
        in >> val;
        heights[val - 1] += 1;
      }
    }
    out << "Case #" << i + 1 << ": ";
    for (int j = 0; j < 2500; ++j) {
      if (heights[j] % 2 != 0) {
        out << j + 1 << ' ';
      }
      heights[j] = 0;
    }
    out << "\n";
  }
  return 0;
}
