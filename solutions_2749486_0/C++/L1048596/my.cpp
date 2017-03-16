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
int X, Y;
int maxdepth = 1;

bool check(int x, int y, int k){
  if(abs(x-X)+abs(y-Y)>k*(k+1)/2) return false;
  return true;
}

string ans;

bool dfs(int x, int y, int k){
  if( k == 0 && x==X && y==Y) return true;
  //cout << x << ' ' << y << ' ' << k << endl;
  if( k==0 ) return false;
  if(!check(x,y,k)) return false;
  
  if(dfs(x+k, y, k-1)) { ans.push_back('E'); return true; }
  if(dfs(x-k, y, k-1)) { ans.push_back('W'); return true; }
  if(dfs(x, y+k, k-1)) { ans.push_back('N'); return true; }
  if(dfs(x, y-k, k-1)) { ans.push_back('S'); return true; }

  return false;
}
void solve(){
  static int t=0;


  fin >> X >> Y;
  ans = "";
  maxdepth = 1;
  while(!dfs(0,0,maxdepth)){
    maxdepth++;
    cout << maxdepth << endl;
  }

  fout << "Case #"<< ++t <<": ";
  fout << ans;
  fout << endl;
}
int main(){
 
  int caseN;
  fin >> caseN;
  //fout << fixed << setprecision(7);
  while(caseN--){
    solve();
  }
  return 0;
}
