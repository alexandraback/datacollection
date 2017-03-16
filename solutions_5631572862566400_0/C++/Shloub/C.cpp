#include<iostream>
#include<vector>
#include<algorithm>

bool valid(std::vector<int>& order, std::vector<int>& bff, int len){
  for(int i {0}; i<len; ++i){
    if(order[(i+1)%len]!=bff[order[i]] and order[(((i-1)%len)+len)%len]!=bff[order[i]])
      return false;
  }
  return true;
}

int main(){
  int t;std::cin >> t;
  for(int i {0}; i<t; ++i){
    int n; std::cin >> n;
    std::vector<int> bff {};
    for(int j {0}; j<n; ++j){
      int pal; std::cin >> pal;
      bff.push_back(pal-1);
    }
    int r {0};
    std::vector<int> order {};
    for(int j {0}; j<n; ++j)
      order.push_back(j);
    do{
      for(int len = order.size(); len>0; --len){
	if(valid(order, bff, len)){
	  if(len>r)
	    r = len;
	  break;
	} 
      }
    }while(next_permutation(begin(order), end(order)));
    std::cout << "Case #" << i+1 << ": " << r << '\n';
  }
}
