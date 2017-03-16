#include<algorithm>
#include<cstdio>
#include<vector>
#include<cmath>
#include<cstring>
#define INF 2000000000
#define REP(i,n) for(int i = 0; i < (n); i++)
#define FOR(i, a, b) for(int i = (a); i < (b); i++)
#define FORD(i, a, b) for(int i = (a); i >= (b); i--)
#define PI pair<int, int>
#define ST first
#define ND second
#define CLR(a, b) memset(a, b, sizeof(a))
#ifdef DEBUG
  #define DBG printf
#else
  #define DBG 
#endif
using namespace std;

int a[209], n, sum;

bool check(int v, double x){
  double r = 1.0 - x, p;
  double m = double(sum) * x + a[v];
  REP(i, n){
    if( i == v) continue;
    if( double(a[i]) >= m ) continue;
    p = (m - double(a[i])) / double(sum);
    r -= p;
    if( r <= 0.0 ) return true;
  }
  return false;
}


double binsearch(int v){
  double l = 0.0, r = 1.0, m;
  while( r - l > 1e-9 ){
    m = (r + l) / 2.0;
    if( check(v, m) ) r = m;
    else l = m;
  }
  return l*100.0;
}

int main(){
  int t;
  scanf("%d",&t);
  int casenum = 0;
  while(t--){
    casenum++;
    scanf("%d",&n);
    sum = 0;
    REP(i, n){ scanf("%d",&a[i]); sum+= a[i];}
    printf("Case #%d:", casenum);
    REP(i, n) printf(" %lf", binsearch(i));
    printf("\n");
  }
  return 0;
}
