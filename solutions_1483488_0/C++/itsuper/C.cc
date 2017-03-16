#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;


ifstream input;
ofstream output;
long long f[12];
int icount(long long num,int n,long long up) {
  if ( n == 1) return 0;
  int res = 0;
  vector <long long> vec;
  vec.clear();
  for (int i = 1;i< n;++i) {
    long long k = num / f[i];
    long long t = num % f[i];
    long long newnum = t * f[n-i] + k;
    if (newnum > num && newnum <= up
        && find(vec.begin(),vec.end(), newnum) == vec.end()) {
      vec.push_back(newnum);
      ++res;
    }      
  }
  return res;
}
void Work() {
  long long A, B;
  input >> A >>B;
  int sum = 0;
  int n = 0;
  long long t = B;
  while(t) {
    ++n;
    t/=10;
  }
  for (long long i = A; i<= B;++i) {
    sum += icount(i,n,B); 
  }
  
  //  cout<<sum<<endl;
  output<<sum<<endl;
}
void init() {
  f[0] = 1;
  for (int i = 1;i< 12;++i) {
    f[i] = f[i-1]*10;
  }
}
int main() {
  
int t = 0;
  string inputfile("inputC.in");
  string outputfile("outputC.out");
  input.open(inputfile.c_str());
  output.open(outputfile.c_str());
  input>>t;
  int tcase = 0;
  init();
  while( t--) {
    ++tcase;
    output<<"Case #"<<tcase<<": "; 
    Work();
  }
}
