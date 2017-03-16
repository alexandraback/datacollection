#include <iostream>
#include <string>
#include <sstream>
#include <vector>

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
  int smax;
  std::string people;
  std::cin >> smax >> people;
  std::vector<int> nPeople(smax+1);
  for(int i=0; i<smax+1; i++) {
    nPeople[i] = people[i]-'0';
  }

  int y = 0;
  int nStand = 0;
  for(int i=0; i<smax+1; i++) {
    if(!nPeople[i]) continue;
    if(nStand < i) {
      y += (i-nStand);
      nStand = i;
    }
    nStand += nPeople[i];
  }

  return y;
}
