#include <iostream>
#include <fstream>
#include <algorithm>
#include <string>
#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cassert>
#include <cstring>
#include <cstddef>
#define _USE_MATH_DEFINES // for C++
#include <cmath>

using namespace std;

int dp[1000006];

long long reverse(int i){
  if(i % 10 == 0)
    return 1e14 + 14;
  long long j = 0;
  while(i){
    j *= 10;
    j += i % 10;
    i /= 10;
  }
  return j;
}

int main(){
  FILE *fin = freopen("A.in", "r", stdin);
  assert(fin != NULL);
  FILE *fout = freopen("A.ans", "w", stdout);

  ios :: sync_with_stdio(false);
  cin.tie(0);

  int T;
  cin >> T;

  for(int t = 1; t <= T; t++){
    long long N;
    cin >> N;

    long long ans = N;
    for(int i = 1; i <= N; i++){
      dp[i] = dp[i - 1] + 1;

      long long j = reverse(i);
      if(j < i)
        dp[i] = min(dp[i], dp[j] + 1);
      /* cout << i << " " << dp[i] << endl; */
    }
    cout << "Case #" << t << ": " << dp[N] << endl;
  }
}

