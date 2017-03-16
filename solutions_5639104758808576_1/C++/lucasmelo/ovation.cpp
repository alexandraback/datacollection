#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

#define MAXN 2000
char s[MAXN];
int n;

int main() {
  int t; cin >> t;
  for(int cn=1; cn<=t; cn++) {
    cin >> n >> s;

    int ans;
    for(ans=0; ans<=n; ans++) {
      int x = ans;
      int i;
      for(i=0; i<=n; i++) {
        if (x < i) break;
        else {
          x += s[i]-'0';
        }
      }
      if (i == n+1) break;
    }

    printf("Case #%d: %d\n", cn, ans);
  }
  return 0;
}
