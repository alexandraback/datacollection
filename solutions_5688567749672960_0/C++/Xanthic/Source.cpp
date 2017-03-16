#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<algorithm>
#include<vector>
#include<queue>
#include<list>
#include<string>
#include<set>
#include<map>
#include<iomanip>
#include<sstream>
#include<functional>
#include<climits>
#define eps 1e-9
const int mod = 281683;
using namespace std;

int t, n;
int dist[1000005];
int poww(int x) {
  int ret = 1;
  for (int i = 0; i < x; ++i) ret *= 10;
  return ret;
}
int rev(int x) {
  string s = to_string(x);
  int ret = 0;
  int n = s.size();
  for (int i = n - 1; i >= 0; --i) {
    ret += poww(i)*(s[i] - '0');
  }
  return ret;
}
void bfs() {
  memset(dist, 0, sizeof(dist));
  dist[1] = 1;
  queue<int> q;
  q.push(1);
  while (!q.empty()) {
    int cur = q.front();
    q.pop();
    if (cur > 1000000) continue;
    if (cur == n) break;
    if (dist[cur + 1] == 0) {
	dist[cur + 1] = dist[cur] + 1;
	q.push(cur + 1);
    }
    int x = rev(cur);
    if (dist[x] == 0) {
	dist[x] = dist[cur] + 1;
	q.push(x);
    }
  }
}
int main() {
  freopen("A-small-attempt0.in", "r", stdin);
  freopen("A-small-attempt0Result.txt", "w", stdout);
  scanf("%d", &t);
  for(int test= 1; test <=t; ++test) {
    scanf("%d", &n);
    bfs();
    printf("Case #%d: %d\n", test, dist[n]);
  }
  return 0;
}