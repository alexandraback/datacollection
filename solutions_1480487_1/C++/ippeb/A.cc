#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <complex>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <cassert>
#include <complex>
#define MP              make_pair
#define CMNT            1
#define INF             0x3fffffff
#define MM(s,a)         memset((s),(a),sizeof((s)))
using namespace std;

typedef unsigned           uint;
typedef long long int     llint;
typedef pair<int,int>       PII;
typedef pair<double,double> PDD;

int T,N;
double S[201], X;
const double eps=0.0000000001;

bool ok(double x, int i){
  double pts=X*x+S[i];
  double tmp=0.0;
  for (int j=0; j<N; ++j){
    if (i==j) continue;
    if (S[j]>pts) continue;
    tmp+=(pts-S[j])/X;
  }
  //  printf("x %lf tmp %lf\n",x,tmp);
  if (tmp+x>1) return true;
  return false;
}

int main(){
  scanf("%d",&T);
  for (int t=1; t<=T; ++t){
    scanf("%d",&N);
    X=0;
    for (int i=0; i<N; ++i) {scanf("%lf",&S[i]); X+=S[i];}
    
    printf("Case #%d: ",t);

    for (int i=0; i<N; ++i){
      double up=1.0000,low=0.00000,mid;
      while (up-low>eps){
	mid = (up+low)/2;
	if (ok(mid,i)) up=mid;
	else low=mid+eps;
      }
      printf("%.6lf ",mid*100.0);
    }
    printf("\n");
  }
}
