#include <bits/stdc++.h>

using namespace std;
typedef vector<int> vi;
typedef long long ll;

int getInt() {
  int v;
  scanf("%d", &v);
  return v;
}

vi getVector(int n) {
  vi vec;
  for(int i=0;i<n;i++) {
    int v = getInt();
    vec.push_back(v);
  }
  return vec;
}

int f(vi v) {
  int m = 0;
  for(size_t j=0;j<v.size();j++) {
    m = max(m, v[j]);
  }
  int ans = m;
  for(int i=1;i<=m;i++) {
    int cnt = 0;
    for(size_t j=0;j<v.size();j++) {
      cnt += (v[j] - 1) / i; 
    }
    ans = min(ans, cnt + i);
  }

  return ans;
}

int solve() {
  int n = getInt();
  vi s = getVector(n);
  return f(s);
}


int main() {
  int T = getInt();
  for(int tt=1;tt<=T;tt++) {
    int ans = solve();
    printf("Case #%d: %d\n", tt, ans);
  }
}
