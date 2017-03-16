#include<iostream>
#include<algorithm>
#include<set>
#include<vector>
#include<map>
#include<deque>
#include<queue>
#include<complex>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>

using namespace std;

#define REP(i,a,n) for(int i = a ; i < n ; i++)
#define rep(i,n) REP(i,0,n)

typedef long long ll;

int main(){
  int T;
  cin>>T;
  for(int t = 1 ; t <= T ; t++){
    int n , s , p;
    int ans = 0;
    int count = 0;
    cin>>n>>s>>p;
    int th =  3 * p -4;
    for(int i = 0 ; i < n ; i++){
      int c;
      cin>>c;
      if(c > th + 1)ans++;
      else if(c == th || c== th+1)count++;
    }
    if(p >= 2)
      ans += min(s,count);
    cout<<"Case #"<<t<<": "<<ans<<endl;
  }
}
