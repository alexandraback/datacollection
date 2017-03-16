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
  for(int i=0;i<=n;) {
    char c;
    scanf("%c", &c);
    if(c < '0' || c > '9') continue;
    vec.push_back(c - '0');
    i++;
  }
  return vec;
}

int solve() {
  int n = getInt();
  vi s = getVector(n);
  vi ss(s.size());
  ss[0] = s[0];
  for(int i=1;i<=n;i++)
    ss[i] = ss[i-1] + s[i];
  int ans = 0;
  
  for(int i=0;i<n;i++) {
    int d = i + 1 - ss[i];
    if(d > 0) {
      ans = max(ans, d);
    }
  }
  return ans;
}


int main() {
  int T = getInt();
  for(int tt=1;tt<=T;tt++) {
    int ans = solve();
    printf("Case #%d: %d\n", tt, ans);
  }
}
