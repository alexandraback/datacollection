#include <bits/stdc++.h>

#define fori(i,b,e) for (int i = (b); i < (e); i++)
#define mp make_pair
#define pb push_back
#define all(a) (a).begin(), (a).end()
#define elsif else if
#define sz(a) ((int)(a).size())
#define X first
#define Y second

using namespace std;

typedef long long int int64;
typedef pair<int, int> pii;
typedef vector<int> vi;

inline int getInt() { int res;  scanf("%d", &res);  return res; }
inline double getDbl() { double res;  scanf("%lf", &res);  return res; }

const int maxn = 1010;
char s[maxn];
char ans[maxn];

void clear() {
}

void read() {
}

void solve() {
  scanf("%s", s);
  int n = strlen(s);
  ans[n] = 0;
  vi st;
  fori(i,0,n) {
    char c = s[i];
    if (st.empty() || s[st[sz(st)-1]] <= c)
      st.pb(i);
  }
  int last = n-1, fst = 0, prev = n;
  while (!st.empty()) {
    int pos = st[sz(st) - 1];
    st.pop_back();
    for (int i = prev - 1; i > pos; i--) {
      ans[last--] = s[i];
    }
    ans[fst++] = s[pos];
    prev = pos;
  }
  assert(fst == last + 1);
  printf("%s\n", ans);
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
    solve();
  }
  return 0;
}
