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

int solve(int A, int B, int m){
  int ten[20];
  set <int> s;
  ten[0] = 1;
  REP(i, m) ten[i+1] = ten[i] * 10;
  int ans = 0;

  for(int i=A;i<=B;i++){
    s.clear();
    for(int j=1; j<m; j++){
      int tmp = (i / ten[j]) + (i % ten[j]) * ten[m-j];
      if(tmp <= B && i < tmp) s.insert(tmp);
    }
    ans += s.size();
  }

  return ans;
}

int main(){
  int T,A,B,m;
  cin >> T;

  REP(i, T){
    cin >> A >> B;
    int a = A;
    int m = 0;
    while(a){
      m++;
      a /= 10;
    }
    int ans = solve(A, B, m);
    printf("Case #%d: %d\n", i+1, ans);
  }

  return 0;
}
