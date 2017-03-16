#include <bits/stdc++.h>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define add insert
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())

using namespace std;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 101;
char s[maxn];

void clear() {
}

void read() {
}

int solve() {
  scanf("%s", s);
  int n = strlen(s);
  fori(i,0,n)
    s[i] = s[i] == '-' ? 0 : 1;
  int cnt = 0;
  while (true) {
    if (s[0] == 0) {
      int j = 0;
      cnt++;
      while (!s[j])
        s[j++] = 1;
    } else {
      int i = n-1;
      while (i >= 0 && s[i])
        i--;
      if (i == -1)
        return cnt;
      cnt++;
      reverse(s, s+(i+1));
    }
  }
}

int main() {
  freopen("in.txt", "rt", stdin);
  freopen("out.txt", "wt", stdout);
  srand(time(0));
  int N = getInt();
  fori(T,1,N+1) {
    clear();
    read();
    printf("Case #%d: ", T);
    printf("%d\n", solve());
  }
  return 0;
}
