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

const int N = 6;

int mat[N][N];
map<int, ii> rev;
ll n, b;
ll pd[N];

inline void printMatrix() {
  for(int i = 0; i < n; ++i) {
    for(int j = 0; j < n; ++j) {
      printf("%d", mat[i][j]);
    }
    printf("\n");
  }
}

ll func(int x){
  if(x == n - 1) return 1;
  if(pd[x] != -1) return pd[x];
  ll ret = 0;
  for(int i = 0; i < n; ++i) if(mat[x][i]) ret += func(i);
  return pd[x] = ret;
}

inline void main2() {
  scanf("%lld %lld", &n, &b);
  rev.clear();
  int cnt = 0;
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) rev[cnt++] = ii(i, j);
  for(int i = 0; i < (1 << cnt); ++i) {
    memset(mat, 0, sizeof mat);
    for(int j = 0; j < cnt; ++j) if((i >> j) & 1) mat[rev[j].F][rev[j].S] = 1;
    memset(pd, -1, sizeof pd);
    ll qtdWays = func(0);
    if(qtdWays == b) {
      puts("POSSIBLE");
      printMatrix();
      return;
    }
  }
  puts("IMPOSSIBLE");
}

int main() {
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    main2();
  }
  return 0;
}