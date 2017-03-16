#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<iomanip>

int main(){
  int probN;
  std::cin >> probN;
  for(int prob=1;prob<=probN;prob++){
    int n,m,k;
    std::cin >> n >> m >> k;
    std::cout << "Case #" << prob << ": ";
    if(n<=2 || m<=2)std::cout << k;
    else if(k<=4)std::cout << k;
    else if(n*m==k)std::cout << (n+m-2)*2;
    else if(n*m==k+1)std::cout << (n+m-2)*2-1; 
    else if(n*m==k+2)std::cout << (n+m-2)*2-2; 
    else if(n*m==k+3)std::cout << (n+m-2)*2-3;  
    else if(n*m==k+4)std::cout << (n+m-2)*2-4;
    else{
      //Human power
    }
    std::cout << std::endl;
  }
  return 0;
}