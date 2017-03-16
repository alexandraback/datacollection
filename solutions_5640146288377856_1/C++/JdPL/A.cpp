#include <iostream>
#include <fstream>

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t caseNum=1; caseNum<=T; caseNum++) {
    std::cout << "Case #" << caseNum << "\n";
    uint64_t R, C, W, solution;
    input >> R >> C >> W;
    solution = (C/W)*R;
    if(C%W==0) {
      solution += W-1;
    } else {
      solution += W;
    }
    output << "Case #" << caseNum << ": ";
    output << solution;
    output << '\n';
  }
}
