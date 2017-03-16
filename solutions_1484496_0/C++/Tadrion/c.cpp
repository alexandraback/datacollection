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

int T;
int N;

int a[30];

vector<int> sums[2500000];

int main() {
  scanf("%d",&T);
  for(int tttt = 1; tttt <= T; tttt++) {
    for(int i = 0; i < 2500000; i++)
      sums[i].clear();
    scanf("%d",&N);
    for(int i = 0; i < N; i++) {
      scanf("%d",&a[i]);
    }
    for(int j = 1; j < (1<<N); j++) {
      int summ=0;
      for(int k = 0; k < N; k++) {
	if(j&(1<<k)) summ+=a[k];
      }
      sums[summ].PB(j);
    }
    int ok=0;
    for(int i = 1; i < 2500000; i++) {
      if(SZ(sums[i]) >= 2) {
	ok=1;
	printf("Case #%d:\n",tttt);
	for(int k = 0; k < N; k++) {
	  if((1<<k)&sums[i][0]) printf("%d ",a[k]);
	}
	printf("\n");
	for(int k = 0; k < N; k++) {
	  if((1<<k)&sums[i][1]) printf("%d ",a[k]);
	}
	printf("\n");
	break;
      }
    }
    if(ok == 0) printf("Case #%d:\n Impossible\n",tttt);
  }
  
  return 0;
}
