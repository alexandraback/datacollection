#include <iostream>
#include <cmath>
#include <map>
#include <utility>
#include <iomanip>
using namespace std;

map<pair<pair<double,double>,double>,double> m;
double c,f,ut;
double mintime(double x, double r, double t){
  if (m.count(make_pair(make_pair(x,r),t))>0) return t+m[make_pair(make_pair(x,r),t)];
  if (t>=ut) return ut;
  if (c>=x) return t+x/r;
  double t1 = mintime(x-c,r,t+c/r);
  double t2 = mintime(x,r+f,t+c/r);
  if (t1>t2){
    ut = t2;
  }
  else{
    ut = t1;
  }
  m[make_pair(make_pair(x,r),t)] = ut;
  return ut;
}

int main(){
  int ti,i,j,k,n;
  double x,s,t,r;
  cin>>ti;
  for (i=1; i<=ti; i++){
    if (i>1) cout << endl;
    cout << "Case #" << i << ": ";
    cin>>c>>f>>x;
    s = c/2;
    ut = x/2;
    t = x/2;
    r=2;
    while(t<=ut){
      t = s + x/(r+f);
      s+=c/(r+f);
      r+=f;
      if (t<ut) ut=t;
    }
    //s = mintime(x,2.0,0);
    cout << setprecision(7) << fixed << ut;
  }
  return 0;
}

