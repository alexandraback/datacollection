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

const int N = 51;

int mat[N][N];
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

ll p[60];
vii potencia;

bool cmp(ii a, ii b) {
  return max(a.F, a.S) > max(b.F, b.S);
}

inline void main2() {
  scanf("%lld %lld", &n, &b);
  potencia.clear();
  for(int i = 0; i < n; ++i) for(int j = i + 1; j < n; ++j) {
    mat[i][j] = 1;
    potencia.pb(mp(i, j));
  }
  memset(pd, -1, sizeof pd);
  if(func(0) < b) {
    puts("IMPOSSIBLE");
    return;
  }
  sort(potencia.begin(), potencia.end(), cmp);
  for(int i = n - 1; i >= 0; --i) {
    for(int j = n - 1; j > i; --j) {
      mat[i][j] = 0;
      memset(pd, -1, sizeof pd);
      if(func(0) < b) mat[i][j] = 1;
    }
  }
  // for(int i = 0; i < potencia.size(); ++i) {
  //   ll maxi = max(potencia[i].F, potencia[i].S);
  //   mat[potencia[i].F][potencia[i].S] = 0;
  //   memset(pd, -1, sizeof pd);
  //   if(func(0) < b) mat[potencia[i].F][potencia[i].S] = 1;
  // }
  puts("POSSIBLE");
  printMatrix();
  memset(pd, -1, sizeof pd);
  debug("%lld == %lld\n", b, func(0));
  if(b != func(0)) debug("!!!!!!!!!!!!!!!!ERROR!!!!!!!!!!!!!!!\n");
}

int main() {
  p[0] = 1;
  p[1] = 1;
  for(int i = 2; i < 60; ++i) p[i] = p[i - 1] * 2LL;
  int t; scanf("%d", &t);
  for(int i = 1; i <= t; ++i) {
    printf("Case #%d: ", i);
    main2();
  }
  return 0;
}