#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll n;
set<int> st;

int main() {
  freopen("A-large.in", "r", stdin);
  freopen("A.out", "w", stdout);

  int C = 0, T;
  scanf("%d", &T);
  while (++C <= T) {
    st.clear();
    scanf("%I64d", &n);
    ll nn = n, cnt = 0;
    while (true) {
      for (ll t = nn; t; t /= 10) { st.insert(t % 10); }
      if (cnt > 100 || st.size() == 10) { break; }
      nn += n; cnt++;
    }
    printf("Case #%d: ", C);
    if (cnt > 100) { puts("INSOMNIA"); }
    else { printf("%I64d\n", nn); }
  }
}
