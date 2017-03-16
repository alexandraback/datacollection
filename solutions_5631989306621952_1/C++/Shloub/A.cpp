#include<iostream>

int main(){
  int t;std::cin >> t;
  for(int i {0}; i<t; ++i){
    std::string s; std::cin >> s;
    std::string r {""};
    for(char c: s){
      if(r.size() and c<r[0]){
	r.push_back(c);
      }
      else{
	r.insert(0, 1, c);
      }
    }
    std::cout << "Case #" << i+1 << ": " << r << '\n';
  }
}
