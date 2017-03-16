#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

struct dividedPancakes {
  uint64_t pancakes;
  uint64_t divisions;
};

bool invSort(dividedPancakes a, dividedPancakes b) {return a.pancakes*b.divisions>b.pancakes*a.divisions;}

uint64_t minimize(std::vector <dividedPancakes> &portions, uint64_t a, uint64_t deep) {
  uint64_t min, temp;
  if(deep>1000) return 1000;
  min=1+((portions[0]).pancakes-1)/(portions[0]).divisions;
  if(min<4) return min;
  portions[0].divisions++;
  std::sort(&portions[0], &portions[a], invSort);
  temp=1+minimize(portions, a, deep+1);
  if(temp<min) return temp;
  return min;
}

int main() {
  std::ifstream input;
  std::ofstream output;
  uint64_t T;
  input.open("input.in");
  output.open("output.out");
  input >> T;
  for(uint16_t count=1; count<=T; count++) {
    uint64_t a;
    input >> a;
    std::vector <dividedPancakes> portions(a);
    for(uint16_t i=0; i<a; i++) {
      input >> portions[i].pancakes;
      portions[i].divisions=1;
    }
    std::sort(&portions[0], &portions[a], invSort);
    
    output << "Case #" << count << ": ";
    output << minimize(portions, a, 0);
    output << '\n';
    std::cout << "Case #" << count << "\n";
  }
}
