//Tadrion
#include <cstdio>
#include <vector>
#include <iostream>
#include <deque>
#include <map>
#include <set>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <queue>
#include <stack>
#include <algorithm>
#include <utility>
using namespace std;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define CLEAR(x) (memset(x,0,sizeof(x)))
#define SZ(x) ((int)(x).size())
#define ALL(x) (x).begin(),(x).end()
#define VAR(v, n) __typeof(n) v = (n)
#define FOR(x, b, e) for(int x = b; x <= (e); ++x)
#define FORD(x, b, e) for(int x = b; x >= (e); --x)
#define REP(x, n) for(int x = 0; x < (n); ++x)
#define FOREACH(i, c) for(VAR(i,(c).begin()); i != (c).end(); ++i)
#define DBG(v) cout<<#v<<" = "<<v<<endl; 
#define IN(x,y) ((y).find(x)!=(y).end())
#define ST first
#define ND second
#define PB push_back
#define PF push_front
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T, N;
int s[300];
double eps = 1e-7;
double res[300];
int main() {
  scanf("%d",&T);
  FOR(tttt,1,T) {
    double sum=0;
    scanf("%d",&N);
    for(int i = 0; i < N; i++) {
      scanf("%d",&s[i]);
      sum+=(double)s[i];
    }
    
    
    for(int i = 0; i < N; i++) {
      double b = 0;
    double e = 100.0;
    
      while(fabs(e-b) > eps) {
	///	printf("binse\n");
	
	double m = (e+b)/2.0;
	//	printf("%lf\n",m);
	double res = (double)s[i] + (m*sum)/100.0;
	//printf("res:%lf\n",res);
	double pula = 100.0 - m;
	for(int j = 0; j < N; j++) {
	  if(j!= i && s[j] < res) {
	    double kk = s[j];
	    //printf("brakuje: %d %lf\n",j,100*(res-kk)/sum);
	    pula -= ((res-kk)*100.0) / sum;
	  }
	}
	if(pula < 0) e=m;
	else b=m;
      }
      res[i] = e;
    }
    
    printf("Case #%d: ",tttt);
    for(int i = 0; i < N; i++) {
      printf("%lf ",res[i]);
    }
    printf("\n");
  }
  
  return 0;
}
