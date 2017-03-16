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
const int maxsize = 100;

int wall[401];
int bias = 200;


struct Attack{
  int west, east;
  int strength;
  int day;
  Attack(int d, int w,int e,int s):west(w),east(e),strength(s),day(d){}
};

vector<Attack> att;

bool check(const Attack &a){
  for(int i=a.west; i<=a.east; i++){
    if(wall[i]<a.strength) return true;
  }
  return false;
}
void repair(const Attack &a){
  for(int i=a.west; i<=a.east; i++){
    wall[i] = max(wall[i], a.strength);
  }
}
void solve(){
  int N;
  int d;
  int n;
  int w;
  int e;
  int s;
  int dd;
  int dp;
  int ds;
  att.clear();
  fin >> N;
  for(int i=1; i<=N; i++){
    fin >> d >> n >> w >> e >> s >> dd >> dp >> ds;
    w = w + bias;
    e = e + bias;
    for(int j=0; j<n; j++){
      Attack x(d+dd*j, w+dp*j, e+dp*j-1, s+ds*j);
      att.push_back(x);
    }
  }

  for(int i=1; i<att.size(); i++)
    for(int j=0; j<att.size()-i; j++){
      if(att[j].day>att[j+1].day) 
        swap(att[j],att[j+1]);
    }
  for(int i=0; i<att.size(); i++)
     cout << att[i].day << ' ';
   cout << endl;
  int ret=0;

  for(int i=0; i<=400; i++) wall[i] = 0;

  for(int i=0; i<att.size(); i++){
    int j;
    for(j=i; j<att.size() && att[j].day==att[i].day; j++) ;
    j--;
    for(int k=i; k<=j; k++){
      if(check(att[k])) ret ++;
    }
    for(int k=i; k<=j; k++){
      repair(att[k]);
    }
  }
  output(ret);
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
