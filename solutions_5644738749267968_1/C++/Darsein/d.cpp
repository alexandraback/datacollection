#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
using namespace std;
typedef long double D;
const D EPS = 1e-8;

int n;
D a[1010],b[1010];

int main(){
  int testcase;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    cin >> n;
    rep(i,n)cin >> a[i];
    rep(i,n)cin >> b[i];
    sort(a,a+n); sort(b,b+n);

    int ans1 = 0, ans2 = 0;
    int id = 0;
    rep(i,n){
      while(id<n && a[id]<b[i])id++;
      if(id==n)break;
      ans1++;
      id++;
    }

    id = 0;
    rep(i,n){
      while(id<n && b[id]<a[i])id++;
      if(id==n)break;
      ans2++;
      id++;
    }

    cout << "Case #" << casenum << ": ";
    cout << ans1 << " " << n-ans2 << endl;
  }
}
