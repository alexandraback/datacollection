#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<complex>
#include<map>
#include<list>
#include<deque>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
using namespace std;

typedef long long ll;

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ll e,r,n,v,ans = 0,ma=0;

    cin >> e >> r >> n;
    ll k = min(e,r);
    for(int i=0;i<n;i++){
      cin >> v; ans += k*v; ma=max(v,ma);
    }
    ans += ma*max(0LL,e-r);
    
    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
