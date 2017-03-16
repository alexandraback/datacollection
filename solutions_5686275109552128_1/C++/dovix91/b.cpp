// For each i,j find what's the cost of splitting j into pieces of size at most i.
// Then do dot product of the frequency vector with each row i and take the smallest (dot+i).

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <list>
#include <set>
#include <algorithm>
#include <climits>
#include <cmath>
#include <string>
using namespace std;

#define SIZE 1002
// #define SIZE 11

int dp[SIZE][SIZE];
int vec[SIZE];

void solve(int test) {
  int n;
  int x;
  
  cin >> n;
  
  int best = 0;
  
  for (int i = 0; i < SIZE; i++) {
    vec[i] = 0;
  }
  for (int i = 0; i < n; i++) {
    cin >> x;
    vec[x]++;
    if (x > best) best = x;
  }
  // cout << best << endl;
  
  for (int i = 1; i < best; i++) {
    int dot = 0;
    for (int j = 0; j < SIZE; j++)
      dot += vec[j] * dp[i][j];
    // cout << i << dot << endl;
    if (dot + i < best)
      best = dot + i;
  }

  cout << "Case #" << (test+1) << ": " << best << endl;
}


int main() {
  int t, T;
  
  // Perform DP
  for (int i = 0; i < SIZE; i++) dp[0][i] = 0;
  for (int i = 1; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) {
      if (j <= i) dp[i][j] = 0;
      else {
        dp[i][j] = INT_MAX;
        for (int k = 1; k <= j/2; k++) {
          if (dp[i][j] > dp[i][k] + dp[i][j-k] + 1)
            dp[i][j] = dp[i][k] + dp[i][j-k] + 1;
        }
      }
    }
  }

  /*
  for (int i = 0; i < SIZE; i++) {
    for (int j = 0; j < SIZE; j++) cout << dp[i][j] << " ";
    cout << endl;
  }
  */
 
  cin >> T;
  for(t=0; t<T; t++) solve(t);
  return 0;
}

