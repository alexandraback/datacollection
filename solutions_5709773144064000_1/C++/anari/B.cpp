#include <iostream>
#include <vector>
#include <map>
#include <cstdio>
#include <set>
#include <algorithm>
#include <list>
using namespace std;
int main(){
  int tnum;cin>>tnum;int tcou=0;
  cout<<fixed;
  cout.precision(7);
  while (tnum--){
    double c, f, x; cin>>c>>f>>x;
    cout<<"Case #"<<++tcou<<": ";
    double r=2.;
    double best=x/r;
    double t=0.;
    while (true) {
      double next = t+c/r;
      best = min(best, t+x/r);
      if (next>best)
        break;
      t = next;
      r += f;
    }
    cout<<best<<endl;
  }
  return 0;
}
