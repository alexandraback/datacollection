#include <vector>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstring>
#include <iterator>
#define FOR(i,a,n) for(int i = (a); i < (int)(n); ++i)
#define foreach(itr,c) for(decltype((c).begin()) itr=(c).begin(); itr != (c).end(); itr++)
#define MP(a,b) make_pair(a,b)

using namespace std;

// 0 is untouched, -1 is dead, 1 is touched, 2 is luck guy, 3 is in stack.

int in[2000], mk[2000], lst[2000];

int n, ans;

int stk[2000], top;

void dfs(int x) {
  top = 0;
  while(mk[x] == 0) {
    lst[x] = top;
    stk[top++] = x;
    mk[x] = 3;
    x = in[x];
  }
  
  if(mk[x] == -1) {
    FOR(i, 0, top) mk[stk[i]] = -1;
    return;
  }
  
  if(mk[x] == 2 || mk[x] == 1) {
    FOR(i, 0, top) mk[stk[i]] = 1;
    
    while(mk[x] == 1) {
      if(lst[x] >= top) return;
      lst[x] = top++;
      x = in[x];  
    }
    
    if(lst[x] < top) lst[x] = top++;
    return;
  } 
   
  if(mk[x] == 3) {
    int i = 0;
    for(i = top - 1; i >= 0; --i) {
      if(stk[i] == x) break; 
    }
    
    if(i == top - 2) {
      FOR(i, 0, top - 1) {
        lst[stk[i]] = i;
        mk[stk[i]] = 1;
      }
      lst[stk[top - 1]] = 0;
      mk[stk[top - 2]] = mk[stk[top - 1]] = 2;    
      return;
    }
    
    if(ans < top - i) ans = top - i;
    
    FOR(i, 0, top) {
      mk[stk[i]] = -1;
    }
    
  }
}

void solve() {
  int tmp = 0;
  FOR(i, 0, n) {
    if(mk[i] == 2) {
      tmp += lst[i] + 1;
    }
  }
  if(ans < tmp) ans = tmp;
}

void print() {
  puts("--- print ---");
  FOR(i, 0, n) printf("%d ", mk[i]); puts("");
  FOR(i, 0, n) printf("%d ", lst[i]); puts("");
  puts("--- end ---");
}

int main() {
  getchar();
  freopen("C-large.in", "r", stdin);
  freopen("C-large.out", "w", stdout);
  //freopen("C-small-attempt1.in", "r", stdin);
  //freopen("C-small-attempt1.out", "w", stdout);
  int t, x;
  cin >> t;
  FOR(tt, 1, t + 1) {
    cin >> n;
    FOR(i, 0, n) {
      cin >> in[i];
      in[i]--;
    }
    memset(mk, 0, sizeof(mk));
    memset(lst, 0, sizeof(lst));
    ans = 0;
    FOR(i, 0, n) {
      if(mk[i] != 0) continue;
      dfs(i);
    }
    solve();
    //print();
    printf("Case #%d: %d\n", tt, ans);
  }
  return 0;
}
