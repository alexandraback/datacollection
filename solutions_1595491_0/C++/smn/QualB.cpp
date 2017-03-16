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

int main(){
  int m,N,S,p;
  vector <int> v;
  cin >> m;
  int sum[200];

  REP(i, m){
    int ans = 0;

    cin >> N >> S >> p;
    int val = max(p, p * 3 - 2);
    int val2 = max(p, p * 3 - 4);
    REP(j, N) cin >> sum[j];


    REP(j, N){
      if(sum[j] >= val) ans++;
      else if(S > 0 && sum[j] >= val2){
	ans++;
	S--;
      }
    }
    printf("Case #%d: %d\n", i+1, ans);
  }

  return 0;
}
