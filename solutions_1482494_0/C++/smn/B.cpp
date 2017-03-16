#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <map>
#include <set>
#include <iostream>
#include <memory>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <sstream>
#include <stack>
#include <queue>
#include <cstring>
#include <assert.h>
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)


int a[1010];
int b[1010];
int mark[1010][2];

void solve(int N){
  memset(mark, false, sizeof(mark));
  int cur = 0;
  int done = 0;
  int ans = 0;

  while(1){
  RESET:
    if(done==N) break;
    REP(i, N) if(!mark[i][1] && cur >= b[i]){
      if(mark[i][0]) cur+=1;
      else cur += 2;
      done++;
      ans++;
      mark[i][1] = true;
      goto RESET;
    }
    int tmp = -1;
    int cand = -1;
    REP(i, N) if(!mark[i][0] && !mark[i][1] && cur >= a[i]){
      if(tmp < b[i]){
	tmp = b[i];
	cand = i;
      }
    }
    if(cand==-1) break;
    mark[cand][0] = true;
    ans++;
    cur++;
    goto RESET;
  }

  if(done==N) printf("%d\n", ans);
  else printf("Too Bad\n");
}


int main(){
  int T,N;
  cin >> T; 
  REP(i, T){
    cin >> N;
    REP(j, N) cin >> a[j] >> b[j];
    printf("Case #%d: ",i+1);
    solve(N);
  }

  return 0;
}
/*
4
2
0 1
0 2
3
2 2
0 0
4 4
1
1 1
5
0 5
0 1
1 1
4 7
5 6
*/
