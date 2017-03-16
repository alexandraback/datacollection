
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <cmath>

int studyCase();

int main(int argc, char** argv) {

  int nCases;
  std::cin >> nCases;
  std::string line;
  for(int i=1; i<=nCases; i++) {
    int time = studyCase();
    std::cout << "Case #" << i << ": " << time << std::endl;
  }

  return 0;
}

int studyCase() {
  int d;
  std::cin >> d;
  std::vector<int> pi(d);
  for(int i=0; i<d; i++) {
    std::cin >> pi[i];
  }

  /*
  for(int i=0; i<d; i++) {
    std::cout << pi[i] << " ";
  }
  std::cout << std::endl;
  */

  int highest = *(std::max_element(pi.begin(), pi.end()));
  std::vector<int> costs(highest);
  for(int i=0; i<highest; i++) {
    int nSpec = 0;
    for(int j=0; j<d; j++) {
      if(pi[j]>i+1) {
        nSpec += int(ceil(pi[j]*1.0/(i+1)))-1;
      }
    }
    costs[i] = nSpec + i + 1;
  }

  return *(std::min_element(costs.begin(), costs.end()));
}
