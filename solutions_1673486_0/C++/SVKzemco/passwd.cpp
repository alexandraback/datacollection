#include<iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <deque>
#include <stack>
#include <vector>
#include <cmath>
#include <list>
#include <sstream>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;
typedef long long LL;
typedef vector<int> VI;
typedef pair<LL,LL> PLL;
typedef vector<pair<int,int> > VPII;
typedef vector<LL> VLL;
typedef vector<vector<int> > VVI;
typedef vector<string> VS;
typedef long double LD;

#define PI 3.14159265358979323
#define EE 2.71828182845
#define EPS 10e-10
#define INF 10000000

inline LL MAX(LL a, LL b){ return a < b ? b : a;}
inline LL MIN(LL a, LL b){ return a < b ? a : b;}

#define FOR(i,n)      for(int i=0;i<(n);i++)
#define FORD(i,n)     for(int i=(n)-1;i>=0;i--)

#define MP make_pair
#define PB push_back

LD P[1000000];
int A,B;

int main(){
  int TT;
  scanf("%d ",&TT);
  FOR(tt,TT){
    scanf("%d %d ",&A,&B);
    FOR(i,A)scanf("%Lf ",&P[i]);    
    LD sum = 1;
    LD best = B+2;
    FOR(i,A+1){
      //nechame i-znakov
      int val = (A-i) + (B-i) + 1;
      LD cand = (sum * val) + (1.0-sum)*(val + B + 1);
      if (cand < best) best = cand;
      sum *= P[i];
    }
    printf("Case #%d: %.12Lf\n",(tt+1),best);
  }
}
