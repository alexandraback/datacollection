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
#define eps 1e-9
int main() {
  int T;
  long double C,F,X;
  cin>>T;
  int kase = 0;
  while(T--) {
    scanf("%Lf%Lf%Lf",&C,&F,&X);
    printf("Case #%d: ",++kase);
    long double ans = X/2.0;
    long double cum = 0;
    for(int i=1;i<=1000000;i++) {
      cum += C/(2.0 + F*(i-1));
      long double pos = (cum + X/(2.0 + i*F));
      if(ans > pos - eps) {
        ans = pos;
      }
    }
    printf("%.7Lf\n",ans);
  }
  return 0;
}
