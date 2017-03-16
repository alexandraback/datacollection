#include<iostream>
#include<string>
#include<set>

int main(){
  unsigned t; std::cin >> t;
  for(unsigned i {0}; i<t; ++i){
    long long unsigned n; std::cin >> n;
    std::string r {"INSOMNIA"};
    if(n){
      long long unsigned j {n};
      for(std::set<unsigned> s {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};s.size();){
	for(char c: std::to_string(j))
	  s.erase(std::stoi(std::string(1, c)));
	if(!s.size())
	  r = std::to_string(j);
	j += n;
      }
    }
    std::cout << "Case #" << i+1 << ": " << r << '\n';
  }
}
