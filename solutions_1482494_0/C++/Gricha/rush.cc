#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

struct myclass {
  bool operator() (pair<int,int> a, pair<int,int> b){
    return a.second > b.second;
  }
} myobject;

struct myclass2 {
  bool operator() (pair<int,int> a, pair<int,int> b){
    return a.first <  b.first;
  }
} myobject2;



int main(){
  int T;
  cin >> T;
  for (int z=0; z<T;z++){
    int n; 
    cin >> n;
    int dummy, dum2;
    vector<pair<int,int> > star;
    for (int i=0; i<n; i++){
      cin >> dummy >> dum2;
      star.push_back(make_pair(dummy,dum2));
    }
    int stars = 0;
    int ruchy = 0;

    while(1){
      int dwa = -1;
    sort (star.begin(), star.end(), myobject);
      for (int i=0; i<star.size(); i++){
        if (star[i].second <= stars){
          dwa = i;
          break;
        }
      }

      if (dwa >=0) {
        ruchy++;
        stars += 2;
        star.erase(star.begin() + dwa);
      } else {
    sort (star.begin(), star.end(), myobject2);
        for (int i=0; i<star.size(); i++){
          if (star[i].first <= stars){
            dwa = i;
            break;
          }
        }

        if (dwa >= 0){
          ruchy++;
          stars += 1;
          star[dwa].first = star[dwa].second;
          star[dwa].second = 1000000;
          if (star[dwa].first == star[dwa].second)
            star.erase(star.begin() + dwa);
        }
       else {

        break;
      }}
 /*
      for (int j=0; j<n; j++){
        cout << star[j].first << " " << star[j].second << endl;
      } cout << "***" << endl;*/
    }

    if (!star.empty()){
      printf("Case #%d: Too Bad\n", z+1);
    } else {
      printf("Case #%d: %d\n", z+1, ruchy);
    }
  
  
  
  
  }
  return 0;
}
