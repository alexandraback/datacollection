#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <ctime>
#include <queue>
#define LL long long
using namespace std;

template<typename T>
ostream& operator<<(ostream& s, const vector<T>& v) {
    s << '{';
    for (int i = 0 ;i <  v.size(); ++i) {
        s << (i ? "," : "") << v[i];
    }
    return s << '}';
}

template<typename T, typename U>
ostream& operator<<(ostream& s, const pair<T,U>& p) {
  s << "(" << p.first << "," << p.second << ")";
  return s;
}


int main(){

  int ncases; cin>>ncases;

  for(int nc = 1; nc <= ncases; nc++) {

    double C;cin>>C; // cost of factory
    double F;cin>>F; // production of factory
    double X;cin>>X; // target

    double cookies = 0;
    double time = 0;
    double factories = 0;

    while(1) {

      double time1 = time + (X-cookies)/(2+(F*factories));

      double save_for_factory = C / (2+F*factories);
      double time2 = time + save_for_factory + (X-cookies)/(2+F*(factories+1));

      //cout<<time1<< " " <<time2<<endl;

      if(time1 < time2){
        time = time1;
        break;
      }

      time += save_for_factory;
      factories += 1;

    }

    printf("Case #%d: %9.7lf\n",nc,time);

  }



}


