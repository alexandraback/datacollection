#include <iostream>
#include <cstdio>
#include <cmath>

using namespace std;

bool isPalin(int x){
  int size = floor(log10(x)) + 1;
  char str[size];
  sprintf(str, "%d", x);
  for(int i=0; i<size/2; i++){
    if(str[i] != str[size-i-1])
      return false;
  }
  return true;
}

int main(int argc, char* argv[]){
  int tests;
  cin>>tests;
  int index=1;
  while(index<=tests){
    int A,B;
    cin>>A>>B;
    int start = sqrt(A);
    int sqr = start * start;
    int count=0;
    while(sqr <= B){
      if(sqr<A){
        start++;
        sqr = start*start;
        continue;
      }
      if(isPalin(start)){
        if(isPalin(sqr)){
          count++;
        }
      }
      start++;
      sqr = start*start;
    }
    cout<<"Case #"<<index<<": "<<count<<endl;
    index++;
  }
  return 0;
}
