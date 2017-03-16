#include <iostream>
#include <algorithm>
#include <cstdio>
#include <memory.h>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <vector>
#define ABS(x) ((x) >= 0 ? (x) : (-(x)))
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
using namespace std;
const int inf = 1 << 29;
const int maxn = 10002;
const int maxm = 100002;
const int mod = 142857;

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

int n, sig;
long long m;
char str[maxn];

void read() {
  cin >> n >> m >> str;
  return;
}

char ttt[4][4] = {{'1', 'i', 'j', 'k'},
                  {'i', '1', 'k', 'j'},
                  {'j', 'k', '1', 'i'},
                  {'k', 'j', 'i', '1'}};

int tran(char x) {
  if (x == '1') return 0;
  if (x == 'i') return 1;
  if (x == 'j') return 2;
  return 3;
}

char calc(char x, char y) {
  int xx = tran(x);
  int yy = tran(y);
  if (xx == yy || (xx == 1 && yy == 3) || (xx == 2 && yy == 1) || (xx == 3 && yy == 2)) {
    sig ^= 1;
  }

  return ttt[xx][yy];
}

char calc_sum() {
  int t = (int)(m % 4);
  char ans = '1';
  sig = 0;
  while(t--) {
    for (int i=0;i<n;i++) {
      ans = calc(ans, str[i]);
    }
  }
  return ans;
}

void solve() {
  char sum = calc_sum();
  if (!(sig == 1 && sum == '1')) {
    puts("NO");
    return;
  }

  int t = 8;
  if (m < 8LL) t = (int)m;
  sig = 0;
  sum = '1';
  bool f1 = false, f2 = false;
  while(t--) {
    for (int i=0;i<n;i++) {
      sum = calc(sum, str[i]);
      if (sig == 0 && sum == 'i') {
        f1 = true;
      }
      if (sig == 0 && sum == 'k' && f1) {
        f2 = true;
        break;
      }
    }
    if (f1 && f2) break;
  }
  if (f1 && f2) puts("YES");
  else puts("NO");
  return;
}

int main() {
  //freopen("data.in", "r", stdin);
  //freopen("C-small-attempt1.in", "r", stdin);
  //freopen("C-large.in", "r", stdin);
  //freopen("data.out", "w", stdout);
  int cas;
  scanf("%d", &cas);
  for (int i=1;i<=cas;i++) {
    printf("Case #%d: ",i);
    read();
    solve();
  }
  return 0;
}

