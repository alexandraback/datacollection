#include <iostream>
#include <fstream>
#include <stdio.h>
using namespace std;

ifstream fin("B-large.in");
ofstream fout("my.out");


const int MAX = 1000;
int a[MAX+1];

bool isOk(int t, int n){
  for(int k=0; k<t; k++){
    int basetime = t-k;
    int rest = k;
    for(int i=1; i<=n; i++)
      if(a[i]>basetime){
        int part = (a[i]+basetime-1)/basetime;
        rest = rest - (part - 1);
        if(rest < 0) break;
      }
    if(rest >= 0) return true;
  }
  return false;
}
int foo(){
  int n;
  fin >> n;
  for(int i=1; i<=n; i++){
    fin >> a[i];
  }
  int ret = 1;
  while(isOk(ret, n) == false ) ret++;
  return ret;
  // int left = 1, right = MAX;

  // while(right - left > 0){
  //   int mid = (left + right)/2;
  //   if(isOk(mid, n)){
  //     right = mid;
  //   }
  //   else{
  //     left = mid + 1;
  //   }
  // }
  
  // return right;
}
int main(){
  int M;
  fin >> M;

  //cout << M << endl;
  for(int index=1; index<=M; index++){
    fout << "Case #" << index << ": " << foo() << endl;
  }
  return 0;
}