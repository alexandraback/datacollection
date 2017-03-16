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

#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;

int main(){
  int testcase;
  string ans;

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    int n,m;
    int a[110][110];
    cin >> n >> m;
    rep(i,n)rep(j,m)cin >> a[i][j];

    ans = "YES";
    for(int x=0;x<n*m;x++){
      int minv=10000,h,w;
      rep(i,n)rep(j,m){
	if(a[i][j] >=0 && minv>a[i][j]){
	  minv = a[i][j], h = i; w = j;
	}
      }
      if(minv==10000)break;

      bool f = true;
      rep(i,n){
	if(minv<a[i][w]){f = false; break;}
      }
      if(f){ rep(i,n)a[i][w] = -1; continue; }

      f = true;
      rep(i,m){
	if(minv<a[h][i]){f = false; break;}
      }
      if(f){ rep(i,m)a[h][i] = -1; continue; }

      ans = "NO";
      break;
    }

    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
