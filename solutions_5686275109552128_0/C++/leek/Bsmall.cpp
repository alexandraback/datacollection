#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int T;
int D;
vector<int> P;

int sp(int x) {
  int ret = 0;

  for(int i=0; i<P.size(); i++) {
    ret += (P[i]-1)/x;
  }
  return ret;
}

int main () {

  cin >> T;

  for(int tc=1;tc<=T;tc++) {
    P.clear();
    cin >> D;
    P = vector<int> (D,0);
    int ret = 999999;
    for(int i=0; i<D; i++) {
      cin >> P[i];
    }

    for(int x=1; x<=1000; x ++) {
      ret = min(ret, x + sp(x));
    }


    printf("Case #%d: %d\n",tc,ret);


  }

  return 0;
}