#include <bits/stdc++.h>

// clang-format off
using namespace std;
typedef int i32;
#define int long long
#define all(a) (a).begin(), (a).end()
#define ms(a,v) memset(a, v, sizeof(a))
#define mp make_pair
#define pb push_back
#define prev franga_de_sunga
#define next tio_de_sueter
#define index bora_baea
#define left ahsiha19as
#define VAR(i, x) __typeof(x) i=(x)
#define R32 ({i32 x; scanf("%d", &x); x;})
#define RL ({long long x; scanf("%lld", &x); x;})
#define RC ({char x; scanf(" %c", &x); x;})
#define foreach(i, x) for(VAR(i, (x).begin()); i != (x).end(); ++(i))
#define RI RL
typedef pair<int, int> ii;
typedef long long ll;
// clang-format on

void solve(int tn) {
  string s, ans;
  cin >> s;

  deque<char> res;
  res.push_back(s[0]);
  for (int i = 1; i < s.size(); i++) {
    if (s[i] >= res.front())
      res.push_front(s[i]);
    else
      res.push_back(s[i]);
  }

  for (char c : res)
    ans += c;
  printf("Case #%lld: %s\n", tn, ans.c_str());
}

i32 main() {
  // YOU SHALL CLEAR DAMN VARIABLES BEFORE EACH TEST
  // WITH MEMSET
  int T = RI;
  for (int tn = 1; tn <= T; tn++)
    solve(tn);
}
