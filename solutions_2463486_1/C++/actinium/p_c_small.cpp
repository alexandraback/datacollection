#include <cstdio>
#include <vector>
#include <sstream>
#include <string>

typedef unsigned long long ull;

bool is_palindrome(ull i){
  std::stringstream ss;
  ss << i;
  std::string snum = ss.str();
  for(ull i=0;i<snum.size();++i){
    if(snum[i]!=snum[snum.size()-1-i])return false;
  }
  return true;
}

int main(){
  std::vector<ull> fair_square;
  for(ull i=1; i<=10000000;++i){
    if(is_palindrome(i)){
      if(is_palindrome(i*i)){
        fair_square.push_back(i*i);
      }
    }
  }
  ull T;
  scanf("%llu",&T);
  for(ull t=1;t<=T;++t){
    ull count = 0;
    ull A,B;
    scanf("%llu %llu",&A,&B);
    for(ull i=0;i<fair_square.size();++i){
      if( (fair_square[i]>=A) && (fair_square[i]<=B) ) count++;
    }
    printf("Case #%llu: %llu\n",t,count);
  }
}
