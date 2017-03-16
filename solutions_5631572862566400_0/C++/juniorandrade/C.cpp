#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
typedef pair<ll,ll> ii;
typedef vector<ll> vi;
typedef vector< ii > vii;

#define INF 0x3F3F3F3F
#define LINF 0x3F3F3F3F3F3F3F3FLL
#define pb push_back
#define mp make_pair
#define pq priority_queue
#define LSONE(s) ((s)&(-s)) //LASTBIT
#define DEG_to_RAD(X)   (X * PI / 180)
#define F first
#define S second
#define PI 2*acos(0)

#ifdef ONLINE_JUDGE
#define debug(args...)
#else
#define debug(args...) fprintf(stderr,args)
#endif

//////////////////////
int dx[] = {1,-1,0,0};
int dy[] = {0,0,-1,1};
//////////////////////

void arquivo() {
  freopen("","r",stdin);
  freopen("","w",stdout);
}

const int N = 12;

int n;
int f[N];
int pd[(1 << N)][N][2];
short memo[(1 << N)][N][2];
int fst;

int func(int mask, int lst, int ok) {
  //if(memo[mask][lst][ok]) return pd[mask][lst][ok];
  int ret = -INF;
  if(f[lst] == fst || ok) ret = 0;
  for(int i = 0; i < n; ++i) {
    if((mask >> i) & 1) continue;
    if(ok) {
      ret = max(ret, 1 + func(mask | (1 << i), i, f[i] == lst));
    }
    else {
      if(f[lst] == i) ret = max(ret, 1 + func(mask | (1 << i), i, f[i] == lst));
    }
  }
  //memo[mask][lst][ok] = 1;
  return pd[mask][lst][ok] = ret;
}

inline void main2() {
  scanf("%d", &n);
  for(int i = 0; i < n; ++i) scanf("%d", f + i), f[i]--;
  if(n <= 3) {
    printf(" %d\n", n);
    return;
  }
  int ans = 1;
  //memset(pd, -1, sizeof pd);
  for(int i = 0; i < n; ++i) {
    //memset(memo, 0, sizeof memo);
    fst = i;
    ans = max(ans, 2 + func((1 << i) | (1 << f[i]), f[i], f[i] == i));
  }
  printf(" %d\n", ans);
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) {
    printf("Case #%d:", tt);
    main2();
  }
  return 0;
}