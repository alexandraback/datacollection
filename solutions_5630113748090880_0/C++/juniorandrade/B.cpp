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

const int N = 101;

ll arr[N][N];
ll cnt[N * N];
int n;

inline void main2() {
  memset(cnt, 0, sizeof cnt);
  scanf("%d", &n);
  
  for(int i = 0; i < 2 * n - 1; ++i) {
    for(int j = 0; j < n; ++j) {
      scanf("%lld", &arr[i][j]);
      cnt[arr[i][j]]++;
    }
  }
  for(int i = 0; i < N * N; ++i) {
    if(cnt[i] % 2 == 1) printf(" %d", i);
  }
  printf("\n");
}

int main() {
  int t; scanf("%d", &t);
  for(int tt = 1; tt <= t; ++tt) {
    printf("Case #%d:", tt);
    main2();
  }
  return 0;
}