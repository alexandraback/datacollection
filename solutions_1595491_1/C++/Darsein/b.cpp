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

int main(){
  int testcase;
  int ans;
  int n,s,p,t[1000];

  cin >> testcase;
  for(int casenum=1;casenum<=testcase;casenum++){
    ans = 0;
    cin >> n >> s >> p;
    for(int i=0;i<n;i++)cin >> t[i];

    for(int i=0;i<n;i++){
      t[i] -= p;
      if(t[i]<0)continue;
      if(t[i]/2>=p-1)ans++;
      else if(s && t[i]/2>=p-2){
	ans++; s--;
      }
    }
    cout << "Case #" << casenum << ": ";
    cout << ans << endl;
  }
}
