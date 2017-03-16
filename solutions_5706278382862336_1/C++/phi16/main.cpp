#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<iomanip>

__int64 gcd(__int64 p,__int64 q){
  if(q!=0)return gcd(q,p%q);
  else return p;
}

int main(){
  int probN;
  std::cin >> probN;
  for(int prob=1;prob<=probN;prob++){
    __int64 p,q;
    std::cin >> p;
    char c;
    std::cin.get(c);
    std::cin >> q;
    std::cout << "Case #" << prob << ": ";
    __int64 g=gcd(p,q);
    p/=g;
    q/=g;
    if(q==(q&-q)){
      if(q==1)std::cout << 0 << std::endl;
      else{
        int c=1;
        while(p*2<q)q/=2,c++;
        std::cout << c << std::endl;
      }
    }else{
      std::cout << "impossible" << std::endl;
    }
  }
  return 0;
}