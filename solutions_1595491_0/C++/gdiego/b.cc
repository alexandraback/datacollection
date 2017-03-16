#include <string>
#include <iostream>
#include <algorithm>
using namespace std;
int n, s, p;
int scores[101];
int memo[101][101];
int nsm(int score) {
  return (int)(score/3) + (score%3?1:0);
}
int sm(int score) {
  if (!score) return 0;
  switch (score % 3) {
    case 0: return (int)(score / 3) + 1;
    case 1: return (int)(score / 3) + 1;
    default: return (int)(score / 3) + 2;
  }
}
int din(int from, int sur) {
  if (sur < 0)
    return -1000000;
  if (from == n)
    return sur ? (memo[from][sur] = -1000000) : (memo[from][sur] = 0);
  if (memo[from][sur] > -1)
    return memo[from][sur];

  return memo[from][sur] = max(din(from + 1, sur) + (nsm(scores[from]) >= p ? 1 : 0), din(from + 1, sur - 1) + (sm(scores[from]) >= p ? 1 : 0));  
}
int doit() {
  cin >> n >> s >> p;
  for (int x = 0; x < 101; x++)
    for (int y = 0; y < 101; y++) memo[x][y] = -1;
  for (int x = 0; x < n; x++) cin >> scores[x];
  return din(0, s);
}
int main() {
  int cases;
  cin >> cases;
  for (int x = 0; x < cases; x++) {
    cout << "Case #" << (x + 1) << ": ";
    cout << doit();
    cout << endl;
  }
  return 0;
}

