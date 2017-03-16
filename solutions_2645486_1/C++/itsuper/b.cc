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

int istack[20000];
int f[20000];
int a[20000];
void init() {

}


void Work() {
  long long E,R;
  int n;
  input>>E>>R>>n;
  for (int i = 0; i< n; ++i) {
    input>>a[i];
  }
  int top = -1;
  for (int i = n-1; i>=0; --i) {
    while ((top >=0) && (a[istack[top ]]) <= a[i]) --top;
    if ( top == -1) {
      f[i] = -1;
    } else {
      f[i] = istack[top];
    }
    istack[++top] = i;
  }
  long long res = 0, curE = E;
  for (int i = 0; i< n; ++i) {
    int nexti = f[i];
    //std::cout<<"next "<<i<<" = "<<nexti<<std::endl;
    if (nexti == -1) {
      res += curE * a[i];
      curE = 0;
    } else {
      long long g = (nexti - i) * R;
      g = max(g + curE - E, 0LL);
      g = min(g, curE);
      res += g * a[i];
      curE -= g;
    }
    curE += min(R, E);
  }
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
