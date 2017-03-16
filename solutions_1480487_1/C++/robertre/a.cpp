#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>

using namespace std;

void solve() {

  int N;
  cin>>N;
  vector<int> points;
  int total = 0;

  for(int n=0;n<N;++n) {
    int p;
    cin>>p;
    points.push_back(p);
    total+=p;
  }

  for(int n=0;n<N;++n) {
    double mini = 0;
    double maxi = 1;

    //cerr<<"n="<<n<<" points "<<points[n]<<endl;
    while ( fabs(mini-maxi) > 10e-9) {
      double val = (mini + maxi) / 2;
      double avail = 1-val;

      double myscore = points[n] + val * total;
      bool ok=false;
      //cerr<<": val="<<val<<" mypoints "<<myscore<<endl;

      for(int m=0;m<N;++m) {
        if (n==m) continue;
        if (myscore > points[m]) {
          double diff = myscore-points[m];
          diff/=total;
          avail -= diff;
          ok = true;
        }
      }
      //cerr<<"--- AVAIL: "<<avail<<endl;

      if(ok && avail < 0) {
        maxi = val;
      } else {
        mini = val;
      }
    }
    cout<<" "<<mini*100;
  }
}

int main(int argc, char** argv) {
  int T;
  cin>>T;
  for(int t=0;t<T;++t) {
    cout<<"Case #"<<t+1<<":";
    solve();
    cout<<endl;
  }
  return 0;
}
