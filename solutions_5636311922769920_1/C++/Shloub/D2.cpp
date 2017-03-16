#include<iostream>
#include<vector>

int main(){
  unsigned t; std::cin >> t;
  for(unsigned i {0}; i<t; ++i){
    unsigned k, c, s;
    std::cin >> k >> c >> s;  
    std::cout << "Case #" << i+1 << ":";
    if(c*s<k)
      std::cout << " IMPOSSIBLE";
    else{
      std::vector<std::vector<unsigned>> vv {{}};
      for(unsigned j {0}; j<k; ++j)
	if(vv.back().size()<c)
	  vv.back().push_back(j);
	else
	  vv.push_back({j});
      while(vv.back().size()<c)
	vv.back().push_back(0);
      for(const auto& v: vv){
	long long unsigned u {1};
	long long unsigned pow {1};
	for(unsigned p {static_cast<unsigned>(v.size()-1)}; p<v.size(); --p){
	  u += v[p]*pow;
	  pow *= k;
	}
	std::cout << ' ' << u;
      }
    }
    std::cout << '\n';
  }
}
