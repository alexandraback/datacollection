#include <cstdio>
#include <vector>
#include <sstream>
#include <string>

bool is_palindrome(int i){
  std::stringstream ss;
  ss << i;
  std::string snum = ss.str();
  for(int i=0;i<snum.size();++i){
    if(snum[i]!=snum[snum.size()-1-i])return false;
  }
  return true;
}

int main(){
  std::vector<int> fair_square;
  for(int i=1; i*i<=1000;++i){
    if(is_palindrome(i) && is_palindrome(i*i)){
      fair_square.push_back(i*i);
      //printf("%d,%d\n",i,i*i);
    }
  }
  int T;
  scanf("%d",&T);
  for(int t=1;t<=T;++t){
    int count = 0;
    int A,B;
    scanf("%d %d",&A,&B);
    for(int i=0;i<fair_square.size();++i){
      if( (fair_square[i]>=A) && (fair_square[i]<=B) ) count++;
    }
    printf("Case #%d: %d\n",t,count);
  }
}
