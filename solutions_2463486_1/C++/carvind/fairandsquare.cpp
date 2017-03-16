#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<long long> limit;

bool isPalin(long long x){
  int size = floor(log10(x)) + 1;
  char str[size];
  sprintf(str, "%lld", x);
  for(int i=0; i<size/2; i++){
    if(str[i] != str[size-i-1])
      return false;
  }
  return true;
}

int getCount(long long A){
  if(A==0){
    return 0;
  }
  else {
    int index = 0;
    for(int i=0; i<limit.size(); i++){
      if(limit[i] <= A){
        index++;
      }
    }
    return index;
  }
}

int main(int argc, char* argv[]){
  int tests;
  cin>>tests;
  int index=1;
  long long A,B;
  A = 1LL;
  B = (long long)pow(10, 14);
  long long start = sqrt(A);
  long long sqr = start * start;
  while(sqr <= B){
    if(sqr<A){
      start++;
      sqr = start*start;
      continue;
    }
    if(isPalin(start)){
      if(isPalin(sqr)){
        limit.push_back(sqr);
      }
    }
    start++;
    sqr = start*start;
  }
  while(index <= tests){
    cin>>A>>B;
    int countB = getCount(B);
    int countA = getCount(A-1);
    cout<<"Case #"<<index<<": "<<countB-countA<<endl;
    index++;
  }
  return 0;
}
