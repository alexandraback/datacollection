#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <vector>

size_t max_fake_count;

void Solve(std::vector<std::string> &s1, std::vector<std::string> &s2, 
  std::map<std::string, size_t> &s1_count, std::map<std::string, size_t> &s2_count, 
  size_t index, size_t fake_count) {

  if (index == s1.size()) {
    max_fake_count = std::max(fake_count, max_fake_count);
    return;
  }

  Solve(s1, s2, s1_count, s2_count, index + 1, fake_count);

  if (s1_count[s1[index]] > 1 && s2_count[s2[index]] > 1) {
    //std::cout << i << " " << s1[i] << " " << s2[i] << "\n";
    --s1_count[s1[index]];
    --s2_count[s2[index]];
    Solve(s1, s2, s1_count, s2_count, index + 1, fake_count + 1);
    ++s1_count[s1[index]];
    ++s2_count[s2[index]];
  }
}

int main() {
  size_t T;
  std::cin >> T;
  for (size_t t = 1; t <= T; ++t) {
    size_t N;
    std::cin >> N;
    std::vector<std::string> s1(N), s2(N);
    std::map<std::string, size_t> s1_count, s2_count;
    for (size_t i = 0; i < N; ++i) {
      std::cin >> s1[i] >> s2[i];
      ++s1_count[s1[i]];
      ++s2_count[s2[i]];
    }
    max_fake_count = 0;
    Solve(s1, s2, s1_count, s2_count, 0, 0);
    std::cout << "Case #" << t << ": " << max_fake_count << "\n";
  }
  return 0;
}
