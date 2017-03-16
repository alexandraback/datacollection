#include <iostream>

#include <vector>
#include <algorithm>
using namespace std;

int normalScore(std::vector<double> n, std::vector<double> k) {

  sort(n.begin(), n.end());
  sort(k.begin(), k.end());
  reverse(n.begin(), n.end());
  reverse(k.begin(), k.end());

  while(!n.empty() && !k.empty()) {
    if(k.back() >= n.back())
      n.pop_back();
    k.pop_back();
  }
  return n.size();
}


int cheatScore(std::vector<double> n, std::vector<double> k) {

  sort(n.begin(), n.end());
  sort(k.begin(), k.end());

  int ret = 0;
  while(!n.empty() && !k.empty()) {
    if(n.back() > k.back()) {
      ++ret;
      n.pop_back();
    }
    k.pop_back();
  }
  return ret;
}

void testCase(unsigned id) {
  unsigned N;
  cin >> N;
  std::vector<double> naomi(N), ken(N);
  for(unsigned i = 0; i < N; ++i)
    cin >> naomi[i];
  for(unsigned j = 0; j < N; ++j)
    cin >> ken[j];
  int y = cheatScore(naomi, ken);
  int z = normalScore(naomi, ken);
  std::cout << "Case #" << id << ": " << y << " " << z << "\n";
}


int main() {
  int T;
  cin >> T;
  for(int i = 1; i <= T; ++i)
    testCase(i);
  return 0;
}
