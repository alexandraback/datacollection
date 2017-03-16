#include<bits/stdc++.h>
using namespace std;

#define CLR(a,x) memset(a,x,sizeof(a))
#define PB push_back
#define INF 1000000000
#define MOD 1000000007
#define MP make_pair
#define tr(container , it) for(typeof(container.begin()) it=container.begin() ; it!=container.end() ; it++)
#define FOR(i,a,b) for(i=a;i<b;i++)
#define REP(i,a) FOR(i,0,a)
#define LL long long
#define VI vector < int >
#define PII pair < int , int >

int t, n;
long long d[2], h[2], m[2];
bool check(int ind1, int ind2) {
  if(m[ind2]*360 + m[ind2]*(360-d[ind2]) <= (360-d[ind1])*m[ind1]) {
    return true;
  }
  return false;
}
int main() {
  int kase = 1;
  scanf("%d",&t);
  while(t--) {
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
      scanf("%lld%lld%lld",&d[i], &h[i], &m[i]);
    }
    if(n == 1) {
      d[1] = d[0];
      m[1] = m[0] + 1;
    }
    int ans = 0;
    if(check(0,1) or check(1, 0)) {
      ans = 1;
    }
    cout<<"Case #"<<kase++<<": "<<ans<<endl;
  }
  return 0;
}
