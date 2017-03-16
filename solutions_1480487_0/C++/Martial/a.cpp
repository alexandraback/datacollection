#include <climits>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;


void run(int case_index) {
  int n; cin >> n;
  vector<int> s(n);
  double x=0;
  for(int i = 0; i < n; i++){
    cin >> s[i];
    x+=s[i];
  }
  vector<double> y(n);
  for(int i = 0; i < n; i++){
    double l=0,r=1,m,yy,sy;
    bool possible;
    for(int z = 0; z < 100; z++){
      m=0.5*l+0.5*r;
      sy=0;
      for(int k = 0; k < n; k++){
        yy = m+(s[i]-s[k])/x;
        if(yy<0){
          yy=0;
        }
        sy+=yy;
      }
      possible=sy<=1;
      if(possible){
        l=m;
      }
      else{
        r=m;
      }
    }
    y[i]=100*r;
  }
  cout << "Case #" << case_index << ":";
  for(int i = 0; i < n; i++){
    printf(" %.6f",y[i]);
  }
  cout << endl;
}

int main(int argc, char* argv[]) {
  int n; 
  cin >> n;
  for(int i = 1; i <= n; i++){
    cerr << i << " ";
    run(i);
  }
  cerr << endl;
  return 0;
}
