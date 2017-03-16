#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
using namespace std;
unsigned long long A,B;

bool is_p(unsigned long long i){
  bool is=true;
  stringstream ss;
  ss<< i;
  string s = ss.str();
  for(unsigned int i=0;i<floor((float)s.size()/2.0f) && is;++i){
    if(s[i]!=s[s.size()-1-i])
      is=false;
  }
  return is;
}

int main(){
  long long T;
  unsigned long long count;
  cin >> T;
  for(int t=1;t<=T;++t){
      cout << "Case #"<<t<<": ";
      cin >> A;
      cin >> B;
      count=0;
      for(unsigned long long i=(unsigned long long)floor(sqrt(A));i<=(unsigned long long)ceil(sqrt(B));++i){
        unsigned long long q = i*i;
        if(q>=A && q<=B && is_p(i) && is_p(q)){
          ++count;
        }
      }
      cout<<count<<endl;
  }
  return 0;
}
