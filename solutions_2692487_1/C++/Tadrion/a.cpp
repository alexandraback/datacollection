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
#define MP make_pair
typedef long long int LL;
typedef pair<int,int> PII;
typedef vector<int> VI;
int T;
LL a[110];
LL A,N,m;
vector<LL> v;
int res = 1000;
int main() {  
  cin >> T;
  FOR(tt,1,T) {
    v.clear();
    res = 1000;
    //CLEAR(a);
    FOR(i,0,100) a[i] = -1;
    cin >> A >> N;
    FOR(i,1,N) {
      cin >> m;
      v.PB(m);
    }
    int iter = 0;
    sort(v.begin(),v.end());
    a[0] = A;
    while(iter < SZ(v) && v[iter] < a[0]) {a[0] += v[iter]; iter++;}

    FOR(i,1,100) {
      if(a[i-1] > 1000000000000000LL) break;
      a[i] = a[i-1] + (a[i-1]-1);
      while(iter < SZ(v) && v[iter] < a[i]) {a[i] += v[iter]; iter++;}
    }
    
    FOR(i,0,100) {
      if(a[i] > 0) {
	//printf("%lld %lld %d\n",a[i],*lower_bound(v.begin(),v.end(),a[i]),i);
	res = MIN(res,(v.end() - lower_bound(v.begin(),v.end(),a[i]))+i);
      }
    }
    printf("Case #%d: %d\n",tt,res);
  }

  
  return 0;
}
