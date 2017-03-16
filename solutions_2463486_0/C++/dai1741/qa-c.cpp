#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stdio.h>
#include <queue>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define rep(i,n) for (int i=0; i < (n); i++)

// a^2 is palindrome only if computation of a*a can be performed without carry
// both a and a^2 is palindrome only if sum of square of i-th digit of a is less than 10

// A002778 - OEIS
int theFairSqrts[] = {1, 2, 3, 11, 22, 101, 111, 121, 202, 212, 1001, 1111, 2002, 10001, 10101, 10201, 11011, 11111, 11211, 20002, 20102, 100001, 101101, 110011, 111111, 200002, 1000001, 1001001};

int solve() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  rep(i, sizeof(theFairSqrts)/sizeof(int)) {
    int v = theFairSqrts[i] * theFairSqrts[i];
    if (a <= v && v <= b) ans++;
  }

  return ans;
}

int main() {
  int t;
  cin >> t;
  rep(i, t) cout << "Case #" << i+1 << ": " << solve() << endl;
  return 0;
}