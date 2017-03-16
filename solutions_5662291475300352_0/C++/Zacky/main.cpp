#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <cmath>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
using namespace std;
const int inf = 1 << 29;
const int maxn = 1000002;
const int maxm = 102;
const int mod = 100007;

void in(int &x) {
  char ch=getchar();
  bool flag=false;
  while ((ch<'0'||ch>'9')&&ch!='-') ch=getchar();
  if (ch=='-') {
    flag=true;
    ch=getchar();
  }
  x=0;
  while (ch>='0'&&ch<='9') {
    x=x*10+ch-'0';
    ch=getchar();
  }
  if (flag) x=-x;
}

/*
struct Node {
  int v,w;
  int next;
}edge[maxn << 1];
int head[maxn << 1];
bool vis[maxn];
int m,n,idx;

void init() {
  memset(head,-1,sizeof(head));
  memset(vis, false, sizeof(vis));
  idx = 0;
  return;
}

void addedge(int u, int v, int w) {
  edge[idx].v = v;
  edge[idx].w = w;
  edge[idx].next = head[u];
  head[u] = idx++;

  edge[idx].v = u;
  edge[idx].w = w;
  edge[idx].next = head[v];
  head[v] = idx++;
  return;
}

int find(int x) {
  return fa[x] == x ? x : (fa[x] = find(fa[x]));
}

bool flag[maxn];
int phi[maxn];
vector<int> prime;

void get_prime_phi() {
  memset(flag, false, false);
  prime.clear();

  phi[1] = 1;
  for (int i=2;i<maxn;i++) {
    if (!flag[i]) {
      printf("%d ",i);
      prime.push_back(i);
      phi[i] = i-1;
    }
    for (int j=0;j<prime.size() && i*prime[j]<maxn; j++) {
      flag[i * prime[j]] = true;
      if (i % prime[j]) {
        phi[i * prime[j]] = phi[i] * (prime[j] - 1);
      } else {
        phi[i * prime[j]] = phi[i] * prime[j];
        break;
      }
    }
  }
  return;
}

long long extend_gcd(long long a,long long b,long long &x,long long &y) {
  if(a == 0 && b == 0) return -1;
  if(b == 0){x = 1; y = 0; return a;}
  long long d = extend_gcd(b, a % b, y, x);
  y -= a / b * x;
  return d;
}

long long mod_reverse(long long a, long long n) {
  long long x,y;
  long long d = extend_gcd(a, n, x, y);
  if(d == 1) return (x % n + n) % n;
  else return -1;
}

int c[maxn << 1];
int lowbit(int x) {
  return x & (-x);
}

void update(int x, int num) {
  while(x < maxn) {
    c[x] += num;
    x += lowbit(x);
  }
  return;
}

int getSum(int x) {
  int cnt = 0;
  while(x > 0) {
    cnt += c[x];
    x -= lowbit(x);
  }
  return cnt;
}

long long multi(long long m, long long n, long long k) {
  long long res = 0;
  while(n) {
    if (n & 1) {
      res += m;
      res %= k;
    }
    m = (m + m) % k;
    n >>= 1;
  }
  return res;
}

// m^n % k
long long quickpow(long long m, long long n, long long k) {
  long long res = 1LL;
  while (n) {
    if (n & 1) {
      res = multi(res, m, k);
    }
    m = multi(m, m, k);
    n >>= 1;
  }
  return res;
}
*/

int dp[maxn];

int flip(int x) {
  int ans = 0;
  while(x) {
    ans *= 10;
    ans += x % 10;
    x /= 10;
  }
  return ans;
}

vector< pair<int, int> > V;
int m,n,d,tmp;

void read() {
  scanf("%d", &n);
  V.clear();
  for (int i=0;i<n;i++) {
    scanf("%d%d%d", &d, &tmp, &m);
    V.push_back(make_pair(d, m));
    if (tmp != 1) {
      V.push_back(make_pair(d, m+1));
    }
  }
  return;
}

void solve() {
  double r = 1.0*360;
  double x1 = (r-V[0].first)/r*V[0].second;
  double x2 = (r-V[1].first)/r*V[1].second;
  double x3 = (r*2-V[0].first)/r*V[0].second;
  double x4 = (r*2-V[1].first)/r*V[1].second;

  int ans = 1;
  if ((x1 < x2 && x3 > x2) || (x2 < x1 && x4 > x1)){
    ans = 0;
  }
  printf ("%d\n", ans);
  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("C-small-1-attempt0.in", "r", stdin);
  //freopen("C-large.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  //init();
  int cas;
  scanf("%d", &cas);
  for (int i=1;i<=cas;i++) {
    printf("Case #%d: ",i);
    read();
    solve();
  }
  return 0;
}

