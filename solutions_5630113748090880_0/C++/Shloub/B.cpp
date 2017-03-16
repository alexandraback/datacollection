#include<iostream>
#include<array>

int main(){
  int t;std::cin >> t;
  for(int i {0}; i<t; ++i){
    std::array<int, 2500> count {};
    int n;std::cin >> n;
    for(int j {0}; j<2*n-1; ++j){
      for(int k {0}; k<n; ++k){
	int height; std::cin >> height;
	++count[height-1];
      }
    }
    std::cout << "Case #" << i+1 << ':';
    for(int j {0}; j<2500; ++j){
      if(count[j]%2){
	std::cout << " " << j+1;
      }
    }
    std::cout << '\n';
  }
}
