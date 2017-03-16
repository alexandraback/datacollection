#include<iostream>
#include<string>
#include<map>
#include<array>
#include<deque>
#include<algorithm>

int main(){
  unsigned T; std::cin >> T;
  std::array<std::string, 10> digits {{"ZERO", "ONE", "TWO", "THREE", "FOUR", "FIVE", "SIX", "SEVEN", "EIGHT", "NINE"}};
  std::array<char, 10> tochar {{'0', '1', '2', '3', '4', '5', '6', '7', '8' ,'9'}};
  std::array<std::map<char, unsigned>, 10> letters {};
  for(unsigned i {0}; i<10; ++i){
    std::map<char, unsigned> lcount {};
    for(char c: digits[i])
      ++lcount[c];
    letters[i] = lcount;
  }
  for(unsigned i {0}; i<T; ++i){
    std::string r {};
    std::string s; std::cin >> s;
    std::map<char, unsigned> count {};
    for(char c: s)
      ++count[c];
    std::map<std::string, std::map<char, unsigned>> remains {};
    remains[""] = count;
    std::deque<std::string> d {""};
    while(d.size()){
      std::string cur {d.front()};
      d.pop_front();
      for(unsigned j {0}; j<10; ++j){
	std::string nei {cur};
	nei.push_back(tochar[j]);
	std::sort(begin(nei), end(nei));
	if(remains.find(nei)==end(remains)){
	  std::map<char, unsigned> nei_rem {remains[cur]};
	  bool b {true};
	  for(auto p: letters[j]){
	    if(nei_rem[p.first]<p.second)
	      b = false;
	    nei_rem[p.first]-=p.second;
	  }
	  if(b){
	    unsigned sum {0};
	    for(auto p: nei_rem)
	      sum += p.second;
	    if(sum==0){
	      r = nei;
	      d = {};
	      break;
	    }
	    remains[nei] = nei_rem;
	    d.push_back(nei);
	  }
	}
      }
    }
    std::cout << "Case #" << (i+1) << ": " << r << '\n';
  }
}
