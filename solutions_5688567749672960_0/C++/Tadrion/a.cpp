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

int m[1000100];

int rev(int k) {
    int s = 0;
    while(k > 0) {
        s = 10*s + (k%10);
        k/=10;
    }
    return s;
}


int main() {
  FOR(i,1,1000000) m[i] = i;

  FOR(i,1,1000000) {
    m[i] = MIN(m[i-1]+1,m[i]);
    m[rev(i)] = MIN(m[rev(i)],m[i]+1);
    //printf("%d %d\n",i,m[i]);
  }


  scanf("%d",&T);
  FOR(TTT,1,T) {
    int n;
    scanf("%d",&n);
    printf("Case #%d: %d\n",TTT,m[n]);
  }
  return 0;
}
