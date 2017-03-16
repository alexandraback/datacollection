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

#define MAXN 1000

int N,s[MAXN];
map<int,int> m;

void print(int mask){
  bool printed = false;
  REP(i,N) if(mask & (1<<i)){
    if(printed) printf(" ");
    printf("%d",s[i]);
    printed = true;
  }
  printf("\n");
}

void solve(){
  REP(mask,1<<N){
    if(!mask) continue;
    int sum = 0;
    REP(i,N) if(mask & (1<<i)) sum += s[i];
    if(m.count(sum)){
      print(mask);
      print(m[sum]);
      return;
    }
    m[sum] = mask;
  }
  printf("Impossible\n");
}

int main(int argc, char *argv[]){
  int T; 
  scanf("%d",&T);
  REP(t,T){
    printf("Case #%d:\n",t+1);
    scanf("%d",&N);
    REP(i,N) scanf("%d",s+i);
    m.clear();
    solve();
  }
  return 0;
}
