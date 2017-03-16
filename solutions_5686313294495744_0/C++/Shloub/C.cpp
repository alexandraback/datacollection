#include<iostream>
#include<string>
#include<map>
#include<array>
#include<deque>
#include<algorithm>
#include<set>

bool possible(std::vector<std::pair<std::string, std::string>> fakes, std::vector<std::pair<std::string, std::string>> trus){
  std::set<std::string> w1s {};
  std::set<std::string> w2s {};
  for(auto t: trus){
    w1s.insert(t.first);
    w2s.insert(t.second);
  }
  for(auto f: fakes){
    if(w1s.find(f.first)==end(w1s))
      return false;
    if(w2s.find(f.second)==end(w2s))
      return false;
  }
  return true;
}

int main(){
  unsigned T; std::cin >> T;
  for(unsigned i {0}; i<T; ++i){
    unsigned n; std::cin >> n;
    unsigned r {};
    std::vector<std::pair<std::string, std::string>> v {};
    for(unsigned j {0}; j<n; ++j){
      std::string w1; std::cin >> w1;
      std::string w2; std::cin >> w2;
      v.push_back({w1, w2});
    }
    bool b {false};
    for(unsigned nbfake {n-1}; nbfake<n; --nbfake){
      if(!b){
	r = nbfake;
	std::string isfake(n-nbfake, '0');
	isfake += std::string(nbfake, '1');
	do{
	  std::vector<std::pair<std::string, std::string>> fakes {};
	  std::vector<std::pair<std::string, std::string>> trus {};
	  for(unsigned j{0}; j<n; ++j){
	    if(isfake[j]=='1')
	      fakes.push_back(v[j]);
	    else
	      trus.push_back(v[j]);
	  }
	  if(possible(fakes, trus)){
	    b = true;
	    break;
	  } 
	}while(std::next_permutation(begin(isfake), end(isfake)));
      }
    }
    std::cout << "Case #" << (i+1) << ": " << r << '\n';
  }
}
