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

int n,x,y;
int c[105][105];

//probability coint toss n times success at least k
double atleast(int n, int k){
//  printf("atleastf: %d %d\n",n,k);
  int ret=0;
  FR(i,k,n+1) ret+= c[n][i];
//  printf("ret: %d\n",ret);
  return (double)ret / pow(2.0, n);
}

double ries(int n, int s, int y){
//  printf("%d %d %d\n",n,s,y);
  if(n >= s + y + 1) return 1.0;
  if(y==s) {
    if(n==s+s+1) return 1.0; else return 0.0;
  }
//  printf("atleast %d %d\n",n,y+1);
  return atleast(n, y+1);
}

void solve(){
  scanf("%d %d %d",&n,&x,&y);
  int k = 0;
  int r = 0;
  int p = 0;
  while(1) {
    if(n<= p + 2*k+1) break;
    p += 2*k+1;
    r++;
    k += 2;   
    if((int)abs(x)+(int)abs(y) <= 2*(r-1)) { printf("1.0\n"); return; }
  }
  if(abs(x)+abs(y) > 2*(r)) { printf("0.0\n"); return; }
  printf("%.9lf\n",ries(n-p, k, y));
}

int main(){
  FOR(i,101)
    FOR(j,i+1) {
      if(j==0 || j==i) c[i][j] = 1; 
      else c[i][j] = c[i-1][j] + c[i-1][j-1];
    }
  int pvs; scanf("%d",&pvs);
  FR(ppp,1,pvs+1){
     printf("Case #%d: ",ppp);

     solve();
  }
}


// vim: fdm=marker:commentstring=\ \"\ %s:nowrap:autoread
