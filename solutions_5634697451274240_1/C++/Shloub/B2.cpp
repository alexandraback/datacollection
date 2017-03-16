#include<iostream>
#include<string>
#include<algorithm>

unsigned solve(std::string s){
  if(s==std::string(s.size(), '+'))
    return 0;
  if(s.back()=='+'){
    unsigned m {static_cast<unsigned int>(s.rfind('-'))};
    return solve(s.substr(0, m+1));
  }
  if(s.front()=='-'){
      std::reverse(s.begin(), s.end());
      for(char& c: s)
	c=(c=='+')?'-':'+';
      return 1+solve(s);
  }
  unsigned m {static_cast<unsigned int>(s.find('-'))};
  std::string head(m, '-');
  return 1+solve(head+s.substr(m));
}

int main(){
  unsigned t; std::cin >> t;
  for(unsigned i {0}; i<t; ++i){
    std::string s; std::cin >> s;
    std::cout << "Case #" << i+1 << ": " << solve(s) << '\n';
  }
}
