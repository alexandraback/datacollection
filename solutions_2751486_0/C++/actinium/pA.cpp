#include <cstdio>
#include <string>
#include <vector>
#include <iostream>

// vowels: a, e, i, o, and u
// consonants:
bool vowel(const char& c){
  return (c=='a') || (c=='e') || (c=='i') || (c=='o') || (c=='u');
}

int main(){
  int T;
  scanf("%d",&T);
  for(int t=1; t<=T; ++t){
    std::string s;
    unsigned n;
    std::cin >> s >> n;
    std::vector<unsigned> conson;
    //----------------------------------------
    unsigned count = 0;
    for(unsigned i=0;i<s.size();++i){
      if(!vowel(s[i])){
        count++;
      }else{
        count = 0;
      }
      if(count >= n){
        conson.push_back(i-n+1);
      }
    }
    //----------------------------------------
    unsigned long long res = 0;
    unsigned limit = 0;
    for(unsigned i=0; i < conson.size(); ++i){
      res += (conson[i]-limit+1)*(1 + s.size()-(conson[i]+n));
      limit = conson[i]+1;
    }
    //----------------------------------------
    printf("Case #%d: %llu\n",t,res);
  }
}
