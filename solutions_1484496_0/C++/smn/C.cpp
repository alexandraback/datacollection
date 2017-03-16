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
using namespace std;

typedef long long LL;
#define REP(i,e) for (int (i) = 0; (i) < (e); ++(i))
#define foreach(__my_iterator,__my_object) for (typeof((__my_object).begin()) __my_iterator = (__my_object).begin(); __my_iterator!= (__my_object).end(); __my_iterator++)

int H[20 * 100000 + 1];
int a[21];

void go(int x, int y){
  REP(i, 20){
    int ax = (x>>i) & 1;
    int ay = (y>>i) & 1;
    if(ax && ay){
      x ^= 1<<i;
      y ^= 1<<i;
    }
  }
  REP(i,20) if((x>>i) & 1) printf("%d ", a[i]);
  printf("\n");
  REP(i,20) if((y>>i) & 1) printf("%d ", a[i]);
  printf("\n");  
}


void solve(){
  bool ok = false;
  REP(i, 1<<20){
    int sum = 0;
    REP(j, 20) if((i >> j) & 1) sum += a[j];
    if(H[sum] > 0){
      ok = true;
      go(H[sum], i);
      break;
    }
    H[sum] = i;
  }

  if(!ok) printf("Impossible\n");
}
int main(){
  int T,N;
  cin >> T; 
  REP(i, T){
    cin >> N;

    REP(j, N) cin >> a[j];
    printf("Case #%d:\n", i+1);
    memset(H, 0, sizeof(H));
    solve();
  }

  return 0;
}

/*
echo "2
20 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20
20 120 266 858 1243 1657 1771 2328 2490 2665 2894 3117 4210 4454 4943 5690 6170 7048 7125 9512 9600" | ./a.out
 */
