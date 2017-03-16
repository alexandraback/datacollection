/* Writen by Filip Hlasek 2012 */
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define FORD(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,b) for(int i=0;i<b;i++)

using namespace std;

#define MAXN 222
int s[MAXN],X,N;

bool possible(double d){
  double sum = 0;
  REP(i,N) if(s[i] < d) sum += d - s[i];
  return sum < X;
}

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    printf("Case #%d:",t+1);
    scanf("%d",&N);
    REP(i,N) scanf("%d",s+i);
    X = 0;
    REP(i,N) X += s[i];
    REP(n,N){
      double left = 0, right = 1, middle;
      REP(t,100){
        middle = (left + right)/2;
        if(possible(s[n] + X * middle)) left = middle; 
        else right = middle;
      }
      printf(" %.8lf",100*left);
    }
    printf("\n");
  }
  return 0;
}
