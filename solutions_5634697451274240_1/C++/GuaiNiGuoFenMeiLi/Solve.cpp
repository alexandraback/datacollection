#include <bits/stdc++.h>

using namespace std;

const int MAX_STATE = 300;

int cost[MAX_STATE];

int id(int beg, int len) {
  return len * 2 + beg;
}

int init(string s) {
  int beg = (s[0] == '+' ? 1 : 0), len = 0;
  for (int i = 0; i < (int)s.size(); ++i) {
    if (i > 0 && s[i] == s[i - 1]) {
      continue;
    }
    ++len;
  }
  return id(beg, len);
}

int to(int beg, int len, int pre) {
  string s = "";
  for (int i = 0; i < len; ++i) {
    if (i < pre) {
      if ((pre - 1 - i) & 1) {
        s += (beg ? "+" : "-");
      } else {
        s += (beg ? "-" : "+");
      }
    } else {
      if (i & 1) {
        s += (beg ? "-" : "+");
      } else {
        s += (beg ? "+" : "-");
      }
    }
  }
  return init(s);
}

int main() {
  freopen("B-large.in", "r", stdin);
  freopen("B-large.out", "w", stdout);
  int T;
  scanf("%d", &T);
  for (int test = 1; test <= T; ++test) {
    string source;
    cin >> source;
    int st = init(source);
    fill(cost, cost + MAX_STATE, numeric_limits<int>::max());
    cost[st] = 0;
    string target = "+";
    int ed = init(target);
    priority_queue<pair<int, int> > Q;
    Q.push(make_pair(-cost[st], st));
    while (!Q.empty()) {
      int u = Q.top().second;
      int cur = -Q.top().first;
      Q.pop();
      if (cur != cost[u]) {
        continue;
      }
      for (int pre = 1; pre <= u / 2; ++pre) {
        int v = to(u % 2, u / 2, pre);
        // printf("%d,%d -> %d,%d\n", u % 2, u / 2, v % 2, v / 2);
        int nxt = cost[u] + 1;
        if (nxt < cost[v]) {
          cost[v] = nxt;
          Q.push(make_pair(-cost[v], v));
        }
      }
    }
    printf("Case #%d: %d\n", test, cost[ed]);
  }
  return 0;
}
