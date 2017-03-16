#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
typedef long double D;
const D EPS = 1e-8;

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    D C,F,X;
    cin >> C >> F >> X;
    D res = 0, cps = 2;
    while(C/cps + X/(cps+F) + EPS < X/cps){
      res += C/cps;
      cps += F;
    }

    cout << "Case #" << casenum << ": ";
    cout << fixed << setprecision(7) << res+X/cps << endl;
  }
}
