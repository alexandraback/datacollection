#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <map>
#include <string>
#include <string.h>
#include <set>
#include <stdio.h>
#include <assert.h>
#include <sstream>
using namespace std;

inline long long rev(long long x) {
  stringstream ss;
  ss << x;
  string str = ss.str();
  long long tens = 1, ans = 0;
  reverse(str.begin(), str.end());
  for (int i = str.size() - 1; i >= 0; --i, tens *= 10)
    ans += (str[i]-'0')*tens;
  return ans;
}

queue<int> Q;
int dist[1000001];

inline void enq(int x, int d) {
  if (x > 1000000) return;
  if (dist[x] != -1) return;
  dist[x] = d;
  Q.push(x);
}

int main(int argc, char* argv[]) {
  int nocases;
  cin >> nocases;
  getchar();
  memset(dist, -1, sizeof(dist));
  Q = queue<int>();
  enq(1, 0);
  while (Q.size()) {
    int x = Q.front();
    Q.pop();
    enq(x+1, dist[x]+1);
    enq(rev(x), dist[x]+1);
  }
  for (int rr = 1; rr <= nocases; ++rr) {
    int n;
    cin >> n;
    printf("Case #%d: %d\n", rr, dist[n]+1);
  }
  return 0;
}
