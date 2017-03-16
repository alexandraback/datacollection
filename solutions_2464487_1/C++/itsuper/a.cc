#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;
template<class T> void atov(int n,T A[],vector<T> &vi){
  vi.clear();for (int i=0;i<n;i++) vi.push_back(A[i]);
}//NOTES:atov(
template<class T> void stov(string s,vector<T> &vi){
  vi.clear();istringstream sin(s);for(T v;sin>>v;vi.push_bakc(v));
}
template<class T> inline T lowbit(T n){return (n^(n-1))&n;}
template<class T> inline int countbit(T n){return (n==0)?0:(1+countbit(n&(n-1)));}
template <typename T> inline T Gcd( T a, T b) {
  // a, b should be unnegative
  if ( b == 0) return a;
  return Gcd( b, a % b);
}


ifstream input;
ofstream output;

void init() {

}
long long getv(long long t, long long r) {
  long long l = 1, h = t;
  long long res = 1;
  
  while (l <= h) {
    long long mid = (l + h)>>1;
    double tv = (2.0* r)* mid + (2.0 * mid) * (mid + 1) - 3.0 * mid;
    if (tv <= t) {
      res = mid;
      l = mid + 1;
    } else {
      h = mid - 1;
    }
  }
  return res;
}

void Work() {
  long long t, r;
  input>>r>>t;
  long long res = getv(t,r);
  output<<res<<std::endl;
}
int main() {
  
  
int t = 0;
  string inputfile("input.in");
  string outputfile("output.out");
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


