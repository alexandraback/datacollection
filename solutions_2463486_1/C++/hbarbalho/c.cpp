#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <map>
#include <string>
#include <math.h>
using namespace std;
long long A,B;

bool is_p(long long i){
  long long n = i;
  long long rev=0;
  int digit;
  do
  {
     digit = i%10;
     rev = (rev*10) + digit;
     i = i/10;
  }while (i!=0);
  return n==rev;
}

int main(){
  long long T;
  cin >> T;
  long long len = (long long)floor(sqrt(1e+14))/10;
  long long is_ok[len];
  long long count=0;
  long long n=0;
  for(long long i=1;i<=len*10;++i){
    long long q = i*i;
    if(is_p(i) && is_p(q))
      ++count;
    if(i%10==0){
      is_ok[n++]=count;
      count=0;
    }
  }
  for(long long t=1;t<=T;++t){
      cout << "Case #"<<(t)<<": ";
      cin >> A;
      cin >> B;
      count=0;
      long long limit = (long long)floor(sqrt(B));
      for(long long i=(long long)ceil(sqrt(A));i<=limit;++i){
        long long q = i*i;
        if(q>=A && q<=B){
          if(i%10==0 && i+10<limit){
            count+=is_ok[i/10];
            i+=9;
          }else if(is_p(i) && is_p(q))
            ++count;
        }
      }
      cout<<count<<endl;
  }
  return 0;
}
