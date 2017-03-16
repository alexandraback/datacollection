#include<iostream>

int main(){
  unsigned t; std::cin >> t;
  for(unsigned i {0}; i<t; ++i){
    unsigned k, c, s;
    std::cin >> k >> c >> s;
    std::cout << "Case #" << i+1 << ":";
    for(unsigned j {1}; j<=s; ++j)
      std::cout << ' ' << j;
    std::cout << '\n';
  }
}
