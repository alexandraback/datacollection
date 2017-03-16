// pre-written code {{{
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <queue>
#include <numeric>
#include <iostream>
#include <cassert>
#include <set>
#define FOR(i,n) for(int _n=n,i=0;i<_n;++i)
#define FR(i,a,b) for(int _b=b,i=a;i<_b;++i)
#define CL(x) memset(x,0,sizeof(x))
#define PN printf("\n");
#define MP make_pair
#define PB push_back
#define SZ size()
#define ALL(x) x.begin(),x.end()
#define FORSZ(i,v) FOR(i,v.size())
#define FORIT(it,x) for(__typeof(x.begin()) it=x.begin();it!=x.end();it++)
using namespace std;
typedef vector<int> VI;
typedef vector<string> VS;
typedef long long LL;
///////////////////////////////////////////////////////////////////////////////////
// }}}


int s[1000];
int n;
double x;

void solve(){
  scanf("%d",&n);  
  FOR(i,n) scanf("%d",&s[i]);
  x=0.0;
  FOR(i,n) x+=s[i];

  FOR(i,n){
    double left=0.0, right=1.0;    
    while(fabs(left-right)>1e-9){
      double c = (left+right)/2;
      double moje = s[i] + x*c;
      double sum=0.0;
      FOR(j,n) if(s[j] < moje) {
        sum += (moje-s[j])/x;
      }
      if(sum<1.0) left = c; else right = c;
    }
    printf("%.8lf ",left * 100);
  }
  PN;
  
}

int main(){
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
