#include<iostream>
#include<vector>
#include<map>
#include<string>
#include<queue>
#include<iomanip>
#include<cmath>

__int64 solve(int a,int b,int p,int z,int as,int bs){    
  if(as>=a || bs>=b)return 0;
  if(z==-1)return 1;
  //std::cout << "[" << z << ":" << as << "-" << bs << "]" << std::endl; 
  if(p & (1<<z)){
    as+=1<<z;
    bs+=1<<z;
    if(as>=a || bs>=b)return 0;
    else return solve(a,b,p,z-1,as,bs);
  }else{
    as+=1<<(z+1);
    bs+=1<<(z+1);
    as--;
    bs--;
    if(as<a && bs<b){
      __int64 e=1;
      for(int y=z;y>-1;y--){
        if(!(p & (1<<y)))e*=3;
      }
      //std::cout << "{" << e << "}";
      return e;
    }else{
      as++;
      bs++;
      as-=1<<(z+1);
      bs-=1<<(z+1);
      as+=1<<z;
      bs+=1<<z;
      int s=0;
      as-=1<<z;
      s+=solve(a,b,p,z-1,as,bs);
      bs-=1<<z;
      s+=solve(a,b,p,z-1,as,bs);
      as+=1<<z;
      s+=solve(a,b,p,z-1,as,bs);
      //std::cout << "{|" << s << "|}";
      return s;
    }
  }
}

int main(){
  int probN;
  std::cin >> probN;
  for(int prob=1;prob<=probN;prob++){
    int a,b,k;
    std::cin >> a >> b >> k;
    int ex=28;
    while(a <= (1 << ex) && b <= (1 << ex))ex--;
    ex++;
    __int64 sc=0;
    k=std::min(1<<ex,k);
    for(int p=0;p<k;p++){          
      //std::cout << p << std::endl;
      sc+=solve(a,b,p,ex,0,0);
      //std::cout << "<" << solve(a,b,p,ex,0,0) << ">" << std::endl;
    }
    std::cout << "Case #" << prob << ": ";
    std::cout << sc << std::endl;
  }
  return 0;
}