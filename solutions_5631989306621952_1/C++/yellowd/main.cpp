#include <iostream>
#include <fstream>
#include <vector>
#include <string>

std::ifstream in("input.txt");
std::ofstream out("output.txt");

int main() {
  int data_size = 0;
  in >> data_size;
  std::vector<std::string> patterns(data_size);
  for (int i = 0; i < data_size; ++i) {
    in >> patterns[i];
  }
  for (int i = 0; i < data_size; ++i) {
    std::vector<char> res(patterns[i].length());
    res[0] = patterns[i][0];
    for (int j = 1; j < patterns[i].length(); ++j) {
      if (res[0] <= patterns[i][j]) {
        res.insert(res.begin(), patterns[i][j]);
      } else {
        res[j] = patterns[i][j];
      }
    }
    out << "Case #" << i + 1 << ": ";
    for (int k = 0; k < patterns[i].length(); ++k) {
      out << char(res[k]);
    }
    out << "\n";
  }
  return 0;
}