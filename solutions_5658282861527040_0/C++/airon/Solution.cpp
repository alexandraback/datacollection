#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <iomanip>
#include <string>
#include <map>
#include <queue>
#include <set>
#include <ctime>
#include <functional>

#define pb push_back
#define mk make_pair
#define sqr(N) ((N)*(N))
#define F first
#define S second
#define maxn 101010

using namespace std;                         

typedef long long ll;

int a, b, k, i, j;

int main(){
  #ifndef ONLINE_JUDGE
   freopen("input.txt", "r", stdin);
   freopen("output.txt", "w", stdout);
  #endif
  int t;
  cin >> t;
  for(int test = 1; test <= t; test++) {
    printf("Case #%d: ", test);
    cin >> a >> b >> k;
    int ans = 0;
    for(i = 0; i < a; i++)
      for(j = 0; j < b; j++) if((i & j) < k) ans++;
    cout << ans << endl;
  }
  return 0;
}         