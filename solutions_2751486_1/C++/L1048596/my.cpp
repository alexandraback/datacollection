/*
ID: nongeek1
PROG: my
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <vector>
#include <iomanip> 
using namespace std;

ifstream fin("my.in");
ofstream fout("my.out");

inline void output(long long ret){
  static int t=0;
  fout << "Case #"<< ++t <<": " << ret << endl;
}
inline void output(string s=""){
  static int t=0;
  fout << "Case #"<< ++t <<": " << s << endl;
}

inline bool equal(double x1, double x2){
 if(fabs(x1-x2)<0.000001) return true;
  return false;
}
int f[26];

string s;
int n;
void solve(){
  fin >> s >> n;
  
  long long ret=0;
  int last = -1;
  for(int i=0; i<s.size(); i++){
    if(f[s[i]-'a']) continue;
    int count = 0;
    int begin = i;
    while(i<s.size() && f[s[i]-'a']==0){
      count++;
      i++;
    }
    if(count==n){
      ret += (long long)(begin-last)*(long long)(s.size()-i+1);
    }
    else if(count>n){
      ret += (long long)((begin-last)+(s.size()-i+1))*(count-n)
              + (long long)(begin-last)*(long long)(s.size()-i+1);
      if(count>=n+2){
        int t = count-2-n+1;
        ret += t*(t+1)/2;
      }
    }
    if(count>=n) last = i-n;
    i--;
  }
  output(ret);
}
int main(){
  f['a'-'a'] = 1;
  f['e'-'a'] = 1;
  f['i'-'a'] = 1;
  f['o'-'a'] = 1;
  f['u'-'a'] = 1;

 
  int caseN;
  fin >> caseN;
  fout << fixed << setprecision(7);
  while(caseN--){
    solve();
  }
  return 0;
}
